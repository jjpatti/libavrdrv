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

#include "libgpio.h"

void set_pin(pinCntl *pinParams){
	switch(pinParams->direction){
	case INPUT:
		setInput(pinParams->pin);
		break;
	case OUTPUT:
		setOutput(pinParams->pin);
		break;
	default:
		break;
	}
}

void set_output(uint8_t pin)
{
	switch(pin){
	case P0:
		DDRD |= (1 << PIN_0);
		break;
	case P1:
		DDRD |= (1 << PIN_1);
		break;
	case P2:
		DDRD |= (1 << PIN_2);
		break;
	case P3:
		DDRD |= (1 << PIN_3);
		break;
	case P4:
		DDRD |= (1 << PIN_4);
		break;
	case P5:
		DDRD |= (1 << PIN_5);
		break;
	case P6:
		DDRD |= (1 << PIN_6);
		break;
	case P7:
		DDRD |= (1 << PIN_7);
		break;
	case P8:
		DDRB |= (1 << PIN_8);
		break;
	case P9:
		DDRB |= (1 << PIN_9);
		break;
	case P10:
		DDRB |= (1 << PIN_10);
		break;
	case P11:
		DDRB |= (1 << PIN_11);
		break;
	case P12:
		DDRB |= (1 << PIN_12);
		break;
	case P13:
		DDRB |= (1 << PIN_13);
		break;
	default:
		break;
	}
}

void set_input(uint8_t pin)
{
	switch(pin){
	case P0:
		DDRD &= ~(1 << PIN_0);
		break;
	case P1:
		DDRD &= ~(1 << PIN_1);
		break;
	case P2:
		DDRD &= ~(1 << PIN_2);
		break;
	case P3:
		DDRD &= ~(1 << PIN_3);
		break;
	case P4:
		DDRD &= ~(1 << PIN_4);
		break;
	case P5:
		DDRD &= ~(1 << PIN_5);
		break;
	case P6:
		DDRD &= ~(1 << PIN_6);
		break;
	case P7:
		DDRD &= ~(1 << PIN_7);
		break;
	case P8:
		DDRB &= ~(1 << PIN_8);
		break;
	case P9:
		DDRB &= ~(1 << PIN_9);
		break;
	case P10:
		DDRB &= ~(1 << PIN_10);
		break;
	case P11:
		DDRB &= ~(1 << PIN_11);
		break;
	case P12:
		DDRB &= ~(1 << PIN_12);
		break;
	case P13:
		DDRB &= ~(1 << PIN_13);
		break;
	default:
		break;

	}
}

void digital_write(uint8_t pin, uint8_t direction)
{
	if (direction == HIGH){
		switch(pin){
		case P0:
			PORTD |= (1 << PIN_0);
			break;
		case P1:
			PORTD |= (1 << PIN_1);
			break;
		case P2:
			PORTD |= (1 << PIN_2);
			break;
		case P3:
			PORTD |= (1 << PIN_3);
			break;
		case P4:
			PORTD |= (1 << PIN_4);
			break;
		case P5:
			PORTD |= (1 << PIN_5);
			break;
		case P6:
			PORTD |= (1 << PIN_6);
			break;
		case P7:
			PORTD |= (1 << PIN_7);
			break;
		case P8:
			PORTB |= (1 << PIN_8);
			break;
		case P9:
			PORTB |= (1 << PIN_9);
			break;
		case P10:
			PORTB |= (1 << PIN_10);
			break;
		case P11:
			PORTB |= (1 << PIN_11);
			break;
		case P12:
			PORTB |= (1 << PIN_12);
			break;
		case P13:
			PORTB |= (1 << PIN_13);
			break;
		default:
			break;
		}
	}
	else{
		switch(pin){
		case P0:
			PORTD &= ~(1 << PIN_0);
			break;
		case P1:
			PORTD &= ~(1 << PIN_1);
			break;
		case P2:
			PORTD &= ~(1 << PIN_2);
			break;
		case P3:
			PORTD &= ~(1 << PIN_3);
			break;
		case P4:
			PORTD &= ~(1 << PIN_4);
			break;
		case P5:
			PORTD &= ~(1 << PIN_5);
			break;
		case P6:
			PORTD &= ~(1 << PIN_6);
			break;
		case P7:
			PORTD &= ~(1 << PIN_7);
			break;
		case P8:
			PORTB &= ~(1 << PIN_8);
			break;
		case P9:
			PORTB &= ~(1 << PIN_9);
			break;
		case P10:
			PORTB &= ~(1 << PIN_10);
			break;
		case P11:
			PORTB &= ~(1 << PIN_11);
			break;
		case P12:
			PORTB &= ~(1 << PIN_12);
			break;
		case P13:
			PORTB &= ~(1 << PIN_13);
			break;
		default:
			break;
		}
	}
}
