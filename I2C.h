/*
 * I2C.h
 *
 * Created: 5/26/2019 12:08:52 PM
 *  Author: Admin
 */ 


#ifndef I2C_H_
#define I2C_H_

#include "Config.h"

#define BITRATE(TWSR)	((F_CPU/SCL_CLK)-16)/(2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1)))))

void TWI_init();
void TWI_run();
uint8_t TWI_write_data(unsigned char data);
void TWI_stop();
char TWI_read_data_ack(void);
char TWI_read_data_nack(void);



#endif /* I2C_H_ */