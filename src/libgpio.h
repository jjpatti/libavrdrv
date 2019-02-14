/******************************************************************************
 * Author: John J. Patti
 *
 * Project Name: Centurion
 * File Name: libgpio.h
 *
 * Version: 0.1
 * Description: AVR GPIO Driver
 *
 * Copyright (c) 2018, John J. Patti
 * All rights reserved.
 *
 *****************************************************************************/

#ifndef LIBGPIO_H_
#define LIBGPIO_H_

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <inttypes.h>

///////////////////////////////////////////////
// Defines
///////////////////////////////////////////////
/**********************************************
 * Pin Labels
 **********************************************/
#define P0				(0x0)
#define P1				(0x1)
#define P2				(0x2)
#define P3				(0x3)
#define P4				(0x4)
#define P5				(0x5)
#define P6				(0x6)
#define P7				(0x7)
#define P8				(0x8)
#define P9				(0x9)
#define P10				(0xA)
#define P11				(0xB)
#define P12				(0xC)
#define P13				(0xD)

/**********************************************
 * Port D Registers
 *
 * See Atmega328 Datasheet at 18.4.8 - 18.4.10
 *
 * Register:
 * 0: Arduino Pin 0
 * 1: Arduino Pin 1
 * 2: Arduino Pin 2
 * 3: Arduino Pin 3
 * 4: Arduino Pin 4
 * 5: Arduino Pin 5
 * 6: Arduino Pin 6
 * 7: Arduino Pin 7
 *
 **********************************************/
#define PIN_0			(0x0)
#define PIN_1			(0x1)
#define PIN_2			(0x2)
#define PIN_3			(0x3)
#define PIN_4			(0x4)
#define PIN_5			(0x5)
#define PIN_6			(0x6)
#define PIN_7			(0x7)

/**********************************************
 * Port B Registers
 *
 * See Atmega328 Datasheet at 18.4.2 - 18.4.4
 *
 * Register:
 * 0: Arduino Pin 8
 * 1: Arduino Pin 9
 * 2: Arduino Pin 10
 * 3: Arduino Pin 11
 * 4: Arduino Pin 12
 * 5: Arduino Pin 13
 * 6:
 * 7:
 *
 **********************************************/
#define PIN_8			(0x0)
#define PIN_9			(0x1)
#define PIN_10			(0x2)
#define PIN_11			(0x3)
#define PIN_12			(0x4)
#define PIN_13			(0x5)

/**********************************************
 * Set Values for Ports B and D
 * Data Direction Registers
 *
 * See Atmega328 Datasheet at 18.4.3 and 18.4.9
 *
 **********************************************/
#define INPUT			(0x0)
#define OUTPUT			(0x1)

/**********************************************
 * Set Values for Ports B and D
 * Data Direction Registers
 *
 * See Atmega328 Datasheet at 18.4.2 and 18.4.8
 *
 **********************************************/
#define LOW			(0x0)
#define HIGH			(0x1)

///////////////////////////////////////////////
// Structs and Typedefs
///////////////////////////////////////////////
typedef struct{
	uint8_t pin;
	uint8_t direction;
} pinCntl;

///////////////////////////////////////////////
// Forward Declarations
///////////////////////////////////////////////
void set_pin(pinCntl*);
void set_input(uint8_t);
void set_output(uint8_t);
void digital_write(uint8_t, uint8_t);

#endif /* LIBGPIO_H_ */
