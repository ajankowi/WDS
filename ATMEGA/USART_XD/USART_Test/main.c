#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/sfr_defs.h>
#include <math.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>

#ifndef _BV
#define _BV(bit)				(1<<(bit))
#endif
#ifndef sbi
#define sbi(reg,bit)		reg |= (_BV(bit))
#endif

#ifndef cbi
#define cbi(reg,bit)		reg &= ~(_BV(bit))
#endif

/*-  Defination of Vectors----------------------------------------*/

#define TIMER0_COMP_VECTOR		__vector_10
#define TIMER1_COMPA_VECTOR  	__vector_7
#define TIMER1_COMPB_VECTOR 	__vector_8
#define TIMER2_COMP_VECTOR      __vector_4
#define TIMER2_OVF			    __vector_5

/*-  Definition of ISR -------------------------------------------*/

#define Timer_ISR(N)            \
void N (void)__attribute((signal,used)); \
void N (void)

#define 	bit_is_set(sfr, bit)   (_SFR_BYTE(sfr) & _BV(bit))
#define 	bit_is_clear(sfr, bit)   (!(_SFR_BYTE(sfr) & _BV(bit)))

#define BUAD 9600
#define BRC ((F_CPU/16/BUAD)-1)

void UART_TxChar(char ch);
void UART_SendString(char *str);
unsigned char UART_RxChar();
void UART_GetString();

char *buff;


int main() {

//	char c;
//	char tab[20];
	uint16_t a = 0;


	UBRRH = (BRC >> 8);
	UBRRL = BRC;

	UCSRB = (1<<RXEN) | (1<<TXEN);
	UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);


	while(1){

		UART_SendString("Dziala!\n\r");
		//UART_GetString();
		_delay_ms(1000);
		//UART_SendString(buff);

		a++;
	}


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
    char buffor[20];

    buffor[i] = 0;

	while(j != 13){

		buffor[i] = j;

		j = UART_RxChar();
		i++;
	}
	buffor[i] = '\0';

	strcat(buffor,"\n\r");

	buff = buffor;

}
























	// Dziala!

//	UBRRH = (BRC >> 8);
//	UBRRL = BRC;
//
//	UCSRB = (1<<RXEN) | (1<<TXEN);
//	UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
//
//	while(1){
//
//		UDR = 'D';
//
//		_delay_ms(10);
//
//	}



//	cbi(DDRD, PD7);
//	sbi(DDRD, PD6);
//
//	sbi(PORTD, PD7);
//
//	while (1) {
//
//		if(bit_is_clear(PIND,7)){
//			cbi(PORTD,PD6);
//		}
//		else{
//			sbi(PORTD,PD6);
//		}
//
//
//		_delay_ms(2);
//
//	}

