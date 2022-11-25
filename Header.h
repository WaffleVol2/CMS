//Header.h - Define header portion of frame
//By Brendan Burdett
#pragma once

typedef struct header Header;

struct header {
	short int sid = 1;
	short int rid = 2;
	char priority = 1;
	short int seqNum;
	short int headerToggle = 1;
	long int payloadSize;		// Number of bytes in payload after this header
	char payLoadType = '0';			// 0: Text, 1: Audio, 2: Image etc.
	char encryption = '0';			// 0: None, 1: XOR,	  2: Vigenere	3: Both
	char compression = '0';			// 0: None, 1: RLE,	  2: Huffman,	3: Both
	long samples;               //Amount of Samples in audio recording
};