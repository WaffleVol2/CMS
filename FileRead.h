/* Interface: Header file for File Reading for getting messages from a file
*  By: Brendan B
*/
#pragma once

typedef struct node Node;
typedef struct item Item;
typedef Node* link;

struct item {
	int size;
	unsigned char message[1000];
	unsigned char audio[1000000];
};

struct node {
	link pNext;
	Item Data;
};

int getMsgFile(link* buff);                  // Function gets and prints a message from the file