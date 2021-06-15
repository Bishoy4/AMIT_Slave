/*
 * AMIT_Slave.c
 *
 * Created: 11/06/2021 03:56:25 ص
 * Author : Beshoy Atya
 */ 



#include "ADC.h"
#include "SPi.h"
#include "LCD.h"
#include "DC_Motor.h"

int main(void)
{
	LCD_Init();
	SPI_Slave_Init();
	DcMotor_Init();

    DIO_SetPinDir(DIO_PORTC,DIO_PIN0,DIO_PIN_OUTPUT);         // init led output //
	DIO_SetPinDir(DIO_PORTA,DIO_PIN1,DIO_PIN_INPUT);          // init lm35 input // 
	
    uint16 temp=0;
	
	uint8 count=0;
	uint8 var;
	while (1)
	{
		var=SPI_Read();
		if (var=='1')
		{
			SET_BIT(PORTC , 0);		
		}
		else if (var=='2')
		{
			CLR_BIT(PORTC , 0);
			
		}
		
		else if (var=='3')
		{
			
			temp = ADC_Read();
			temp /=4;
			LCD_GoTo(1,0);
			LCD_WriteString( "The temperature =" );
			LCD_GoTo(2,0);
			LCD_WRITE_NUMBER(temp);
			_delay_ms(5000);
			LCD_Clear();
			
		}
		else if (var=='+')
		{
			count++;
			switch(count)
			{
				case 1:
				DcMotor_Start();
				DcMotor_SetDir(DIR_CLOCK_WISE);
				DcMotor_SetSpeed(51);
				DcMotor_Stop();
				break;
				case 2:
				DcMotor_Start();
				DcMotor_SetDir(DIR_CLOCK_WISE);
				DcMotor_SetSpeed(102);
				DcMotor_Stop();
				break;
				case 3:
				DcMotor_Start();
				DcMotor_SetDir(DIR_CLOCK_WISE);
				DcMotor_SetSpeed(153);
				DcMotor_Stop();
				break;
				case 4:
				DcMotor_Start();
				DcMotor_SetDir(DIR_CLOCK_WISE);
				DcMotor_SetSpeed(204);
				DcMotor_Stop();
				break;
				case 5:
				DcMotor_Start();
				DcMotor_SetDir(DIR_CLOCK_WISE);
				DcMotor_SetSpeed(255);
				DcMotor_Stop();
				break;
			}
			if (count>5)
			{
				count=5;
			}
			
		}
		else if (var=='-')
		{
			count=count-1;
			if (count==0)
			{
				DcMotor_Start();
				DcMotor_SetDir(DIR_ANTI_CLOCK_WISE);
				DcMotor_SetSpeed(51);
				DcMotor_Stop(); 
			}
			switch(count)
			{
				case 1:
				DcMotor_Start();
				DcMotor_SetDir(DIR_ANTI_CLOCK_WISE);
				DcMotor_SetSpeed(51);
				DcMotor_Stop();
				break;
				case 2:
				DcMotor_Start();
				DcMotor_SetDir(DIR_ANTI_CLOCK_WISE);
				DcMotor_SetSpeed(102);
				DcMotor_Stop();
				break;
				case 3:
				DcMotor_Start();
				DcMotor_SetDir(DIR_ANTI_CLOCK_WISE);
				DcMotor_SetSpeed(153);
				DcMotor_Stop();
				break;
				case 4:
				DcMotor_Start();
				DcMotor_SetDir(DIR_ANTI_CLOCK_WISE);
				DcMotor_SetSpeed(204);
				DcMotor_Stop();
				break;
				case 5:
				DcMotor_Start();
				DcMotor_SetDir(DIR_ANTI_CLOCK_WISE);
				DcMotor_SetSpeed(255);
				DcMotor_Stop();
				break;
			}
			
		}
		
	}
}

