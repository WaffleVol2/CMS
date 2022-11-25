//RLE Compression by Brendan Burdett

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <Windows.h>    
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int RLEncode(unsigned char* in, int iInLen, unsigned char* out, int iOutMax, unsigned char cEsc) {
	unsigned char charac; // repeated character
	unsigned char output[5]; // temp buffer with room for RLE sequence
	out[0] = '\0'; // Set so can use strcat()
	int i = 0, count;
	while (i < iInLen) {
		count = 1;
		while ((in[i] == in[i + 1]) && (i < iInLen) && count <= 255) {
			charac = in[i]; // repeated character
			count++;
			i++;
		}
		if (count >= 4) { //since RLE uses 4 characters to encode. only encode if its 4 or more
			sprintf((char*)output, "%c%02x%c", cEsc, count, charac);
			strcat((char*)out, (char*)output);
		}
		if (count == 3) { // 3, 2 and 1 character counts will simply add the character unaltered to the output message
			sprintf((char*)output, "%c%c%c", charac, charac, charac);
			strcat((char*)out, (char*)output);
		};
		if (count == 2) {
			sprintf((char*)output, "%c%c", charac, charac);
			strcat((char*)out, (char*)output);
		};
		if (count < 2) {
			charac = in[i]; // non repeated character
			sprintf((char*)output, "%c", charac);
			strcat((char*)out, (char*)output);
		};
		i++; // Advance to next character
	}
	return(strlen((char*)out)); // Returns length of output
}

int RLDecode(unsigned char* in, int iInLen, unsigned char* out, int iOutMax, unsigned char cEsc) {
	int i = 0, j = 0, repeats = 0;
	unsigned char HEX[3]; // String rep of HEX number of repeats
	char charac[2]; // repeated character
	out[0] = '\0'; // To use strcat()
	for (i = 0; i < iInLen; i++) { // Build the out buffer using in buffer
		if (in[i] != cEsc) { // No RLE sequence (no repeats)
			charac[0] = in[i];
			charac[1] = '\0';
			strcat((char*)out, charac);
		}
		else { // RLE sequence (repeats encountered)
			HEX[0] = in[++i]; HEX[1] = in[++i]; HEX[2] = '\0'; // repeats string (e.g. x12 is HEX[1]=‘1’HEX[2]=’2’
			charac[0] = in[++i]; charac[1] = '\0'; // repeated char
			repeats = (int)strtol((char*)HEX, NULL, 16); // convert repeats (HEX string) to a number
			for (j = 0; j < repeats; j++) strcat((char*)out, charac);
		}
	}
		if (strlen((char*)out) > iOutMax) { printf("OVERFLOW"); return 0; }
		return(strlen((char*)out)); // Return length of output buffer on success
}