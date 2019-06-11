/*
 * ADC.c
 *
 * Created: 5/26/2019 4:30:04 PM
 *  Author: Admin
 */ 
 #include "ADC.h"

void ADC_init(){
	ADC_DDR = 0;
	ADC_EN();
	//ADC_INT_EN();
	ADC_PRE();
	ADC_REF();
}

uint16_t ADC_read(){
	ADC_START();
	while(~ADC_CONVERSION_DONE);
	return ADC;
}