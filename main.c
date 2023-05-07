/**
 * @file main.c
 * @brief Program koji detektuje podstring "abba" u datom stringu i ispisuje indekse na kojima je detektovao pocetke tih podstringova
 * @author Luka Gluvajić
 * @date 06-05-2023
 * @version 1.0
 */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "timer0.h"
#include "usart.h"

/**
 * main - Prolazim kroz string koristeci masinu stanja; ako je naisla na slovo a, pamti indeks na kom se ono nalazi i prelazi u stanje A, ocekujuci dalje slovo b; kad naidje na njega, prelazi u stanje B1, kako bi naznacilo da je naislo na prvo slovo b u podstringu "abba", ocekuje drugo "b" po redu; kad naidje na njega, prelazi u stanje B2 i ocekuje poslednje slovo, "a"; ako naidje na njega, upisuje prvobitni indeks u niz indeksa koji ce se kasnije ispisivati, i dalje ocekuje opet slovo "b"; ako se bilo koji od navedenih uslova nije ispunio u bilo kom trenutku, program nastavlja sa daljim radom, prolazeci kroz string, dok opet ne naidje na "a".
 * @param ulaz - promenljiva tipa int8_t - string u koji se smesta niz karaktera sa serijskog ulaza
 * @param i - promenljiva tipa int - brojac za prolazak kroz string masinom stanja, dalje se koristi za ispis indeksa
 * @param indeks - promenljiva tipa int - promenljiva u koju se smesta indeks na kom (potencijalno) pocinje podstring "abba"
 * @param indeksi - promenljiva tipa int8_t - niz u koji se smestaju indeksi na kojima pocinju podstringovi "abba"
 * @param broj_indeksa - promenljiva tipa int - promenljiva kojom program prolazi kroz niz indeksi
 * @param buffer - promenljiva tipa int8_t - buffer za atoi funkciju prilikom ispisa indeksa
 * @return nema povratnu vrednost
 */
int16_t main()
{
	usartInit(9600);
	timer0InterruptInit();

	int8_t ulaz[65];
	int i = 0;
	int indeks;
	int8_t indeksi[10];
	int broj_indeksa = 0;
	int8_t buffer[5];

	enum state_t {X, A1, B1, B2};
	enum state_t state = X;

	while(1)
	{
		usartPutString("Ulaz: ");
		while(!(usartAvailable()));
		timer0DelayMs(300);
		usartGetString(ulaz);
		usartPutString(ulaz);
		usartPutString("\r\n");

		while(ulaz[i] != 0)
		{
			switch(ulaz[i])
			{
				case 'a':
					if(state == X || state == B1 || state == A1)
					{
						indeks = i;
						i++;
						state = A1;
					}
					else if(state == B2)
					{
						indeksi[broj_indeksa] = indeks;
						indeks = i;
						broj_indeksa++;
						state = A1;
						i++;
					}
					break;
				case 'b':
					if(state == A1)
					{
						state = B1;
						i++;
					}
					else if(state == B1)
					{
						state = B2;
						i++;
					}
					else
					{
						state = X;
						i++;
					}
					break;
				default:
					i++;
					state = X;
					break;
			}
		}
		indeksi[broj_indeksa] = 0;
		usartPutString("Indeksi: ");
		for(i = 0; i < broj_indeksa; i++)
		{
			itoa(indeksi[i], buffer, 10);
			usartPutString(buffer);
			if(indeksi[i+1] != 0)
			{
				usartPutString(", ");
			}
			indeksi[i] = 0;
		}
		usartPutString("\r\n");
		strcpy(ulaz, "");
		broj_indeksa = 0;
		state = X;
	}
	return 0;
}
