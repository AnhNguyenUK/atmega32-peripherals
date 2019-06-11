/*
 * glcd.h
 *
 * Created: 5/22/2019 12:51:56 PM
 *  Author: Admin
 */ 


#ifndef GLCD_H_
#define GLCD_H_

/*
GLCD	AT8    AT32
VCC
GND
CS		PD5		11 19
RST		PD4		6  18
DC		PD6		12 20
MOSI	PB3		17  6
SCK		PB5		19  8
LED		PD7		13 21
MISO	PB4		18  7	// not really needed
*/
#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include <stdlib.h>	// abs()
#include <string.h>	// strlen()
#include "spi.h"
#include "colors.h"
#include "cmd.h"



#define MAX_X   360
#define MAX_Y   320

#define FONT_SPACE	6
#define FONT_X		8
#define FONT_Y		8

#define PORTRAIT	0
#define LANDSCAPE	1

void glcd_cs_low();
void glcd_cs_high();
void glcd_dc_low();
void glcd_dc_high();
void glcd_led_off();
void glcd_led_on();
void glcd_rst_off();
void glcd_rst_on();

void glcd_sendCmd(unsigned char data);
void glcd_sendData(unsigned char data);
void glcd_sendData16(unsigned int data);
void glcd_init(void);
void glcd_setX(unsigned int x0,unsigned int x1);
void glcd_setY(unsigned int y0,unsigned int y1);
void glcd_setOrientation(char orientation);
void glcd_setXY(unsigned int x0, unsigned int y0);
void glcd_line(unsigned int x0,unsigned int y0,unsigned int x1, unsigned int y1, unsigned int color);
void glcd_hline(unsigned int x0, unsigned int y0, unsigned int length, unsigned int color);
void glcd_vline(unsigned int x0, unsigned int y0, unsigned int length, unsigned int color);
void glcd_rectangle(unsigned int x0, unsigned int y0, unsigned int length, unsigned int width, unsigned int color);
void glcd_fillRectangle(unsigned int x0, unsigned int y0, unsigned int length, unsigned int width, unsigned int color);
void glcd_circle(int x0, int y0, int r, unsigned int color);
void glcd_fillCircle(int x0, int y0, int r, unsigned int color);
void glcd_char(unsigned char ascii, unsigned int x0, unsigned int y0,unsigned int size, unsigned int fgcolor);
void glcd_string(char *argstring, unsigned int x0, unsigned int y0, unsigned int size,unsigned int fgcolor);
unsigned char glcd_number(unsigned int long_num,unsigned int x0, unsigned int y0,unsigned int size,unsigned int fgcolor);
unsigned char glcd_float(float floatNumber, unsigned int x0, unsigned int y0, unsigned int size, unsigned int fgcolor);
void glcd_kocka(unsigned int x0, unsigned int y0, unsigned int koliko, unsigned int size, unsigned int fgcolor);
void glcd_clr(unsigned int x0, unsigned int y0, unsigned int size);
void glcd_clrLine(unsigned int y0, unsigned int size);
void glcd_pixel(unsigned int x0, unsigned int y0, unsigned int color);
void glcd_bar(unsigned int x0, unsigned int y0, unsigned int koliko, unsigned int bar_max, unsigned int size, unsigned int fgcolor, unsigned int rectangle_color);
void glcd_eq(char *string, unsigned int x0, unsigned int y0, float koliko, unsigned int size, unsigned int fgcolor, unsigned int rectangle_color);
void glcd_bg(unsigned int color);
void glcd_arc(int x, int y, int r, int startAngle, int endAngle, int thickness, unsigned int color);
void glcd_title(char *string, unsigned int size, unsigned int fgcolor, unsigned int bgcolor);


#endif /* GLCD_H_ */