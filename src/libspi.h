/******************************************************************************
 * Author: John J. Patti
 *
 * Project Name: Centurion
 * File Name: libspi.c
 *
 * Version: 0.1
 * Description: AVR SPI Driver
 *
 * Copyright (c) 2018, John J. Patti
 * All rights reserved.
 *
 *****************************************************************************/

#ifndef LIBSPI_H_
#define LIBSPI_H_

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <inttypes.h>
#include "libgpio.h"

///////////////////////////////////////////////
// Defines
///////////////////////////////////////////////
/**********************************************
 * SPI Pinout is set through the Port B Data
 * Direction Register (mnemonic: DDRB)
 *
 * See Atmega328 Datasheet at 18.4.3
 *
 * Register:
 * 0:
 * 1:
 * 2: SSb  ==> PB2 (bit 2)
 * 3: MOSI ==> PB3 (bit 3)
 * 4: MISO ==> PB4 (bit 4)
 * 5: SCK  ==> PB5 (bit 5)
 * 6:
 * 7:
 *
 * Master sets SCK, MOSI as out
 * Slave set MISO as out
 *
 **********************************************/
#define MSTR_PINOUT		(0x28)  // (1<<3)|(1<<5)
#define SLV_PINOUT		(0x10)  // (1<<4)
#define SS_BAR			(0x04)  // (1<<2) sets SSb as out

#define WIRE_3			(0x00) // 3-wire mode
#define WIRE_4			(0x01) // 4-Wire mode

/**********************************************
 * SPI is setup through the SPI Control
 * Register (mnemonic: SPCR) and SPI Status
 * Register (mnemonic: SPSR)
 *
 * SPCR
 * See Atmega328 Datasheet at 23.5.1
 *
 * Register:
 * 0: Clock Rate (SPR0)
 * 1: Clock Rate (SPR1)
 * 2: Clock Phase (CPHA)
 * 3: Clock Polarity (CPOL)
 * 4: Master/Slave (MSTR) (Mstr: 1; Slv 0)
 * 5: Data Order (DORD) (1: LSB; 0: MSB)
 * 6: SPI Enable (SPE)
 * 7: SPI Interrupt Enable (SPIE)
 *
 * SPSR
 * See Atmega328 Datasheet at 23.5.2
 * 0: SPI Clock Doubler (SPI2X) (1 -> 2x)
 * 1-5: Reserved
 * 6: Write Collision (WCOL) (Read only)
 * 7: SPI Interrupt Flag  (SPIF) (Read Only)
 **********************************************/
// Speed selection
#define FREQ_8MHZ		(0x00)
#define FREQ_4MHZ		(0x01)
#define FREQ_2MHZ		(0x03)
#define FREQ_1MHZ		(0x04)
#define FREQ_500KHZ		(0x05)
#define FREQ_250KHZ		(0x06)
#define FREQ_125KHZ		(0x07)

// Doubler set to off with setting for
// SPR1 and SPR0
#define SPI_4_CLK	(0x00)  // fosc/4
#define SPI_16_CLK	(0x01)	// fosc/16
#define SPI_64_CLK	(0x02)	// fosc/64
#define SPI_128_CLK	(0x03)  // fosc/128

// Doubler required for 1/2, 1/8, and 1/32
#define SPI_DBL		(0x01)
#define SPI_2_CLK	(0x00)  // fosc/2
#define SPI_8_CLK	(0x01)  // fosc/8
#define SPI_32_CLK	(0x02)  // fosc/32

// Sets mode with CPHA and CPOL
#define SPI_MODE_0		(0x00)
#define SPI_MODE_1		(0x04)
#define SPI_MODE_2		(0x08)
#define SPI_MODE_3		(0x0C)

// Sets SPI Master
#define SPI_MSTR		(0x10)  // (1<<4) or (1<<MSTR)

// Enables SPI
#define SPI_EN			(0x40)  // (1<<6) or (1<<SPE)

// SPI Interrupt Enable
#define SPI_IRQ_EN		(0x80)	// (1<<7) or (1<<SPIE)

///////////////////////////////////////////////
// Structs and Typedefs
///////////////////////////////////////////////
typedef struct {
	uint8_t wires; 	// WIRE_3 or WIRE_4
	uint8_t mode;  	// SPI_MODE_0 to SPI_MODE_4
	uint8_t speed; 	// FREQ_125KHZ to FREQ_8MZ
	uint8_t ssbar;
} settingSPI;

typedef struct {
	uint8_t *payload;
	uint8_t bytes;
	uint8_t ssbar;
} packetData;

///////////////////////////////////////////////
// Forward Declarations
///////////////////////////////////////////////
void init_spi_mstr(settingSPI*);
void init_spi_slv(void);
void spi_xmit(packetData*, packetData*);


#endif /* LIBSPI_H_ */
