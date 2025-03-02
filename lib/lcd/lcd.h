#include <stdio.h>
#include <LCDi2c.h>

#define LCD_ADDRESS 0x27
#define LCD_HEIGHT 2
#define LCD_WIDTH 16

#define LCD_DRV_INPUT_ON 1
#define LCD_DRV_INPUT_OFF 2
#define LCD_DRV_CLEAR 3



void lcd_setup();

// File argument will be unused.
int lcd_putchar(char ch, FILE*); 
