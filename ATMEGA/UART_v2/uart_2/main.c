#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/sfr_defs.h>
#include <math.h>
#include <avr/pgmspace.h>
//ustawiona czêstotliwoœæ - 18432000

//pomocnicze sta³e
#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

//stale do obslugi switchy
#define RESETUJ        0x00
#define ZAPIS        0x01
#define ODCZYT        0x02
#define    WYSWIETLAJ    0x03
#define PRZESTAN_W    0x04

#define AAA            0x01
#define BBB            0x02
#define CCC            0x03

volatile unsigned char a,b,c, stan=0, wysw=0;

void usart_init(void)        //funkcja inicjalizuj¹ca usart
{
    UBRRH = (BAUD_PRESCALE >> 8);        //wpisanie starszego bajtu
    UBRRL = BAUD_PRESCALE;             //wpisanie mlodszego bajtu

    //UCSRA bez zmian - 0x00
    UCSRB = (1<<TXEN)|(1<<RXEN)|(1<<RXCIE);     //zmiana D0 i D1, aktywacja przerwania RX
    UCSRC = (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);         //praca synchroniczna, brak kontroli parzystoœci, 1 bit stopu, 8 bitów danych

}

void timer0_init(void)
{
    TCCR0 = (1<<CS02);
    TIMSK |= (1<<TOIE0);
}

int main(void)
{
    PORTD = 0x02;        //pullup na TXC
    PORTB = 0xFF;        //pullup na port b
    usart_init();
    timer0_init();
    sei();                //aktywacja przerwañ
    for(;;);                //nieskonczona petla
}

ISR(TIMER0_OVF_vect)
{
    if(wysw) UDR = PINB;    //je¿eli zmienna wysw jest ró¿na od 0 - stan pinb jest wysy³any do komputera
}

ISR(USART_RXC_vect)        //przerwanie od odbioru danej
{
    static unsigned char odebrana;        //zmienna pomocnicza
    odebrana = UDR;                //zapis odebranej danej
    UDR = odebrana;
    if(stan==0) //stan domyslny
    {
        switch(odebrana)
        {
            case(RESETUJ):        {a=0; b=0; c=0; wysw=0; UDR=0xFF;}
            case(ZAPIS):        {stan=1; UDR=0xFF;}
            case(ODCZYT):        {stan=2; UDR=0xFF;}
            case(WYSWIETLAJ):    {wysw=1; UDR=0x00;}
            case(PRZESTAN_W):    {wysw=0; UDR=0x00;}
        }
    }
    if(stan==1) //stan zapisu
    {
        switch(odebrana)
        {
            case(AAA):            {UDR=0xFF; stan=3;}
            case(BBB):            {UDR=0xFF; stan=4;}
            case(CCC):            {UDR=0xFF; stan=5;}
        }
    }
    else if(stan==2) //stan odczytu
    {
        switch(odebrana)
        {
            case(AAA):            {UDR=a; stan=0;}
            case(BBB):            {UDR=b; stan=0;}
            case(CCC):            {UDR=c; stan=0;}
        }
    }
    else if(stan==3) //stan zapisu zmiennej a
    {
        a=odebrana; UDR=0xFF; stan=0;
    }
    else if(stan==4) //stan zapisu zmiennej a
    {
        b=odebrana; UDR=0xFF; stan=0;
    }
    else if(stan==5) //stan zapisu zmiennej a
    {
        c=odebrana; UDR=0xFF; stan=0;
    }
}
