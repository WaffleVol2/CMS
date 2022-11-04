/* main.cpp - Client for the Tx/Rx Program
 * Author: Michael A. Galle
 *
 */

#include <Windows.h>    
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "RS232Comm.h"

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
	char msgOut[] = "Hi there person";							// Sent message	

	while (1) {
		printf("Would you like to transmit [1] receive [2] Send a custom message (non functional WIP) [3]: ");
		char userInput = getchar();
		if (userInput == '1') {
			TX(nComRate, nComBits, timeout, msgOut);
			break;
		}
		else if (userInput == '2') {
			RX(nComRate, nComBits, timeout);
			break;
		}
		else if (userInput == '3') { //function will collect a user message and then call the TX function with the message being passed
			Sleep(500);
			printf("Enter message: "); 
			fgets(msgOut, sizeof(msgOut), stdin);
			printf("MESSAGE: %s", msgOut);
			TX(nComRate, nComBits, timeout, msgOut);
			break;
		}
		else {
			printf("error, please try again.");
		}
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
	*/
	system("pause");
}