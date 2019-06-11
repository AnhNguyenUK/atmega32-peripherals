/*
 * DHT21.h
 *
 * Created: 5/26/2019 12:10:45 PM
 *  Author: Admin
 */ 


#ifndef DHT21_H_
#define DHT21_H_

#define I2C_ADD 0x40
#define SHT21_i2c_write 0x80
#define SHT21_i2c_read 0x81
#define TRIGGER_T_MEASUREMENT_HM 0XE3
#define TRIGGER_RH_MEASUREMENT_HM 0XE5
#define TRIGGER_T_MEASUREMENT_NHM 0XF3
#define TRIGGER_RH_MEASUREMENT_NHM 0XF5
#define USER_REGISTER_W 0XE6
#define USER_REGISTER_R 0XE7
#define SOFT_RESET 0XFE
#include "I2C.h"

void DHT21_init();
float CalcRH(uint16_t rh);
float CalcT(uint16_t t) ;
uint8_t CRC_Checksum(uint8_t data[], uint8_t no_of_bytes, uint8_t checksum);
float DHT21_read_humidity();
float DHT21_read_temperature();
void DHT21_reset();



#endif /* DHT21_H_ */