/*
Queues.h - Interface for the queue functionality
By: Brendan B
*/
#pragma once
const int iLength = 140, latSize = 25;

typedef struct node Node;
typedef struct item Item;
typedef Node* link;

struct item {
	char message[iLength];           //Message data
	short int sid, rid, seqNum;      //sid  Sender ID || rid = receiver ID || seqNum = sequence number of the message
	char priority, later[latSize];   //Character for possible later use
};

struct node {
	link pNext;
	Item Data;
};

//Function prototypes
void InitQueue(void);
void AddToQueue(link);
int IsQueueEmpty(void);
link DeQueue(void);

//Recursive Queue Functions
link returnHead();
link deleteR(link parent, link child, Item v);
int count(link x);
void visit(link h); 
void traverse(link h, void(*visit)(link));
void traverseR(link h, void(*visit)(link));

/*	Sound
	Author: Michael Galle
	Date: Updated 2022
	Details: Interface - Contains prototypes for Windows sound API (sound recording and playback functions)
*/
#pragma once

#include <windows.h>					// Contains WAVEFORMATEX structure

// CONSTANTS - SET RECORDING TIME AND RATE
#define	DEFAULT_NSAMPLES	4000	
#define MIN_BUFSIZE			1000
#define RECORD_TIME			6		// seconds to record from mic
#define SAMPLES_SEC			8000	// number of samples per second
#define	NFREQUENCIES		96		// number of frequencies used - leave this alone


// FUNCTION PROTOTYPES
/* ************************ */
// Playback
int InitializePlayback(void);
int PlayBuffer(short* piBuf, long lSamples);
void ClosePlayback(void);

// Recording
int InitializeRecording(void);
int	RecordBuffer(short* piBuf, long lBufSize);
void CloseRecording(void);

// Support functions for Playback functions (updated 2021)
void SetupFormat(WAVEFORMATEX* wf);			// Used by InitializePlayback()					
int WaitOnHeader(WAVEHDR* wh, char cDit);	// Used by Playbuffer()
