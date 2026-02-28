/*
 * USART_Private.h
 *
 *  Created on: Nov 2, 2024
 *      Author: DELL
 */

#ifndef MCAL_USART_HEADER_USART_PRIVATE_H_
#define MCAL_USART_HEADER_USART_PRIVATE_H_

typedef enum{

	UCSRA_MPCM, // Multi-processor Communication Mode
	UCSRA_U2X,  // Double the USART Transmission Speed
	UCSRA_PE,	// Parity Error
	UCSRA_DOR,  // Data OverRun
	UCSRA_FE,	// Frame Error
	UCSRA_UDRE,	// USART Data Register Empty
	UCSRA_TXC, 	// Transmit Complete
	UCSRA_RXC,  //

	UCSRB_TXB8 = 0, // Transmit Data Bit 8
	UCSRB_RXB8,     // Receive Data Bit 8
	UCSRB_UCSZ2,  	//Character Size
	UCSRB_TXEN,		//Transmit Enable
	UCSRB_RXEN, 	//Receiver Enable
	UCSRB_UDRIE,	//Data Register Empty Interrupt Enable
	UCSRB_TXCIE,	//Complete Interrupt Enable
	UCSRB_RXCIE,

	UCSRC_UCPOL = 0,// Clock Polarity
	UCSRC_UCSZ0,    //Character Size
	UCSRC_UCSZ1,	//
	UCSRC_USBS,		// Stop Bit Select
	UCSRC_UPM0,		// Parity Mode
	UCSRC_UPM1,		//
	UCSRC_UMSEL, 	//Mode Select Asynchronous and Synchronous mode of operation
	UCSRC_URSEL, 	// Register Select  accessing the UCSRC or the UBRRH Register.
}USART_BitName;

typedef enum{
	Asynchronous,
	synchronous,
}USART_ModeSelect;

typedef enum{
	Disabled,
	Reserved,
	EnabledEvenParity,
	EnabledOddParity,
}USART_ParityMode;

typedef enum{
	StopSelect1_bit,
	StopSelect2_bit,
}USART_StopBitSelect;

typedef enum{
	CharacterSize5_bit,
	CharacterSize6_bit,
	CharacterSize7_bit,
	CharacterSize8_bit,
	CharacterSize9_bit = 7,
}USART_CharacterSize;

typedef enum{
	Rising_TX_Falling_RX,
	Falling_RX_Rising_TX,
}USART_ClockPolarity;

#endif /* MCAL_USART_HEADER_USART_PRIVATE_H_ */
