#include <avr/io.h>

#include "spi.h"

void SPI_MasterInit(void)
{
	DDR_SPI |= (1<<DD_MOSI)|(1<<DD_SCK)|(1<<DD_SS); // MOSI, SCK, SS su output, svi ostali input, SS kao izlaz treba za GLCD
	SPCR = (1<<SPE)|(1<<MSTR);			// enable SPI, SPI master
	SPSR = (1<<SPI2X);				// clock rate fsck/2
}

uint8_t SPI_MasterTransmit(uint8_t cData)
{
	/* Start transmission */
	SPDR = cData;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)))
		;
	return SPDR;	// Za GLCD
}

void SPI_SlaveInit(void)
{
	/* Set MISO output, all others input */
	DDR_SPI = (1<<DD_MISO);
	/* Enable SPI */
	SPCR = (1<<SPE);
}

char SPI_SlaveReceive(void)
{
	/* Wait for reception complete */
	while(!(SPSR & (1<<SPIF)))
	;
	/* Return data register */
	return SPDR;
}
