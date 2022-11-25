#include <Windows.h>    // Includes the functions for serial communication via RS232
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Menu.h"
#include "RS232Comm.h"
#include "Queues.h"
#include "sound.h"
#include "Settings.h"

int CMDMENU;				//User Command

// Declare constants, variables and communication parameters
const int BUFSIZE = 140;							// Buffer size
wchar_t COMPORT_Rx[] = L"COM8";						// COM port used for Rx 
wchar_t COMPORT_Tx[] = L"COM6";						// COM port used for Tx 
HANDLE hComRx;										// Pointer to the selected COM port (Receiver)
HANDLE hComTx;										// Pointer to the selected COM port (Transmitter)
int nComRate = 9600;								// Baud (Bit) rate in bits/second 
int nComBits = 8;									// Number of bits per frame
COMMTIMEOUTS timeout;								// A commtimeout struct variable

char selection;														// Tx or Rx (can run two instances of this program - double click the exe file)
Header txHeader;													// Header transmitted 
Header rxHeader;													// Header received
void* rxPayload = NULL;												// Received payload (buffer) - void so it can be any data type
DWORD bytesRead;													// Number of bytes received
char msgOut[] = "\nHi there this is a great message for you\n"; 	// Payload is a text message in this example but could be any data	

int mainMenu() {
	while (getchar() != '\n') {}
	while (1) {
		system("CLS");
		printf("What would you like to do? \n[1] Transmit | [2] Receive | [3] Settings | [0] Exit\n");
		CMDMENU = getchar();
		switch (CMDMENU) {
		case '1':
			transmit();
			break;
		case '2':
			receive();
			break;
		case '3':
			settings();
			break;
		case '0':
			return(0);
		default:
			printf("Error, Please try again.\n");
			Sleep(500);
			break;
		}
	}
}

//MAIN
int transmit() {
	while (getchar() != '\n') {}
	while (1) {
		system("CLS");
		printf("What would you like to transmit? \n[1] Text | [2] Audio | [0] Exit\n");
		CMDMENU = getchar();
		switch (CMDMENU) {
		case '1':
			text();
			break;
		case '2':
			audio();
			break;
		case '0':
			return(0);
		default:
			printf("Error, Please try again.\n");
			Sleep(500);
			break;
		}
	}
}

int receive() {
	while (getchar() != '\n') {}
	while (1) {
		system("CLS");
		printf("What would you like to do? \n[1] Receive Data | [2] View Stored Data | [0] Exit\n");
		CMDMENU = getchar();
		switch (CMDMENU) {
		case '1':
			receiverStation();
			break;
		case '2':
			viewStored();
			break;
		case '0':
			return(0);
		default:
			printf("Error, Please try again.\n");
			Sleep(500);
			break;
		}
	}
}

int settings() {
	while (getchar() != '\n') {}
	while (1) {
		system("CLS");
		printf("What would you like to configure? \n[1] Compression | [2] Encryption | [3] Comrate | [4] RX Port | [5] TX Port | [6] Review Configuration | [7] Save Preset | [8] Debug | [0] Exit\n");
		CMDMENU = getchar();
		switch (CMDMENU) {
		case '1':
			compressionConfig(&txHeader);
			break;
		case '2':
			encryptionConfig(&txHeader);
			break;
		case '3':
			comrateConfig();
			break;
		case '4':
			portRXConfig();
			break;
		case '5':
			portTXConfig();
			break;
		case '6':
			view(&txHeader);
			break;
		case '7':
			savePreset();
			break;
		case '8':
			debug();
			break;
		case '0':
			return(0);
			break;
		default:
			printf("Error, Please try again.\n");
			Sleep(500);
			break;
		}
	}
}

//TRANSMIT
int text() {
	while (getchar() != '\n') {}
	while (1) {
		system("CLS");
		printf("What would you like to do? \n[1] Send Custom Message | [2] Load Message From File | [0] Exit\n");
		CMDMENU = getchar();
		switch (CMDMENU) {
		case '1':
			customMessage();
			break;
		case '2':
			generatFromFile();
			break;
		case '0':
			return(0);
		default:
			printf("Error, Please try again.\n");
			Sleep(500);
			break;
		}
	}
}

