/*
 * Timer.h
 *
 * Created: 17/10/2020 01:18:58 م
 *  Author: Ali
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "ATmega_Registers.h"
#include "BIT_MATH.h"


void Timer0_Init(void);

void Timer0_SetDelay(uint32 Delay_ms);

void Timer0_Start(void);

void Timer0_Stop(void);



void Timer1_Init(void);

void Timer1_SetDelay(uint32 Delay_ms);

void Timer1_Start(void);

void Timer1_Stop(void);


void PWM0_Init(void);

void PWM0_Generate(uint8 Duty_Cycle);

void PWM0_Start(void);



void PWM1_Init(void);

void PWM1_Generate(uint8 Duty_Cycle);

void PWM1_Start(void);

#endif /* TIMER_H_ */