#ifndef INC_STEPMOTOR_H_
#define INC_STEPMOTOR_H_


#include "gpio.h"
#include "tim.h"
#include "main.h"
#include "StepMotor.h"



void half_step_motor_left(uint32_t angle, uint8_t number);

void half_step_motor_right(uint32_t angle, uint8_t number);

void SM_it();




#endif /* INC_STEPMOTOR_H_ */
