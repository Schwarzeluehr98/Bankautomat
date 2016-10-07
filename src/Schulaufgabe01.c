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

enum x {
	Abbruch = 1, Betrageingabe = 2
};

enum z {
	Geldscheinwahl = 1, Betrag
};

int wahl(void) {
	int Moeglichkeit;
	scanf("%d", &Moeglichkeit);
	return Moeglichkeit;
}

int geldscheinWahl(void) {
	int Schein;
	printf("Geben sie den Schein an\n");
	scanf("%d", &Schein);

	switch (Schein) {
	case 1:
		printf("Sie haben den 500€ Schein gewählt\n");
		break;
	case 2:
		printf("Sie haben den 200€ Schein gewählt\n");
		break;
	case 3:
		printf("Sie haben den 100€ Schein gewählt\n");
		break;
	case 4:
		printf("Sie haben den 50€ Schein gewählt\n");
		break;
	case 5:
		printf("Sie haben den 20€ Schein gewählt\n");
		break;
	case 6:
		printf("Sie haben den 10€ Schein gewählt\n");
		break;
	case 7:
		printf("Sie haben den 5€ Schein gewählt\n");
		break;
	default:
		printf(
				"Bei erneutem Versuch bitte eine der möglichen Angaben auswählen\n");
	}
	return 0;
}

int main() {

	// lokale Variablen definieren
	int ktoNr;
	enum x Vorgang;
	enum z Moeglichkeit;

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
			Vorgang = auswahl();
			// Bei 1 = Abbruch
			if (Vorgang == Abbruch) {
				printf("Der Vorgang wird nun abgebrochen\n");
				continue;
			}
			//Bei 2 = Betrag angeben
			if (Vorgang == Betrageingabe) {
				printf("Wahl der weiteren Vorgehensweise:\n"
						"1 = Geldscheinwahl\n"
						"2 = Betrag auswählen \n");
			}
			// Geldscheinauswahl
			Moeglichkeit = wahl();
			if (Moeglichkeit == Geldscheinwahl) {
				printf("Wahl der Geldscheine\n"
						"1 = 500€\n"
						"2 = 200€\n"
						"3 = 100€\n"
						"4 = 50€\n"
						"5 = 20€\n"
						"6 = 10€\n"
						"7 = 5€\n");
				geldscheinWahl();
			}
			//Betragangabe
			if (Moeglichkeit == Betrag) {
				printf("Geben Sie nun den gewünschten Betrag ein\n");
				geldscheinAusgabe();
			}
			//Erfolgreiche Auszahlung
			printAuszahlung();
		} // end of if
	}   // end of while(1)
	return 0;
}	// ENDE DES HAUPTPROGRAMMS
