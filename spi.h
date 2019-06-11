/*
 * spi.h
 *
 * Created: 5/21/2019 3:53:53 PM
 *  Author: Admin
 */ 


#ifndef SPI_H_
#define SPI_H_

#define DD_MOSI	5
#define DD_MISO	6
#define DD_SCK	7
#define DDR_SPI	DDRB
#define DD_SS	4

/*
atmega8 datasheet, page 123
SPCR = SPIE, SPE, DORD, MSTR, CPOL, CPHA, SPR1, SPR0 (D7...D0)
SPSR = SPIF, WCOL, -, -, -, -, -, SPI2x (D7...D0)

SPI2X SPR1 SPR0 SCK_freq
0 0 0 fosc/4
0 0 1 fosc/16
0 1 0 fosc/64
0 1 1 fosc/128
1 0 0 fosc/2
1 0 1 fosc/8
1 1 0 fosc/32
1 1 1 fosc/64
*/

void SPI_MasterInit(void);

uint8_t SPI_MasterTransmit(uint8_t cData);

void SPI_SlaveInit(void);

char SPI_SlaveReceive(void);

#endif /* SPI_H_ */