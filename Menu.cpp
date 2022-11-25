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
Header RXHeader;
void* rxPayload = NULL;		// Received payload (buffer) - void so it can be any data type

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
			compressionConfig();
			break;
		case '2':
			encryptionConfig();
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
			view();
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
	RX(&rxPayload, &RXHeader);
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
			headerToggle();
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
