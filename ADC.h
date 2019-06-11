/*
 * ADC.h
 *
 * Created: 5/26/2019 1:22:59 PM
 *  Author: Admin
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "Config.h"

#define ADC_START()	{ADCSRA |= 1<<ADSC;}
#define ADC_EN()	{ADCSRA |= 1<<ADEN;}
#define ADC_INT_EN()	{ADCSRA |= 1<<ADIE;}
#define ADC_PRE()	{ADCSRA |= (1<<ADPS1)|(1<<ADPS2);}//CLK/128
#define ADC_AUTO_TRIG()	{ADCSRA |= 1<<ADATE;}
#define ADC_REF()	{ADMUX |= (1<<REFS0)|(1<<REFS1);}
#define ADC_CONVERSION_DONE	ADCSRA&(1<<ADIF)
#define ADC_DDR		DDRA

void ADC_init();

uint16_t ADC_read();

#endif /* ADC_H_ */