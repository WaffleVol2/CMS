//Header file for the menu system. 
//By Brendan Burdett

#pragma once

int mainMenu();

//MAIN
int transmit();
int receive();
int settings();

//TRANSMIT
int text();
int audio();

//TEXT
int customMessage();
int generatFromFile();

//AUDIO
int record();
int loadFromFile();
int audioSend();

//RECEIVE
int receiverStation();
int viewStored();

//SETTINGS
//Settings.h and settings.cpp
int debug();