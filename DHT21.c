/*
 * DHT21.c
 *
 * Created: 5/26/2019 12:12:06 PM
 *  Author: Admin
 */ 
 #include "DHT21.h"

 const uint16_t POLYNOMIAL = 0x131;


 void DHT21_init(){
	 TWI_init();
 }
 float CalcRH(uint16_t rh) {

	 //rh &= ~0x0003;	// clean last two bits

	 return (-6 + 125.0 / 65536.0 * rh); // return relative humidity
 }

 float CalcT(uint16_t t) {

	 //t &= ~0x0003;	// clean last two bits
	 
	 return (-46.85 + 175.72 / 65536.0 * t);
 }

 uint8_t CRC_Checksum(uint8_t data[], uint8_t no_of_bytes, uint8_t checksum) {
	 uint8_t crc = 0;
	 uint8_t byteCtr;
	 uint8_t bit;

	 //calculates 8-Bit checksum with given polynomial
	 for (byteCtr = 0; byteCtr < no_of_bytes; ++byteCtr)
	 {
		 crc ^= (data[byteCtr]);
		 for (bit = 8; bit > 0; --bit)
		 {
			 if (crc & 0x80){
				 crc = (crc << 1) ^ POLYNOMIAL;
			 }
			 
			 else crc = (crc << 1);
		 }
	 }
	 if (crc != checksum) return 0;
	 else return data;
 }

 uint16_t read_value(uint8_t mode){
	 char data[4],crc;
	 uint16_t result;
	 data[0]=mode;
	 
	 TWI_run();
	 TWI_write_data(SHT21_i2c_write);
	 TWI_write_data(*data);
	 
	 TWI_run();
	 TWI_write_data(SHT21_i2c_read);
	 data[1] = TWI_read_data_ack();
	 data[2] = TWI_read_data_ack();
	 crc=TWI_read_data_nack();
	 TWI_stop();
	 
	 result=(data[1]<<8) | data[2];
	 CRC_Checksum(result,4,crc);
	 result &= 0xFFFC;
	 return result;
 }
 float DHT21_read_humidity(){
	 
	 uint16_t hum = read_value(TRIGGER_RH_MEASUREMENT_HM);
	 return CalcRH(hum);
	 
	 
 }
 float DHT21_read_temperature(){
	 uint16_t temp = read_value(TRIGGER_T_MEASUREMENT_HM);
	 return CalcT(temp);
 }
 void DHT21_reset() {
	 TWI_run();
	 TWI_write_data(SHT21_i2c_write);
	 TWI_write_data(SOFT_RESET);
	 TWI_stop();
	 _delay_ms(100);
 }