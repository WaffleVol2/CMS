/*	Filename: Settings.h
	Author: Brendan Burdett
	Date: Updated 2022
	Details: Settings - Contains all setting functions
*/
#pragma once
#include "Header.h"

typedef struct settings settingsConfigured;

struct settings {
	int comrate = 9600;
	short int headerToggle = 1;
};

void receiverID(Header* txHeader);
void senderID(Header* txHeader);
void compressionConfig(Header* txHeader);
void encryptionConfig(Header* txHeader);
void comrateConfig();
void portRXConfig();
void portTXConfig();
void view(Header* txHeader);
void savePreset();
void headerToggle(Header* txHeader);