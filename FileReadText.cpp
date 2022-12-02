#include <iostream>
#include "FileRead.h"


int getMsgFile(link* buff) {
	FILE* fP;
	errno_t err;
	char c;
	int count = -1;							 //Set to start at -1 to account for first %% in the TXT file
	link pTmp = *buff;

	if ((err = fopen_s(&fP, "Data.txt", "r")) == 0) { //opens Data.txt in read mode and watches for errors
		printf("\nFile opened successfully \n");

		while ((c = fgetc(fP)) != EOF) {         //As long as it is not at the end of the file
			count++;
			pTmp->Data.message[count] = c;	//records the qoute character by character into the buffer msg
		}
		pTmp->Data.message[count + 1] = '\0';
		pTmp->Data.size = count + 1;
		fclose(fP);
		return(0);
	}
	else {
		printf("\nError: Failed to open file\n");
		fclose(fP);
		return(-1);
	}
}