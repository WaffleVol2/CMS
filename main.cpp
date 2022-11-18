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


 // The client - A testing main that calls the functions below
int main() {

	int amntInput = 0;
	char msgOut[MSGSIZE];
	DWORD bytesRead;
	Header rxHeader;												// Header received
	void* rxPayload = NULL;											// Received payload (buffer) - void so it can be any data type

	printf("Enter message: ");
	scanf_s("%[^\n]s", msgOut, (unsigned int)sizeof(msgOut));
	while (getchar() != '\n') {}

	TX(msgOut, configApply());
	bytesRead = RX(&rxPayload, &rxHeader);

	printf("\nMessage recieved: %s\n", (char*)rxPayload);

	compressionConfig();
	encryptionConfig();
	comrateConfig();

	view();


	
	//Recording Related functions
#ifndef Recording
				// initialize playback and recording
	InitializePlayback();
	InitializeRecording();
#define Recording
#endif 
	recording(); //record
	playback(); //Playback audio from buffer
	filePlayback();	 //Playback audio from file

	/*
	/////////////////////////////////////////////////////////EXPERIMENTING/////////////////////////////////////////////////////////
	//Queue menu
#ifndef Queue
	InitQueue();
#define Queue
#endif 
	//////////////////
	////adding to queue | To be used when sending multiple messages or files
	printf("How many messages would you like to queue? ");
	scanf_s("%d", &amntInput);
	for (int i = 0; i < amntInput; i++) {
		//p = (link)malloc(sizeof(Node));
		//p->Data.sid = i;
		//AddToQueue(p);
	}
	////
	///////////////
	*/
}