/* main.cpp - Client for the Tx/Rx Program
 * Author: Michael A. Galle
 *
 */

#include <Windows.h>    
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "RS232Comm.h"
#include "Queues.h"
#include "sound.h"

// Note: Comment out the Tx or Rx sections below to operate in single sided mode

// Declare constants, variables and communication parameters
//const int BUFSIZE = 140;							// Buffer size
//wchar_t COMPORT_Rx[] = L"COM7";						// COM port used for Rx (use L"COM6" for transmit program)
//wchar_t COMPORT_Tx[] = L"COM5";						// COM port used for Rx (use L"COM6" for transmit program)

// Communication variables and parameters
//HANDLE hComRx;										// Pointer to the selected COM port (Receiver)
//HANDLE hComTx;										// Pointer to the selected COM port (Transmitter)
int nComRate = 9600;								// Baud (Bit) rate in bits/second 
int nComBits = 8;									// Number of bits per frame
COMMTIMEOUTS timeout;								// A commtimeout struct variable

 // The client - A testing main that calls the functions below
int main() {
	//Message sendng/receiving
	char msgOut[MSGSIZE] = "Hi there person";							// Sent message	
	int amntInput = 0;
	link p, q;

	//recording
	extern short iBigBuf[];												// buffer
	extern long  lBigBufSize;											// total number of samples
	short* iBigBufNew = (short*)malloc(lBigBufSize * sizeof(short));		// buffer used for reading recorded sound from file

	char save;
	char replay;
	char c;																// used to flush extra input
	FILE* f;

	//int for userinputs 

	int userInput, transmit, recieve, InTransmit1, InTransmit2, InRecieve1, InRecieve2, ComSettings;


	//menu interface for the messaging coded system 

	printf("=========================================================================================\n");
	printf("\nMENU FOR Coaded Messaging system\n\n");
	printf("=========================================================================================\n");
	printf("choose option	\n1.Transmit	\n2.Receive		\n3.communication settings	\n4.Exit\n");
	scanf_s("%d", &userInput);
	while (getchar() != '\n') {}

	int I = 1;
	while (I == 1) {

		if (userInput == 1) {			//transmit function menu
			system("cls");
			printf("===Welcome to the Transmit menu===\n");
			printf("\n1.Text	\n2.Audio	\n3.Exit\n");
			scanf_s("%d", &transmit);
			while (getchar() != '\n') {}

			if (transmit == 1) {
				system("cls");
				printf("===Welcome to the text transmit menu===\n");
				printf("1.Generate message	\n2.Send message	\n3.Exit\n");
				scanf_s("%d", &InTransmit1);
				while (getchar() != '\n') {}

				switch (InTransmit1) {
				case 1:
					printf("Enter message: ");
					scanf_s("%[^\n]s", msgOut, (unsigned int)sizeof(msgOut));
					while (getchar() != '\n') {}
					break;

				case 2:
					TX(nComRate, nComBits, timeout, msgOut);
					break;

				case 3:
					I = 0;
					break;
				}

			}
			else if (transmit == 2) {
				system("cls");
				printf("\nWelcome to the Audio recieve menu\n");
				printf("=======================================================\n");
#ifndef Recording
				// initialize playback and recording
				InitializePlayback();
				InitializeRecording();
#define Recording
#endif 
				printf("1.Record Audio	\n2.Play Audio	\n3.Send Audio	\n4.Load Audio	\n5.Exit\n");
				scanf_s("%d", &InTransmit2);
				while (getchar() != '\n') {}
				switch (InTransmit2) {
				case 1:
					// start recording
					RecordBuffer(iBigBuf, lBigBufSize);
					CloseRecording();

					// playback recording 
					printf("\nPlaying recording from buffer\n");
					PlayBuffer(iBigBuf, lBigBufSize);
					ClosePlayback();

					// save audio recording  
					printf("Would you like to save your audio recording? (y/n): ");
					scanf_s("%c", &save, 1);
					while ((c = getchar()) != '\n' && c != EOF) {}								// Flush other input
					if ((save == 'y') || (save == 'Y')) {
						// Open input file 
						fopen_s(&f, "M:\\PROG 71985\\Project2\\recording.dat", "wb");
						if (!f) {
							printf("unable to open %s\n", "M:\\PROG 71985\\Project2\\recording.dat");
							return 0;
						}
						printf("Writing to sound file ...\n");
						fwrite(iBigBuf, sizeof(short), lBigBufSize, f);
						fclose(f);
					}
					break;

				case 2:
					// playback recording 
					printf("\nPlaying recording from buffer\n");
					PlayBuffer(iBigBuf, lBigBufSize);
					ClosePlayback();
					break;

				case 3:

					break;

				case 4:
					// replay audio recording from file -- read and store in buffer, then use playback() to play it
					printf("Would you like to replay the saved audio recording from the file? (y/n): ");
					scanf_s("%c", &replay, 1);
					while ((c = getchar()) != '\n' && c != EOF) {}								// Flush other input
					if ((replay == 'y') || (replay == 'Y')) {
						//Open input file 
						fopen_s(&f, "M:\\PROG 71985\\Project2\\recording.dat", "rb");
						if (!f) {
							printf("unable to open %s\n", "M:\\PROG 71985\\Project2\\recording.dat");
							return 0;
						}
						printf("Reading from sound file ...\n");
						fread(iBigBufNew, sizeof(short), lBigBufSize, f);				// Record to new buffer iBigBufNew
						fclose(f);
						InitializePlayback();
						printf("\nPlaying recording from saved file ...\n");
						PlayBuffer(iBigBufNew, lBigBufSize);
						ClosePlayback();
					}
					break;

				case 5:
					I = 0;
					break;
				}
			}
			else if (transmit == 3) {
				I = 0;			//Exit case
			}
		}



		else if (userInput == 2) {				//recieve menu

			system("cls");
			printf("\n===Welcome to the recieve menu===\n");
			printf("1.Text	\n2.Audio \n3.Exit\n");
			scanf_s("%d", &recieve);
			while (getchar() != '\n') {}

			if (recieve == 1) {
				system("cls");
				printf("1.View Text	\n2.Rx	\n3.Exit\n");
				scanf_s("%d", &InRecieve1);
				while (getchar() != '\n') {}
				switch (InRecieve1) {
				case 1:

					break;

				case 2:
					RX(nComRate, nComBits, timeout);
					break;

				case 3:
					I = 0;
					break;
				}
			}
			else if (recieve == 2) {
				system("cls");
				printf("1.View Audio	\n2.Rx	\n3.Exit\n");
				scanf_s("%d", &InRecieve2);
				while (getchar() != '\n') {}
				switch (InRecieve2) {
				case 1:

					break;

				case 2:

					break;

				case 3:
					I = 0;
					break;
				}
			}
			else if (recieve == 3) {		//Exit case
				I = 0;
			}
		}



		else if (userInput == 3) {			 //communication settings menu
			system("cls");
			printf("\n=====setting menu======\n");
			printf("1.Bit rate	\n2.comm/ttys port	\n3.Rx ID	\n4.ENCRYPTION	\n5.COMPRESSION	\n6.TIMEOUT	\n7.OPTIONS 	\n8.Exit\n");
			scanf_s("%d", &ComSettings);
			while (getchar() != '\n') {}
			switch (ComSettings) {
			case 1:

				break;

			case 2:

				break;

			case 3:

				break;

			case 4:

				break;

			case 5:

				break;

			case 6:

				break;

			case 7:

				break;

			case 8:
				I = 0;
				break;
			}
		}

		else if (userInput == 4) {			//Exit case
			I = 0;
		}
	}
	/////////////////////////////////////////////////////////EXPERIMENTING/////////////////////////////////////////////////////////

	//Queue menu
#ifndef Queue
	InitQueue();
#define Queue
#endif 
	//////////////////
	////adding to queue | To be used when sending multiple messages or files
	printf("How many messages would you like send? ");
	scanf_s("%d", &amntInput);
	for (int i = 0; i < amntInput; i++) {
		p = (link)malloc(sizeof(Node));
		p->Data.sid = i;
		AddToQueue(p);
	}
	////
	///////////////



	/*
	///////////////////////////////////////////WIP///////////////////////

	//traverse test forward
	printf("\nTraversing list in forward direction gives...\n");
	traverse(returnHead(), visit);
	printf("\n**********************************************************************\n");
	//backward
	printf("\nTraversing list in reverse direction gives...\n");
	traverseR(returnHead(), visit);
	printf("\n**********************************************************************\n");

	//Testing delete
	Item v;
	v.sid = 7;
	deleteR(returnHead(), returnHead()->pNext, v);
	//Testing delete that is non exsistant
	v.sid = 13;
	deleteR(returnHead(), returnHead()->pNext, v);

	while (!IsQueueEmpty()) {							//DeQueue the entire function.
		q = DeQueue();
		printf("\nSID of Node is: %d", q->Data.sid);
	}

	printf("\nThe number of node in the queue is: %d\n", count(returnHead())); //testing they dequeued, should be 0

	////////////////////////////////////////////////////////////SOUND//////////////////////////////////////////////////////////////


	printf("\n");
	system("pause");



	return(0);
*/
}
	/*
	// Set up both sides of the comm link
	initPort(&hComRx, COMPORT_Rx, nComRate, nComBits, timeout);	// Initialize the Rx port
	Sleep(500);
	initPort(&hComTx, COMPORT_Tx, nComRate, nComBits, timeout);	// Initialize the Tx port
	Sleep(500);

	// Transmit side 
	char msgOut[] = "Hi there person";							// Sent message	
	outputToPort(&hComTx, msgOut, strlen(msgOut)+1);			// Send string to port - include space for '\0' termination
	Sleep(500);													// Allow time for signal propagation on cable 

	
	// Receive side  
	char msgIn[BUFSIZE];
	DWORD bytesRead;
	bytesRead = inputFromPort(&hComRx, msgIn, BUFSIZE);			// Receive string from port
	printf("Length of received msg = %d", bytesRead);
	msgIn[bytesRead] = '\0';
	printf("\nMessage Received: %s\n\n", msgIn);				// Display message from port
	

	// Tear down both sides of the comm link
	purgePort(&hComRx);											// Purge the Rx port
	purgePort(&hComTx);											// Purge the Tx port
	CloseHandle(hComRx);										// Close the handle to Rx port 
	CloseHandle(hComTx);										// Close the handle to Tx port 
	
	system("pause");
}
*/