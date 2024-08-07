#include <Windows.h>    // Includes the functions for serial communication via RS232
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Menu.h"
#include "RS232Comm.h"
//#include "Queues.h"
#include "sound.h"
#include "Settings.h"
#include "RLE.h"
#include "FileRead.h"

link fileMsg = (link)malloc(sizeof(Node));

link in = (link)malloc(sizeof(Node));			//Message in
link compressed = (link)malloc(sizeof(Node));	//Compressed message out
link decompress = (link)malloc(sizeof(Node));	//Decompressed message


int CMDMENU;				//User Command

// Declare constants, variables and communication parameters
const int BUFSIZE = 140;							// Buffer size
wchar_t COMPORT_Rx[] = L"COM4";						// COM port used for Rx 
wchar_t COMPORT_Tx[] = L"COM4";						// COM port used for Tx 
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

char msgOut[] = "\nHi there this is a great message for you\n"; 	// Payload for text
short audioBuf[SAMPLES_SEC * RECORD_TIME];							// Payload for audio 

int mainMenu() {

	///////////////////////////////////DEBUG/////////////////////////////////
	txHeader.sid = 1;
	txHeader.rid = 2;
	txHeader.payloadSize = strlen(msgOut) + 1;				// Flexible payload size - Send size of payload inside header (payload can be anything) and enough memory will be malloc'd in the receive function
	txHeader.compression = '0';									// None
	txHeader.encryption = '0';									// None
	txHeader.payLoadType = '1';									// Text
	

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
		while (getchar() != '\n') {}
	}
	free(rxPayload);
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
		while (getchar() != '\n') {}
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
		while (getchar() != '\n') {}
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
		while (getchar() != '\n') {}
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
		while (getchar() != '\n') {}
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
		while (getchar() != '\n') {}
	}
}

//TEXT
int customMessage() {
	custMsg();
	return(0);
}

int generatFromFile() {
	getMsgFile(&fileMsg);
	printf("Your message is: %s", fileMsg->Data.message);
	return(0);
}

//AUDIO
int record() {
	recording();
	audioApply(audioBuf);
	return(0);
}

int loadFromFile() {
	filePlayback();
	audioApply(audioBuf);
	return(0);
}

int audioSend() {
	TX(&txHeader, audioBuf, &hComTx, COMPORT_Tx, nComRate, nComBits, timeout);
	return(0);
}


//RECEIVE
int receiverStation() {
	bytesRead = RX(&rxHeader, &rxPayload, &hComRx, COMPORT_Rx, nComRate, nComBits, timeout);		// Pass pointer to rxPayload so can access malloc'd memory inside the receive function from main()
	
	printf("\nMessage received from %d to %d", rxHeader.rid, rxHeader.sid);
	
	switch (rxHeader.payLoadType) {
	case '0'://TEXT
		if (rxHeader.compression == '1') {
			compressed->Data.size = RLDecode((unsigned char*)rxPayload, in->Data.size, decompress->Data.message, in->Data.size, '@'); //compresses the message with RLE
			printf("\nThe text message received is %s", (char*)(compressed->Data.message));
		}
		else {
			printf("\nThe text message received is %s", (char*)rxPayload);
		}
		Sleep(2000);
		return(0);
	case '1'://AUDIO
		audioApply((short *)rxPayload);
		playback();
		fileSaveAudio();
		return(0);
	case '2'://OTHER
		return(0);
	}
}

int debug() {
	while (getchar() != '\n') {}
	while (1) {
		system("CLS");
		printf("What would you like to configure? \n[1] Header ON/OFF | [0] Exit\n");
		CMDMENU = getchar();
		switch (CMDMENU) {
		case '1':
			headerToggle(&txHeader);
			rxHeader.payloadSize = sizeof(char[1000]);
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

	if (txHeader.compression == '1') {
		compressed->Data.size = RLEncode((unsigned char*)msgOut, in->Data.size, compressed->Data.message, in->Data.size, '@'); //compresses the message with RLE
		TX(&txHeader, (char*)(compressed->Data.message), &hComTx, COMPORT_Tx, nComRate, nComBits, timeout);
	}
	else {
		TX(&txHeader, msgOut, &hComTx, COMPORT_Tx, nComRate, nComBits, timeout);
	}
	return;
}