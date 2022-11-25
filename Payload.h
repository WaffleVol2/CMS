//Payload.h | Defines payload content
//By Brendan B
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