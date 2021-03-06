#include <avr/io.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/sfr_defs.h>
#include <math.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include "USART.h"





void USART_Init(){

	UBRRH = (BRC >> 8);
	UBRRL = BRC;

	UCSRB = (1<<RXEN) | (1<<TXEN);
	UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
}



void UART_TxChar(char ch){

	while (! (UCSRA & (1<<UDRE)));  /* Wait for empty transmit buffer */
	UDR = ch ;
}

void UART_SendString(char *str){

	unsigned char j=0;

	while (str[j]!=0)		/* Send string till null */
	{
		UART_TxChar(str[j]);
		j++;
	}
}

unsigned char UART_RxChar(){
	while ((UCSRA & (1 << RXC)) == 0);/* Wait till data is received */
	return(UDR);		/* Return the byte */
}

void UART_GetString(){


	uint8_t i = 0;
    char j = UART_RxChar();
    char buffor[100];

    buffor[i] = 0;

	while(j != 64){

		buffor[i] = j;

		j = UART_RxChar();
		i++;
	}
	buffor[i] = '@';

	strcat(buffor,"\r\n");

	buff = buffor;

}





