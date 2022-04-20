#ifndef STEPMOTOR_H_
#define STEPMOTOR_H_



//Odpowiednie wyjscia dla silnika 1

#define SM_1_IN1_DIR		DDRB
#define SM_1_IN1_PORT		PORTB
#define SM_1_IN1			PB0

#define SM_1_IN2_DIR		DDRB
#define SM_1_IN2_PORT		PORTB
#define SM_1_IN2			PB1

#define SM_1_IN3_DIR		DDRB
#define SM_1_IN3_PORT		PORTB
#define SM_1_IN3			PB2

#define SM_1_IN4_DIR		DDRB
#define SM_1_IN4_PORT		PORTB
#define SM_1_IN4			PB3

//Odpowiednie wyjscia dla silnika 2

#define SM_2_IN1_DIR		DDRA
#define SM_2_IN1_PORT		PORTA
#define SM_2_IN1			PA0

#define SM_2_IN2_DIR		DDRA
#define SM_2_IN2_PORT		PORTA
#define SM_2_IN2			PA1

#define SM_2_IN3_DIR		DDRA
#define SM_2_IN3_PORT		PORTA
#define SM_2_IN3			PA2

#define SM_2_IN4_DIR		DDRA
#define SM_2_IN4_PORT		PORTA
#define SM_2_IN4			PA3









#ifndef _BV
#define _BV(bit)				(1<<(bit))
#endif

#ifndef inb
#define	inb(addr)			(addr)
#endif

#ifndef outb
#define	outb(addr, data)	addr = (data)
#endif

#ifndef sbi
#define sbi(reg,bit)		reg |= (_BV(bit))
#endif

#ifndef cbi
#define cbi(reg,bit)		reg &= ~(_BV(bit))
#endif

#ifndef tbi
#define tbi(reg,bit)		reg ^= (_BV(bit))
#endif

/*
 *  Gotowe zaimplementowane: */
 #define 	bit_is_set(sfr, bit)   (_SFR_BYTE(sfr) & _BV(bit))
 #define 	bit_is_clear(sfr, bit)   (!(_SFR_BYTE(sfr) & _BV(bit)))
 #define 	loop_until_bit_is_set(sfr, bit)   do { } while (bit_is_clear(sfr, bit))
 #define 	loop_until_bit_is_clear(sfr, bit)   do { } while (bit_is_set(sfr, bit))


// MIN/MAX/ABS macros
#define MIN(a,b)			((a<b)?(a):(b))
#define MAX(a,b)			((a>b)?(a):(b))
#define ABS(x)				((x>0)?(x):(-x))


//  Funkcja inicjalizuje Timer
//

void TimerInit(uint16_t dzielnik);

void half_step_motor_left(uint32_t angle, uint8_t number);


void half_step_motor_right(uint32_t angle, uint8_t number);


void full_step_motor_left(uint32_t angle,  uint8_t number);


void full_step_motor_right(uint32_t angle,  uint8_t number);



#endif /* STEPMOTOR_H_ */
