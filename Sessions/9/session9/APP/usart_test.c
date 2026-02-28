#include "../MCAL/USART/Header/USART_Interface.h"
#include <util/delay.h>

int main(void)
{

    USART_Init();

    while(1)
    {
    	USART_SendString("IEEE");


        USART_SendData('\r');
        USART_SendData('\n');

        _delay_ms(1000);
    }
}
