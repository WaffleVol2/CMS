/*
Queues.cpp - Implementation for the queue functionality
By: Brendan B
*/
#include "Queues.h"
#include <stdlib.h>
#include <stdio.h>

static link pHead, pTail;




void InitQueue(void) {
	pHead = pTail = NULL;
}

int IsQueueEmpty(void) {
	return(pHead == NULL);
}

void AddToQueue(link pn) {
	if (IsQueueEmpty()) {
		pHead = pTail = pn;
	}
	else {
		pTail->pNext = pn;			//Old tail points to pn
		pTail = pn;					// pTail points to pn
	}
	pTail->pNext = NULL;			//pTail next is NULL
}
link DeQueue(void) {				//Deletes queue one by one from head.
	link pTemp;
	if (IsQueueEmpty()) {
		return(NULL);
	}
	else {
		pTemp = pHead;
		pHead = pHead->pNext;
		return(pTemp);
	}
}

//Assignment 2 Recursion

link returnHead() {					//Returns the head of the Queue
	return pHead;
}

int count(link x) {					//Counts the length of the queue
	if (x == NULL) {
		return (0);
	}
	return (1 + count(x->pNext));
}

link deleteR(link parent, link child, Item v) {   //Deletes given item in the Queue
	if (child == NULL) {
		return(NULL);
	}
	if (child->Data.sid == v.sid) {
		parent->pNext = child->pNext;                    //"Were gonna basically delete the child" - Michael Galle
		free(child);
		deleteR(parent, parent->pNext, v);
	}
	else {
		deleteR(child, child->pNext, v);
	}
}

void visit(link h) {							//Locates and prints a specific SID of an item in the queue
	printf("\nSID of node: %d", h->Data.sid);
}

void traverse(link h, void(*visit)(link)) {		//Traverses the function in a forward direction
	if (h == NULL) {
		return;
	}
	(*visit)(h);
	traverse(h->pNext, visit);
}

void traverseR(link h, void(*visit)(link)) {	//Traverses the function in a reverse direction
	if (h == NULL) {
		return;
	}
	traverseR(h->pNext, visit);
	(*visit)(h);
}