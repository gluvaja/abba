/**
 * @file pin.h
 * @brief Funkcije za upravljanje pinovima
 * @author ne znam
 * @date 00-00-0000
 */
#include <avr/io.h>

#ifndef PIN_H_
#define PIN_H_

/// Makro za postavljanje visoke vrednosti na pin
#define HIGH 1
/// Makro za postavljanje niske vrednosti na pin
#define LOW 0

/// Makro koji oznacava da je u pin u pitanju izlazni
#define OUTPUT 1
/// Makro koji oznacava da je u pin u pitanju ulazni
#define INPUT 0

/// Makro za oznacavanje porta B
#define PORT_B 0
/// Makro za oznacavanje porta C
#define PORT_C 1
/// Makro za oznacavanje porta D
#define PORT_D 2

/// Makro za oznacavanje pina za diodu
#define DIODE_PIN 5

/**
 * pinSetValue - Funkcija koja postavlja visoku ili nisku vrednost na specificirani pin
 * @param port - promenljiva tipa uint8_t - oznacava port koji se koristi
 * @param pin - promenljiva tipa uint8_t - oznacava pin koji se koristi
 * @param value - promenljiva tipa uint8_t - oznacava vrednost koja ce se postaviti na pin
 * @return nema povratnu vrednost
 */
void pinSetValue(uint8_t port, uint8_t pin, uint8_t value);
/**
 * pinInit - Funkcija koja inicijalizuje specificirani pin i odredjuje da li ce biti ulazni ili izlazni
 * @param port - promenljiva tipa uint8_t - oznacava port koji se koristi
 * @param pin - promenljiva tipa uint8_t - oznacava pin koji treba da se inicijalizuje
 * @param direction - promenljiva tipa uint8_t - odredjuje da li ce pin biti ulazni ili izlazni
 * @return nema povratnu vrednost
 */
void pinInit(uint8_t port, uint8_t pin, uint8_t direction);
/**
 * pinPulsing - Funkcija koja postavlja visoku, a zatim nisku vrednost (impuls) na specificirani pin
 * @param port - promenljiva tipa uint8_t - oznacava port koji se koristi
 * @param pin - promenljiva tipa uint8_t - oznacava pin koji se koristi
 * @param time - promenljiva tipa uint8_t - oznacava vreme trajanja impulsa
 * @return nema povratnu vrednost
 */
void pinPulsing(uint8_t port, uint8_t pin, uint8_t time);


#endif /* PIN_H_ */
