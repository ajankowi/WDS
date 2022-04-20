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
#include "util/i2cmaster.h"
#include "util/millis.h"
#include "VL53L0X.h"
#include "StepMotor.h"
#include "USART.h"

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

#define PIN_I2C_SDA 	PC1
#define PIN_I2C_SCL 	PC0

#define BAUD 			115200	// Serial baudrate for user interface

#define Timer_ISR(N)            \
void N (void)__attribute((signal,used)); \
void N (void)

#define 	bit_is_set(sfr, bit)   (_SFR_BYTE(sfr) & _BV(bit))
#define 	bit_is_clear(sfr, bit)   (!(_SFR_BYTE(sfr) & _BV(bit)))





void init(void) {
	//debugInit();
	//--------------------------------------------------
	// GPIOs
	//--------------------------------------------------
	//cbi( UCSRB, RXEN );		// Disable UART RX
	//DDRD =  (1<<PIN_UART_TX);	// Set UART TX as output
	// Enable weak pullups on I2C lines
	PORTC = (1<<PIN_I2C_SCL) | (1<<PIN_I2C_SDA);
	//--------------------------------------------------
	// Init the other modules
	//--------------------------------------------------
	i2c_init();
	initMillis();
	sei();
}


int main() {

//	char c;
	char tab[20];
//    int i = 0;
//    char bufor [100];

	//uint16_t a = 0;
	uint16_t liczba = 0;

	 statInfo_t xTraStats;
	 init();
	 initVL53L0X(1);


	USART_Init();

	 setMeasurementTimingBudget( 500 * 1000UL );		// integrate over 500 ms per measurement


	while(1){

		liczba = readRangeSingleMillimeters( &xTraStats );

		//half_step_motor_left(100,1);
		//half_step_motor_left(100,2);


		//sprintf(tab, " Dziala_4! \r\n");
		//UART_SendString(tab);

		//UART_SendString(tab);

//		//DZIALA!
//
//		UART_GetString();
//		UART_SendString(buff);
//		_delay_ms(10);



		UART_GetString();




		sprintf(tab, "%d", 99);


		if(buff[0] == tab[0]){


			sprintf(buff,"%d",liczba);
			UART_SendString(buff);

		}
		else{
			sprintf(buff,"0");
			UART_SendString(buff);
		}


		_delay_ms(10);

	}

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


