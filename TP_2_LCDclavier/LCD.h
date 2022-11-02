/* 
 * File:   LCD.h
 * Author: damie
 *
 * Created on June 13, 2022, 2:36 PM
 */

#define DISPLAY_CLEAR 0x01
#define RETURN_HOME 0x02
#define ENTRY_MODE_SET_CI_DNS 0x06 //Cursor increase, is not shifted
#define ENTRY_MODE_SET_CI_DS 0x07 //Cursor increase, shifted
#define DISPLAY_ON_CUR_ON_BLINK_ON 0x0F
#define DISPLAY_ON_CUR_ON_BLINKOFF 0x0E
#define SHIFT_DISPLAY_RIGHT 0x1C
#define SHIFT_DISPLAY_LEFT 0x18
#define SHIFT_CURSOR_RIGHT 0x14
#define SHIFT_CURSOR_LEFT 0x10
#define SET_FUNC_8BIT_2LINE_5x10 0x3C
#define SET_FUNC_8BIT_2LINE_5x7 0x38

void init_aff_lcd(void);
void LCD_busy (void);
void lcd_print (unsigned char carac);
void LCD_Clear (void);
