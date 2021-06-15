/*
 * Timer.c
 *
 * Created: 17/10/2020 01:18:48 م
 *  Author: Ali
 */ 


#include "Timer.h"



uint32 CounterRegister_InitValue = 0;
uint32 Number_OverFlows = 0;



void Timer0_Init(void)
{
	/*select normal mode*/
	CLR_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	
	/*Enable Interrupt*/
	SET_BIT(SREG,7);
	SET_BIT(TIMSK,0);
	
}

void Timer0_SetDelay(uint32 Delay_ms)
{
	
	uint8 Tick_Time = (64 / 16);
	
	uint32 Total_TicksNumber = (Delay_ms * 1000)   /   Tick_Time ;
	
	Number_OverFlows = Total_TicksNumber / 256 ;
	
	CounterRegister_InitValue = 256 - (Total_TicksNumber % 256);
	
	TCNT0 = CounterRegister_InitValue;
	
	Number_OverFlows++;
	
}

void Timer0_Start(void)
{
	SET_BIT(TCCR0 , 0);
	SET_BIT(TCCR0 , 1);
	CLR_BIT(TCCR0 , 2);
	
}

void Timer0_Stop(void)
{
	CLR_BIT(TCCR0 , 0);
	CLR_BIT(TCCR0 , 1);
	CLR_BIT(TCCR0 , 2);
}



void Timer1_Init(void)
{
	SET_BIT(TCCR1B ,3);
	SET_BIT(SREG , 7);
	SET_BIT(TIMSK , 4);
}

void Timer1_SetDelay(uint32 Delay_ms)
{
	uint32 Tick_Time = 1024 / 16 ;
	uint32 Total_Num_Ticks =  (Delay_ms * 1000) / Tick_Time ;
	OCR1 = Total_Num_Ticks - 1;
}

void Timer1_Start(void)
{
	SET_BIT(TCCR1B ,0);
	CLR_BIT(TCCR1B ,1);
	SET_BIT(TCCR1B ,2);
}

void Timer1_Stop(void)
{
	CLR_BIT(TCCR1B ,0);
    CLR_BIT(TCCR1B ,1);
	CLR_BIT(TCCR1B ,2);
	
}



void PWM0_Init(void)
{
	SET_BIT(DDRB ,3);
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
}

void PWM0_Generate(uint8 Duty_Cycle)
{
	OCR0 = ((Duty_Cycle * 256) /100) - 1;
}

void PWM0_Start(void)
{
	/* Prescaler 8 */
	SET_BIT(TCCR0 , 1);
}



void PWM1_Init(void)
{
	/*Timer1 Mode 14*/
	SET_BIT(TCCR1A , 1);
	SET_BIT(TCCR1B , 3);
	SET_BIT(TCCR1B , 4);
	
	/*select non inverted pwm*/
	SET_BIT(TCCR1A , 7);
	
	/*control top value of pwm wave*/
	ICR1 = 1250;
}

void PWM1_Generate(uint8 Duty_Cycle)
{
	OCR1A = ((Duty_Cycle * 1250) /100) - 1;
}

void PWM1_Start(void)
{
	/*select prescaler 256*/
	SET_BIT(TCCR1B , 2);
}