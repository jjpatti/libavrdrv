/******************************************************************************
 * Author: John J. Patti
 *
 * Project Name: Centurion
 * File Name: libspi.c
 *
 * Version: 0.1
 * Description: AVR SPI Driver (ATMega 328)
 *
 * Copyright (c) 2018, John J. Patti
 * All rights reserved.
 *
 *****************************************************************************/

#include "libspi.h"

void init_spi_mstr(settingSPI *paramSPI)
{
	DDRB = MSTR_PINOUT;
	SPCR = SPI_EN|SPI_MSTR|SPI_IRQ_EN;
	switch(paramSPI->mode){
	case SPI_MODE_0:
		SPCR |= SPI_MODE_0;
		break;
	case SPI_MODE_1:
		SPCR |= SPI_MODE_1;
		break;
	case SPI_MODE_2:
		SPCR |= SPI_MODE_2;
		break;
	case SPI_MODE_3:
		SPCR |= SPI_MODE_3;
		break;
	default:
		SPCR |= SPI_MODE_0;
		break;
	}

	if(paramSPI->wires == WIRE_4){
		SPCR |= SS_BAR;
	}

	switch(paramSPI->speed){
	case FREQ_8MHZ:
		SPCR |= SPI_DBL|SPI_2_CLK;
		break;
	case FREQ_4MHZ:
		SPCR |= SPI_4_CLK;
		break;
	case FREQ_2MHZ:
		SPCR |= SPI_DBL|SPI_8_CLK;
		break;
	case FREQ_1MHZ:
		SPCR |= SPI_16_CLK;
		break;
	case FREQ_500KHZ:
		SPCR |= SPI_DBL|SPI_32_CLK;
		break;
	case FREQ_250KHZ:
		SPCR |= SPI_64_CLK;
		break;
	case FREQ_125KHZ:
		SPCR |= SPI_128_CLK;
		break;
	default:
		SPCR |= SPI_2_CLK;
		break;
	}

	sei();
}

void init_spi_slv(void){
	DDRB = SLV_PINOUT;
	SPCR = SPI_EN|SPI_IRQ_EN;
}

void spi_xmit(packetData *in, packetData *out){
	uint8_t i;
	for (i = 0; i < in->bytes; i++){
		SPDR = in->payload[i];
		asm volatile("nop");
		while(!(SPSR & (1<<SPIF) ));
		out->payload[i] = SPDR;
	}
}


