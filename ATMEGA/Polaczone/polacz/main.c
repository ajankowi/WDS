#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "util/i2cmaster.h"
#include "util/millis.h"
#include "VL53L0X.h"
#include "HD44780.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/sfr_defs.h>
#include <math.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include "StepMotor.h"


//--------------------------------------------------
// Global Defines
//--------------------------------------------------
// GPIO
#define PIN_I2C_SDA 	PC1
#define PIN_I2C_SCL 	PC0

// Constants
#define BAUD 			115200	// Serial baudrate for user interface



#define BU 9600
#define BRC ((F_CPU/16/BU)-1)


void UART_TxChar(char ch);
void UART_SendString(char *str);
unsigned char UART_RxChar();
void UART_GetString();

char *buff;


void init(void) {
	//debugInit();
	//--------------------------------------------------
	// Enable weak pullups on I2C lines
	PORTC = (1<<PIN_I2C_SCL) | (1<<PIN_I2C_SDA);
	//--------------------------------------------------
	// Init the other modules
	//--------------------------------------------------
	i2c_init();
	initMillis();
	sei();
}


int main(){

	statInfo_t xTraStats;
	char tab[20];
	 init();





	 	UBRRH = (BRC >> 8);
	 	UBRRL = BRC;

	 	UCSRB = (1<<RXEN) | (1<<TXEN);
	 	UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);








	//debug_str("\n\n---------------------------------------\n");
	//debug_str(" Hello world, this is vl53l0xExample ! \n");
	//debug_str("---------------------------------------\nGit: ");
	//debug_str( GIT_VERSION );
	//debug_putc( '\n' );

	 initVL53L0X(1);
	// lower the return signal rate limit (default is 0.25 MCPS)
	// setSignalRateLimit(0.1);
	// increase laser pulse periods (defaults are 14 and 10 PCLKs)
	// setVcselPulsePeriod(VcselPeriodPreRange, 18);
	// setVcselPulsePeriod(VcselPeriodFinalRange, 14);

	 setMeasurementTimingBudget( 500 * 1000UL );		// integrate over 500 ms per measurement


	LCD_Initalize();
	LCD_Home();


	int liczba = 0;
	// Main loop

	while(1){


		liczba = readRangeSingleMillimeters( &xTraStats );	// blocks until measurement is finished

			LCD_Clear();

			LCD_GoTo(0, 0);
			sprintf(tab, " Dziala? %d ", liczba);
			LCD_WriteText(tab);
			_delay_ms(100);

				UART_SendString("Dziala?\n\r");

				_delay_ms(1000);


	}
	return 0;
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
