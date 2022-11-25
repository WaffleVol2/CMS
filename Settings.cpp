/* Settigns.cpp - Implementation for the settings
 * By: Brendan Burdett
 *
 */
#include <Windows.h>   
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Header.h"
#include "settings.h"

settingsConfigured settings;
int CMD;			        	//User Command

void compressionConfig(Header* txHeader) {
	while (getchar() != '\n') {}
	while(1) {
		system("CLS");
		printf("What type of compression would you like? \n[0] None | [1] RLE | [2] Huffman | [3] Both \n");
		CMD = getchar();
		if (CMD == '0' || CMD == '1' || CMD == '2' || CMD == '3') {
			
			txHeader->compression = CMD;
			return;
		}
		else {
			printf("Error, Please try again.");
		}
		Sleep(1000);
	}															
}

void encryptionConfig(Header* txHeader) {
	while (getchar() != '\n') {}
	while (1) {
		system("CLS");
		printf("What type of encryption would you like? \n[0] None | [1] XOR | [2] Vigenere | [3] Both \n");
		CMD = getchar();
		if (CMD == '0' || CMD == '1' || CMD == '2' || CMD == '3') {
			txHeader->encryption = CMD;
			return;
		}
		else {
			printf("Error, Please try again.");
		}
		Sleep(1000);
	}
}

void comrateConfig() {
	while (getchar() != '\n') {}
	while (1) {
		system("CLS");
		printf("What comrate would you like? \n[0] 110 | [1] 300 | [2] 1200 | [3] 2400 | [4] 4800 | [5] 9600 | [6] 19200 | [7] 38400 | [8] 57600 | [9] 115200\n");
		CMD = getchar();
		switch (CMD) {
		case '0':
			settings.comrate = 110;
			return;
		case '1':
			settings.comrate = 300;
			return;
		case '2':
			settings.comrate = 1200;
			return;
		case '3':
			settings.comrate = 2400;
			return;
		case '4':
			settings.comrate = 4800;
			return;
		case '5':
			settings.comrate = 9600;
			return;
		case '6':
			settings.comrate = 19200;
			return;
		case '7':
			settings.comrate = 38400;
			return;
		case '8':
			settings.comrate = 57600;
			return;
		case '9':
			settings.comrate = 115200;
			return;
		default:
			printf("Error, Please try again.");
			Sleep(1000);
			break;
		}
	}
}

void portRXConfig() {
	while (getchar() != '\n') {}
		while (1) {
			system("CLS");
			printf("What com port would you like to use? \n[0] COM1 | [1] COM2 | [2] COM3 | [3] COM4 | [4] COM5 | [5] COM6 | [6] COM7 | [7] COM8 | [8] COM9\n");
			CMD = getchar();
			switch (CMD) {
			case '0':
				//wchar_t COMPORT_Rx[] = L"COM1";						// COM port used for Rx 
				break;
			case '1':
			//	wchar_t COMPORT_Rx[] = L"COM2";						// COM port used for Rx 
				break;
			case '2':
				//wchar_t COMPORT_Rx[] = L"COM3";						// COM port used for Rx 
				break;
			case '3':
				//wchar_t COMPORT_Rx[] = L"COM4";						// COM port used for Rx 
				break;
			case '4':
				//wchar_t COMPORT_Rx[] = L"COM5";						// COM port used for Rx 
				break;
			case '5':
				//wchar_t COMPORT_Rx[] = L"COM6";						// COM port used for Rx 
				break;
			case '6':
				//wchar_t COMPORT_Rx[] = L"COM7";						// COM port used for Rx 
				break;
			case '7':
				//wchar_t COMPORT_Rx[] = L"COM8";						// COM port used for Rx 
				break;
			case '8':
				//wchar_t COMPORT_Rx[] = L"COM9";						// COM port used for Rx 
				break;
			default:
				Sleep(500);
				break;
			}
	}
}

void portTXConfig() { //Unsure how to overcome issue with wchar_t being a const
	while (getchar() != '\n') {}
		while (1) {
			system("CLS");
			printf("What com port would you like to use? \n[0] COM1 | [1] COM2 | [2] COM3 | [3] COM4 | [4] COM5 | [5] COM6 | [6] COM7 | [7] COM8 | [8] COM9\n");
			CMD = getchar();
			switch (CMD) {
			case '0':
				//wchar_t COMPORT_Tx[] = L"COM1";						// COM port used for Rx 
				break;
			case '1':
				//wchar_t COMPORT_Tx[] = L"COM2";						// COM port used for Rx 
				break;
			case '2':
				//wchar_t COMPORT_Tx[] = L"COM3";						// COM port used for Rx 
				break;
			case '3':
				//wchar_t COMPORT_Tx[] = L"COM4";						// COM port used for Rx 
				break;
			case '4':
				//wchar_t COMPORT_Tx[] = L"COM5";						// COM port used for Rx 
				break;
			case '5':
				//wchar_t COMPORT_Tx[] = L"COM6";						// COM port used for Rx 
				break;
			case '6':
				//wchar_t COMPORT_Tx[] = L"COM7";						// COM port used for Rx 
				break;
			case '7':
				//wchar_t COMPORT_Tx[] = L"COM8";						// COM port used for Rx 
				break;
			case '8':
				//wchar_t COMPORT_Tx[] = L"COM9";						// COM port used for Rx 
				break;
			default:
				Sleep(500);
				break;
			}
		}
		//Pass wchar_t to main to then pass to Transmit when called...
}

void view(Header* txHeader) {
	switch (txHeader->compression) {
	case '0':
		printf("Compression: NONE\n");
		break;
	case '1':
		printf("Compression: RLE\n");
		break;
	case '2':
		printf("Compression: HUFFMAN\n");
		break;
	case '3':
		printf("Compression: RLE AND HUFFMAN\n");
		break;
	}
	switch (txHeader->encryption) {
	case '0':
		printf("Encryption: NONE\n");
		break;
	case '1':
		printf("Encryption: XOR\n");
		break;
	case '2':
		printf("Encryption: VIRGENERE\n");
		break;
	case '3':
		printf("Encryption: XOR AND VIRGENERE\n");
		break;
	}
	printf("Comrate: %d\n", settings.comrate);
}

void savePreset() {

}

void headerToggle(Header* txHeader) {
	while (getchar() != '\n') {}
	while (1) {
		system("CLS");
		printf("Would you like the header turned on or off? \n[0] OFF | [1] ON\n");
		CMD = getchar();
		if (CMD == '1') {
			txHeader->headerToggle = 1;
			printf("The header is on");
			Sleep(1000);
			return;
		}
		else if (CMD == '0') {
			txHeader->headerToggle = 0;
			printf("The header is off");
			Sleep(1000);
			return;
		}
		else {
			printf("Error, Please try again.");
		}
		Sleep(1000);
	}
}

Header* configApply(Header* txHeader) {
	return (txHeader);
}