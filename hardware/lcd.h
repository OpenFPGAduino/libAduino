/*
 * lcd.h
 *
 *  Created on: Aug 10, 2013
 *      Author: zhizhouli
 */

#ifndef LCD_H_
#define LCD_H_
extern void lcd_clear(char red, char green, char blue);
extern void lcd_set_point(int x, int y, char red, char green, char blue);
extern void lcd_clear_box(int x, int y,int length, int height, char red, char green, char blue);
extern void lcd_init(void);

#endif /* LCD_H_ */
