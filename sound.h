/*	Filename: sound.h 
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
void playback();
void filePlayback();
int InitializePlayback(void);
int PlayBuffer(short *piBuf, long lSamples);
void ClosePlayback(void);

// Recording
void recording();
int InitializeRecording(void);
int	RecordBuffer(short *piBuf, long lBufSize);
void CloseRecording(void);

// Support functions for Playback functions (updated 2021)
void SetupFormat(WAVEFORMATEX* wf);			// Used by InitializePlayback()					
int WaitOnHeader(WAVEHDR* wh, char cDit);	// Used by Playbuffer()

void audioApplyTX(short* buff); //passed the needed buffer for the TX audio
void audioApplyRX(short* buff); //passed the needed buffer for the RX audio
void fileSaveAudio();             //saves the audio to the file