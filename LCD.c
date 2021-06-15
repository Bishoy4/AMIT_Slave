/*
 * LCD.c
 *
 * Created: 30/10/2020 06:08:56 م
 *  Author: ahmed
 */ 


#include "LCD.h"



void LCD_Init(void)
{
	#if      LCD_MODE   ==    8
	/*initializing the pins direction in 8-bit mode*/
	DIO_SetPinDir(LCD_8BIT_CMD_PORT , LCD_RS_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_8BIT_CMD_PORT , LCD_RW_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_8BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_OUTPUT);
	
	DIO_SetPortDir(LCD_8BIT_DATA_PORT , DIO_PORT_OUTPUT);
	
	_delay_ms(100);
	/*send commands to LCD for initializing as 8-bit mode*/
	LCD_WriteCommand(0x38);
	/*Cursor off*/
	LCD_WriteCommand(0x0C);
	/*clear LCD*/
	LCD_WriteCommand(0x01);
	/*Increment Cursor*/
	LCD_WriteCommand(0x06);
	/*Return Home*/
	LCD_WriteCommand(0x02);
	
	#elif    LCD_MODE   ==    4
	/*initializing the pins direction in 4-bit mode*/
	DIO_SetPinDir(LCD_4BIT_CMD_PORT , LCD_RS_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_CMD_PORT , LCD_RW_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_OUTPUT);
	
	DIO_SetPinDir(LCD_4BIT_DATA_PORT , D4_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_DATA_PORT , D5_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_DATA_PORT , D6_PIN , DIO_PIN_OUTPUT);
	DIO_SetPinDir(LCD_4BIT_DATA_PORT , D7_PIN , DIO_PIN_OUTPUT);
	
	_delay_ms(100);
	/*send commands to LCD for initializing as 4-bit mode*/
	LCD_WriteCommand(0x33);
	LCD_WriteCommand(0x32);
	LCD_WriteCommand(0x28);
	
	LCD_WriteCommand(0x0C);
	LCD_WriteCommand(0x01);
	LCD_WriteCommand(0x06);
	LCD_WriteCommand(0x02);
	
	
	#endif
}

void LCD_WriteCommand(uint8 cmd)
{
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_RS_PIN , DIO_PIN_LOW);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_RW_PIN , DIO_PIN_LOW);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);
	
	PORTA = (cmd & 0xf0) | (PORTA & 0x0f);
	
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);
	
	PORTA = (cmd << 4) | (PORTA & 0x0f);
	
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);
	
	
	_delay_ms(5);
}

void LCD_WriteChar(uint8 chr)
{
		DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_RS_PIN , DIO_PIN_HIGH);
		DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_RW_PIN , DIO_PIN_LOW);
		DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);
		
		PORTA = (chr & 0xf0) | (PORTA & 0x0f);
		
		DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH);
		_delay_ms(1);
		DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);
		
		PORTA = (chr << 4) | (PORTA & 0x0f);
		
		DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_HIGH);
		_delay_ms(1);
		DIO_SetPinVal(LCD_4BIT_CMD_PORT , LCD_E_PIN , DIO_PIN_LOW);
		
		
		_delay_ms(5);
}


void LCD_WriteString(char* str)
{
	uint8 i = 0 ;
	
	while(str[i] != '\0')
	{
		LCD_WriteChar(str[i]);
		i++;
	}
}


void LCD_GoTo(uint8 row , uint8 col)
{
	uint8 pos[2] = {0x80 , 0xc0};
	
	LCD_WriteCommand(pos[row]+col);
}


void LCD_Clear(void)
{
	LCD_WriteCommand(0x01);
}

void LCD_WRITE_NUMBER(uint32 number)
{
	uint8 num[10];
	ltoa (number,(uint8*)num,10); //long type of array
	LCD_WriteString(num);
}