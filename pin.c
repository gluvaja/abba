/*
 * pin.c
 *
 *  Created on: 31 Mar 2023
 *      Author: LENOVO
 */

#include "pin.h"
#include "timer0.h"

void pinSetValue(uint8_t port, uint8_t pin, uint8_t value)
{
	switch(port)
	{
		case PORT_B:
			if (value == HIGH)
				PORTB |= 1 << pin;
			else
				PORTB &= ~(1 << pin);
		break;

		case PORT_C:
			if (value == HIGH)
				PORTC |= 1 << pin;
			else
				PORTC &= ~(1 << pin);
		break;

		case PORT_D:
			if (value == HIGH)
				PORTD |= 1 << pin;
			else
				PORTD &= ~(1 << pin);
		break;

		default:
		break;
	}
}

void pinInit(uint8_t port, uint8_t pin, uint8_t direction)
{
	switch(port)
	{
		case PORT_B:
			if (direction == HIGH)
				DDRB |= 1 << pin;
			else
				DDRB &= ~(1 << pin);
		break;

		case PORT_C:
			if (direction == HIGH)
				DDRC |= 1 << pin;
			else
				DDRC &= ~(1 << pin);
		break;

		case PORT_D:
			if (direction == HIGH)
				DDRD |= 1 << pin;
			else
				DDRD &= ~(1 << pin);
		break;

		default:
		break;
	}
}

void pinPulsing(uint8_t port, uint8_t pin, uint8_t time)
{
	pinSetValue(port, pin, HIGH);
	timer0DelayMs(time/2);
	pinSetValue(port, pin, LOW);
	timer0DelayMs(time/2);
}

