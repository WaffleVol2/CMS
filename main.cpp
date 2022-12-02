/* main.cpp - Client for the Tx/Rx Program
 * Author: Brendan Burdett
 *
 */
#include <stdio.h>
#include "Menu.h"
#include "sound.h"

 // The client - A testing main that calls the functions below
int main() {
	InitializeRecording();
	InitializePlayback();

	printf("TO START PRESS ENTER");
	mainMenu();
}