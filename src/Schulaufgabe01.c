/*
 ============================================================================
 Name        : Schulaufgabe01.c
 Author      : Schwarzelühr
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printMenu(void) {
	printf("**************************************************  \n");
	printf("Der Geldautomat der Bank 007  \n");
	printf("\n**************************************************  \n");
	printf("Bitte schieben Sie Ihre Karte ein (KtoNr eingeben)  \n");
}

void printPINabbruch(void) {
	printf("PIN drei mal falsch eingegeben\n");
	printf("Vorgang wird abgebrochen\n");
}

void printAuszahlung(void) {
	printf("\n");
	printf("Der oben angezeigte Betrag wird Ihnen ausgezahlt\n");
	printf("Auf Wiedersehen\n");
}

int pinEinlesen(void) {
	int _pin;
	printf("Geben Sie Ihren PIN ein\n");
	scanf("%d", &_pin);
	printf("eingelesene PIN : %d\n", _pin);

	return _pin;
}

bool gueltigerPIN(void) {
	int _temp;
	for (_temp = 0; _temp < 3; _temp++) {
		if (pinEinlesen() == 111) {
			printf("Ihr PIN ist gültig\n");
			return true;
		} else {
			printf("Ungültiger PIN\n");
		}
	}
	printPINabbruch();
	return false;
}

void geldscheinAusgabe(void) {
	int n, i;
	int scheine[7] = { 500, 200, 100, 50, 20, 10, 5 };

	scanf("%d", &n);
	for (i = 0; i < 7; i++) {
		if (n / scheine[i] != 0)
			printf("%d x %d\t", n / scheine[i], scheine[i]);
		n %= scheine[i];
	}
}

int auswahl(void) {
	int Vorgang;
	printf("Vorgang 1: abbrechen oder 2: fortfahren\n");
	scanf("%d", &Vorgang);
	return Vorgang;
}

int main() {

	// lokale Variablen definieren
	int ktoNr;
	int Vorgang;

	// Endlosschleife
	while (1) {
		// das Menü
		printMenu();
		// Einlesen der Kontonummer
		scanf("%d", &ktoNr);
		// Überprüfung der Kontonummer (=1234)
		if (ktoNr == 1234) {
			if (gueltigerPIN() == false)
				continue;
			//Auswahl des weiteren Vorgangs
			Vorgang=auswahl();
			// Bei 1 = Abbruch
			if (Vorgang == 1) {
				printf("Der Vorgang wird nun abgebrochen\n");
				continue;
			}	//Bei 2 = Betrag angeben
			if (Vorgang == 2) {
				printf("Geben Sie den Betrag an: \n");
			}
			// Geldscheinausgabe
			geldscheinAusgabe();
			printAuszahlung();
		}
	}   // end of while(1)
	return 0;
}	// ENDE DES HAUPTPROGRAMMS

