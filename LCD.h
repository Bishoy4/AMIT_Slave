/*
 * LCD.h
 *
 * Created: 30/10/2020 06:09:08 م
 *  Author: Ali
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "LCD_Cfg.h"
#define  F_CPU   16000000
#include <util/delay.h>



void LCD_Init(void);

void LCD_WriteCommand(uint8 cmd);

void LCD_WriteChar(uint8 chr);

void LCD_WriteString(char* str);

void LCD_GoTo(uint8 row , uint8 col);

void LCD_Clear(void);

void LCD_WRITE_NUMBER(uint32 number);



#endif /* LCD_H_ */