int audio() {
	while (getchar() != '\n') {}
	while (1) {
		system("CLS");
		printf("What would you like to do? \n[1] Record | [2] Load Audio From File | [3] Send Audio | [0] Exit\n");
		CMDMENU = getchar();
		switch (CMDMENU) {
		case '1':
			record();
			break;
		case '2':
			loadFromFile();
			break;
		case '3':
			audioSend();
			break;
		case '0':
			return(0);
		default:
			printf("Error, Please try again.\n");
			Sleep(500);
			break;
		}
	}
}

//TEXT
int customMessage() {
	custMsg();
	return(0);
}

int generatFromFile() {
	while (getchar() != '\n') {}
	while (1) {
		system("CLS");
		printf("\n");
		CMDMENU = getchar();
		switch (CMDMENU) {
		case '0':

			break;
		case '1':

			break;
		case '2':

			break;
		case '3':

			break;
		case '4':

			break;
		case '5':

			break;
		case '6':

			break;
		case '7':

			break;
		case '8':

			break;
		default:
			Sleep(500);
			break;
		}
	}
}

//AUDIO
int record() {
	while (getchar() != '\n') {}
	while (1) {
		system("CLS");
		printf("\n");
		CMDMENU = getchar();
		switch (CMDMENU) {
		case '0':

			break;
		case '1':

			break;
		case '2':

			break;
		case '3':

			break;
		case '4':

			break;
		case '5':

			break;
		case '6':

			break;
		case '7':

			break;
		case '8':

			break;
		default:
			Sleep(500);
			break;
		}
	}
}

int loadFromFile() {
	while (getchar() != '\n') {}
	while (1) {
		system("CLS");
		printf("\n");
		CMDMENU = getchar();
		switch (CMDMENU) {
		case '0':

			break;
		case '1':

			break;
		case '2':

			break;
		case '3':

			break;
		case '4':

			break;
		case '5':

			break;
		case '6':

			break;
		case '7':

			break;
		case '8':

			break;
		default:
			Sleep(500);
			break;
		}
	}
}

int audioSend() {
	while (getchar() != '\n') {}
	while (1) {
		system("CLS");
		printf("\n");
		CMDMENU = getchar();
		switch (CMDMENU) {
		case '0':

			break;
		case '1':

			break;
		case '2':

			break;
		case '3':

			break;
		case '4':

			break;
		case '5':

			break;
		case '6':

			break;
		case '7':

			break;
		case '8':

			break;
		default:
			Sleep(500);
			break;
		}
	}
}


//RECEIVE
int receiverStation() {
	bytesRead = RX(&rxHeader, &rxPayload, &hComRx, COMPORT_Rx, nComRate, nComBits, timeout);		// Pass pointer to rxPayload so can access malloc'd memory inside the receive function from main()
	return(0);
}

int debug() {
	while (getchar() != '\n') {}
	while (1) {
		system("CLS");
		printf("What would you like to configure? \n[1] Header ON/OFF | [2] Encryption | [3] Comrate | [4] RX Port | [5] TX Port | [6] Review Configuration | [7] Save Preset | [8] Debug | [0] Exit\n");
		CMDMENU = getchar();
		switch (CMDMENU) {
		case '1':
			headerToggle(&txHeader);
			break;
		case '2':

			break;
		case '3':

			break;
		case '4':

			break;
		case '5':

			break;
		case '6':

			break;
		case '7':

			break;
		case '8':

			break;
		case '0':
			return(0);
			break;
		default:
			printf("Error, Please try again.\n");
			Sleep(500);
			break;
		}
	}
}

int viewStored() {
	return(0);
}

void custMsg() {
	system("CLS");
	while (getchar() != '\n') {}
	printf("Enter message: ");
	scanf_s("%[^\n]s", msgOut, (unsigned int)sizeof(msgOut));
	while (getchar() != '\n') {}

	TX(&txHeader, msgOut, &hComTx, COMPORT_Tx, nComRate, nComBits, timeout);
}