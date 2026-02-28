/*
 * USART_Program.c
 *
 *  Created on: Nov 2, 2024
 *      Author: DELL
 */
#include "../../../LIB/StdType.h"
#include"../../../LIB/BitMath.h"
#include"../../../LIB/Definition.h"
#include "../Header/USART_Interface.h"

const u8 DataSize = CharacterSize8_bit;
//baud rate 9600 from table or make a function
#define F_CPU 8000000UL   // must match AVR fuse setting

const u16 BaudRate = 51;
#define TimeOut    5000UL

void USART_Init(void)
{
    // ── Baud Rate ────────────────────────────────────────────────────────────
    // UBRRH shares address 0x40 with UCSRC.
    // Writing with URSEL=0 (bit 7 cleared) selects UBRRH.
    USART_UBRRH = (u8)(BaudRate >> 8);   // URSEL=0 implicitly (upper bits of 51 are 0)
    USART_UBRRL = (u8)(BaudRate);

    // ── Speed mode ───────────────────────────────────────────────────────────
    ClrBit(USART_UCSRA, UCSRA_U2X);     // Normal speed (not double)

    // ── Disable all interrupts ────────────────────────────────────────────────
    ClrBit(USART_UCSRB, UCSRB_RXCIE);
    ClrBit(USART_UCSRB, UCSRB_TXCIE);
    ClrBit(USART_UCSRB, UCSRB_UDRIE);

    // ── UCSRC configuration ───────────────────────────────────────────────────
    // FIX 1: Build the entire UCSRC value in a temp variable FIRST,
    //        then write it once with URSEL=1. Writing directly to
    //        USART_UCSRC before the final assignment was overwriting
    //        every bit set there, leaving only URSEL set.
    u8 UCSRCTemp = 0;
    SetBit(UCSRCTemp, UCSRC_URSEL);    // URSEL=1 → write to UCSRC (not UBRRH)

    ClrBit(UCSRCTemp, UCSRC_UMSEL);   // Asynchronous mode
    ClrBit(UCSRCTemp, UCSRC_UPM0);    // No parity
    ClrBit(UCSRCTemp, UCSRC_UPM1);
    ClrBit(UCSRCTemp, UCSRC_USBS);    // 1 stop bit
    SetBit(UCSRCTemp, UCSRC_UCSZ0);   // 8-bit character size (UCSZ = 0b011)
    SetBit(UCSRCTemp, UCSRC_UCSZ1);
    ClrBit(UCSRCTemp, UCSRC_UCPOL);   // Clock polarity — don't care in async mode

    ClrBit(USART_UCSRB, UCSRB_UCSZ2); // 9-bit mode disabled (UCSZ2 lives in UCSRB)

    USART_UCSRC = UCSRCTemp;           // Single atomic write with URSEL=1

    // ── Enable TX and RX ─────────────────────────────────────────────────────
    SetBit(USART_UCSRB, UCSRB_TXEN);
    SetBit(USART_UCSRB, UCSRB_RXEN);
}


void USART_SendData(u16 Data)
{
    // Wait for UDR Empty flag (UDRE) before writing — with timeout guard
    u32 Counter = 0;
    while (GetBit(USART_UCSRA, UCSRA_UDRE) == 0 && Counter < TimeOut)
    {
        Counter++;
    }

    if (DataSize != CharacterSize9_bit)
    {
        // 5–8 bit mode: just write the low byte
        USART_UDR = (u8)Data;
    }
    else
    {
        // FIX 2: In 9-bit mode the ATmega datasheet requires TXB8 to be
        //        written BEFORE UDR, otherwise the 9th bit is lost because
        //        the transmission begins the moment UDR is written.
        u8 BitState = GetBit(Data, 8);
        if (BitState == 1)
            SetBit(USART_UCSRB, UCSRB_TXB8);
        else
            ClrBit(USART_UCSRB, UCSRB_TXB8);

        USART_UDR = (u8)Data;   // Write UDR last — triggers transmission
    }
}
void USART_RecevieData (u16 *Data)
{
    if (Data == NULL) return;
	u32 Counter=0;
		while(GetBit(USART_UCSRA,UCSRA_RXC)==0 && Counter < TimeOut)
		{
			Counter++;
		}
		if(DataSize!=CharacterSize9_bit)
		{
			if(Data!=NULL)
			{
				*Data=USART_UDR;
			}
		}
		else
		    {
		        // FIX 4: Read RXB8 (9th bit) from UCSRB BEFORE reading UDR.
		        //        Reading UDR clears the receive buffer and RXB8 along with it.
		        u16 Bit9 = GetBit(USART_UCSRB, UCSRB_RXB8);
		        *Data = ((Bit9 << 8) | USART_UDR);
		    }
}

void USART_SendString(char *str)
{
    while(*str)
    {
        USART_SendData(*str);
        str++;
    }
}

void USART_SendNumber(u16 num)
{
    char buffer[6];
    u8 i = 0;

    if(num == 0)
    {
        USART_SendData('0');
        return;
    }

    while(num > 0)
    {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    }

    while(i > 0)
    {
        USART_SendData(buffer[--i]);
    }
}
