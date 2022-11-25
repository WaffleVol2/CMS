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
};

void compressionConfig();
void encryptionConfig();
void comrateConfig();
void portRXConfig();
void portTXConfig();
void view();
void savePreset();
void headerToggle();

header* configApply();