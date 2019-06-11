/*
 * I2C.c
 *
 * Created: 5/26/2019 12:11:40 PM
 *  Author: Admin
 */ 
 #include "I2C.h"

 void TWI_init(){
	 TWBR = 0x01;    // Bit rate
	 TWSR &=~((1<<TWPS1)|(1<<TWPS0));
 }

 void TWI_run(){
	 TWCR=(1<<TWSTA)|(1<<TWEN)|(1<<TWINT);
	 while(!(TWCR&(1<<TWINT)));
 }


 uint8_t TWI_write_data(unsigned char data){
	 uint8_t status;		/* Declare variable */
	 TWDR=data;			/* Copy data in TWI data register */
	 TWCR=(1<<TWEN)|(1<<TWINT);	/* Enable TWI and clear interrupt flag */
	 while(!(TWCR&(1<<TWINT)));	/* Wait until TWI finish its current job */
	 status=TWSR&0xF8;		/* Read TWI status register */
	 if(status==0x28)		/* Check for data transmitted &ack received */
	 return 0;			/* Return 0 to indicate ack received */
	 if(status==0x30)		/* Check for data transmitted &nack received */
	 return 1;			/* Return 1 to indicate nack received */
	 else
	 return 2;
 }

 void TWI_stop(){
	 TWCR= (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	 while(TWCR & (1<<TWSTO));
	 //PORTD |= (1<<7);
 }

 char TWI_read_data_ack(void){
	 TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	 while (!(TWCR & (1<<TWINT)));
	 return TWDR;
 }
 char TWI_read_data_nack(void){
	 TWCR=(1<<TWINT)|(1<<TWEN);
	 while (!(TWCR & (1<<TWINT)));
	 return TWDR;
 }
