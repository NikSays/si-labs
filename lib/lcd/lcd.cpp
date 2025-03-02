#include "lcd.h"


LCDi2c lcd;

void lcd_setup() {
    lcd = LCDi2c(LCD_ADDRESS);
    lcd.begin(LCD_WIDTH, LCD_HEIGHT);
	lcd.display(DISPLAY_ON);
	lcd.display(BACKLIGHT_ON);
};

int lcd_putchar(char ch, FILE*) {
    switch (ch)
    {
    case LCD_DRV_INPUT_ON:
        lcd.display(CURSOR_ON);
        lcd.display(BLINK_ON);
        break;
    case LCD_DRV_INPUT_OFF:
        lcd.display(CURSOR_OFF);
        lcd.display(BLINK_OFF);
        break;
    case LCD_DRV_CLEAR:
        lcd.cls();
        break;
    case '\n':
        lcd.locate(2,1);
        break;
    default:
        lcd.print(ch);
        break;
    }
    return ch;
}