/*
 * TFT_ILI9341.c
 *
 * Created: 5/21/2019 3:24:05 PM
 * Author : Admin
 */ 

#define F_CPU 16000000UL
#include "glcd.h"
#include "DHT21.h"
#include "uart.h"
#include "ADC.h"
#define BG_COLOR black

#define font_size 2

float new_temp = 0.0;
float new_hum = 0.0;
float old_temp = 0.0;
float old_hum = 0.0;
float nthre = 0.0;
float othre = 0.0;

void init_display(){
	glcd_string("Temperature: ",200,0*font_size/2,font_size,orange);
	glcd_string("Humidity: ",200,20*font_size/2,font_size,cyan);
	glcd_string("Threshold: ",200,40*font_size/2,font_size,white);
	//glcd_string("haha",200,60*font_size/2,font_size,yellow);
}

void update_val(float ntemp, float nhum,float otemp,float ohum,float new_threshold,float old_threshold){
	//char buffer[15];
	//char adc_buf[15];
	//clear the previous character
	//dtostrf(otemp,5,2,buffer);
	glcd_float(otemp,strlen("Temperature: ")*font_size,0*font_size/2,font_size,BG_COLOR);
	//dtostrf(ohum,5,2,buffer);
	glcd_float(ohum,strlen("Humidity:")*font_size+10,20*font_size/2,font_size,BG_COLOR);
	//dtostrf(old_threshold,7,3,adc_buf);
	glcd_float(old_threshold/1024*100,strlen("Threshold:")*font_size+10,40*font_size/2,font_size,BG_COLOR);
	//update new value
	//dtostrf(ntemp,5,2,buffer);
	glcd_float(ntemp,strlen("Temperature: ")*font_size,0*font_size/2,font_size,orange);
	//dtostrf(nhum,5,2,buffer);
	glcd_float(nhum,strlen("Humidity:")*font_size+10,20*font_size/2,font_size,cyan);
	//dtostrf(new_threshold,7,3,adc_buf);
	glcd_float(new_threshold/1024*100,strlen("Threshold:")*font_size+10,40*font_size/2,font_size,white);
}

int main(void)
{
	uint8_t num_buf[8];
	
    glcd_init();
	//DDRD |=(1<<1);
	//DDRD &=~(1<<0);
	UART_init(9600);
	ADC_init();
    glcd_led_on();
	glcd_setOrientation(LANDSCAPE);
	DHT21_init();
	DHT21_reset();
	_delay_ms(200);
	glcd_bg(BG_COLOR);
	update_val(new_temp,new_hum,old_temp,old_hum,nthre,othre);
	init_display();
    while(1)
    {
		/////////////////////I2C_SHT21---ADC_trimmer/////////////////////
		new_temp = DHT21_read_temperature();
		new_hum = DHT21_read_humidity();
		_delay_ms(20);
		nthre = (float)ADC_read();
		/////////////////////SPI_ILI9341///////////////////
		_delay_ms(20);
		update_val(new_temp,new_hum,old_temp,old_hum,nthre,othre);
	
		/////////////////////UART_FT232///////////////////
		_delay_ms(20);
		UART_TxChar('T');
		dtostrf(new_temp,5,2,num_buf);
		UART_SendString(num_buf);
		UART_TxChar('H');
		dtostrf(new_hum,5,2,num_buf);
		UART_SendString(num_buf);
		UART_TxChar('\n');
		//////////////////////////////////////////////////
		old_hum = new_hum;
		old_temp = new_temp;
		othre = nthre;
		_delay_ms(200);
    }
}

