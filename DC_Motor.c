/*
 * DC_Motor.c
 *
 * Created: 05/12/2020 07:18:11 م
 *  Author: Ali
 */ 

#include "DC_Motor.h"


void DcMotor_Init(void)
{
	DIO_SetPinDir(DIO_PORTC , DIO_PIN3 , DIO_PIN_OUTPUT);
	DIO_SetPinDir(DIO_PORTC , DIO_PIN4 , DIO_PIN_OUTPUT);
	
	PWM0_Init();
}

void DcMotor_SetDir(DcMotor_Dir dir)
{
	switch(dir)
	{
		case DIR_CLOCK_WISE :
		DIO_SetPinVal(DIO_PORTC , DIO_PIN3 , DIO_PIN_HIGH);
		DIO_SetPinVal(DIO_PORTC , DIO_PIN4 , DIO_PIN_LOW);
		break;
		
		case DIR_ANTI_CLOCK_WISE :
		DIO_SetPinVal(DIO_PORTC , DIO_PIN3 , DIO_PIN_LOW);
		DIO_SetPinVal(DIO_PORTC , DIO_PIN4 , DIO_PIN_HIGH );
		break;
		
		default:
		break;
	}
}

void DcMotor_SetSpeed(uint8 speed)
{
	speed *= 10;
	PWM0_Generate(speed);
}

void DcMotor_Start(void)
{
	PWM0_Start();
}

void DcMotor_Stop(void)
{
	DIO_SetPinVal(DIO_PORTC , DIO_PIN3 , DIO_PIN_LOW);
	DIO_SetPinVal(DIO_PORTC , DIO_PIN4 , DIO_PIN_LOW );
}