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

void printmenu(void){
	printf("**************************************************  \n");
	printf("Der Geldautomat der Bank 007  \n");
	printf("\n**************************************************  \n");
	printf("Bitte schieben Sie Ihre Karte ein (KtoNr eingeben)  \n");
}

void printPIN(void){
	printf("PIN drei mal falsch eingegeben\n");
	printf("Vorgang wird abgebrochen\n");
}

void printAuszahlung(void){
	printf("\n");
	printf("Der oben angezeigte Betrag wird Ihnen ausgezahlt\n");
	printf("Auf Wiedersehen\n");
}

int pinEingabe(void){
	int _pin;
	printf("Geben Sie Ihren PIN ein\n");
	scanf("%d", &_pin);
	printf("eingelesene PIN : %d\n", _pin);

	return _pin;
}


int main() {
	// lokale Variablen definieren
	int ktoNr;
	int temp = 0;
	int Vorgang;
	int n, i;
	int scheine[7] = { 500, 200, 100, 50, 20, 10, 5 };

	// Endlosschleife
	while (1) {
		// das Menü
		printmenu();
		// Einlesen der Kontonummer
		scanf("%d", &ktoNr);

		// Überprüfung der Kontonummer (=1234)
		if (ktoNr == 1234) {
			temp = 0;

			// Eine Möglichkeit der PIN-Abfrage
			// hier Lösung mit for()-Schleife
			for (temp = 0; temp < 3; temp++) {
				if (pinEingabe() == 111) {
					printf("Ihr PIN ist gültig\n");
					// Scheife beenden
					break;
				} else {
					printf("PIN falsch eingegeben\n");
				}
			}

			//Beim dreimaligem PIN Fehlversuch = Abbruch
			if (temp > 3) {
				printPIN();
			} else {
				printf("PIN ist OK\n");
				//Auswahl wie der Vorgang weiter gehen soll
				printf("Vorgang 1: abbrechen oder 2: fortfahren\n");
				scanf("%d", &Vorgang);
				// Bei 1 = Abbruch
				if (Vorgang == 1) {
					printf("Der Vorgang wird nun abgebrochen\n");
				}	//Bei 2 = Betrag angeben
				if (Vorgang == 2) {
					printf("Geben Sie den Betrag an: \n");
					scanf("%d", &n);
					//Scheinauswahl
					for (i = 0; i < 7; i++) {
						if (n / scheine[i] != 0)
							printf("%d x %d\t", n / scheine[i], scheine[i]);
						n %= scheine[i];
					}	//Der Betrag wird ausgezahlt
						printAuszahlung();
				}
			}

		}

	}   // end of while(1)

	return 0;
}	// ENDE DES HAUPTPROGRAMMS

