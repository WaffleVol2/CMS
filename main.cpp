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
#include "Settings.h"

// Note: Comment out the Tx or Rx sections below to operate in single sided mode

// Declare constants, variables and communication parameters
//const int BUFSIZE = 140;							// Buffer size
//wchar_t COMPORT_Rx[] = L"COM7";						// COM port used for Rx (use L"COM6" for transmit program)
//wchar_t COMPORT_Tx[] = L"COM5";						// COM port used for Rx (use L"COM6" for transmit program)

// Communication variables and parameters
//HANDLE hComRx;										// Pointer to the selected COM port (Receiver)
//HANDLE hComTx;										// Pointer to the selected COM port (Transmitter)

 // The client - A testing main that calls the functions below
int main() {
	//Message sendng/receiving

	int amntInput = 0;
	link p, q;

	//recording
	extern short iBigBuf[];												// buffer
	extern long  lBigBufSize;											// total number of samples

	//int for userinputs 

	int userInput, transmit, recieve, InTransmit1, InTransmit2, InRecieve1, InRecieve2, ComSettings;

	view();
	
	//custMsg(); //Send Custom Messages
	//RX();		//Receive
	//TX();		//Transmit

	//Recording Related functions
#ifndef Recording
				// initialize playback and recording
				InitializePlayback();
				InitializeRecording();
#define Recording
#endif 

	playback(); //Playback audio from buffer
	filePlayback();	 //Playback audio from file


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