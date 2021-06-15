/*
 * DC_Motor.h
 *
 * Created: 05/12/2020 07:18:23 م
 *  Author: Ali
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "Timer.h"
#include "DIO.h"



typedef enum
{
	DIR_CLOCK_WISE,
	DIR_ANTI_CLOCK_WISE
}DcMotor_Dir;



void DcMotor_Init(void);

void DcMotor_SetDir(DcMotor_Dir dir);

void DcMotor_SetSpeed(uint8 speed);

void DcMotor_Start(void);

void DcMotor_Stop(void);



#endif /* DC_MOTOR_H_ */