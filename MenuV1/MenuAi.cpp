// MenuAi.cpp : This file contains the Menu UI
// by:- Shivam shivam
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>






int main()
{    //int for userinputs 

	int userInput;
	int transmit;
	int recieve;
	
	
	//menu interface for the messaging coded system 
	
	printf("=========================================================================================\n");
	printf("\nMENU FOR Coaded Messaging system\n\n");


	printf("=========================================================================================\n");
	
	printf("choose option\n\n");

	printf("1.Transmit\n");
	printf("2.Receive\n");
	printf("3.communication settings\n");
	
	for (int i = 0; i < 20; i++) {

	scanf_s("%d", &userInput);

	if (userInput == 1) {  //transmit function menu
		
		system("cls");
		printf("===Welcome to the Transmit menu===\n");

		printf("\n1.Text\n");
		printf("2.Audio\n");
		
		

		// Sub menus tranmit 

		if (transmit == 1) {

			system("cls");
			printf("===Welcome to the text version===\n");
			printf("=======================================================\n");
			printf("1.Generate message\n");
			printf("2.Send message\n");
			printf("3.Exit\n");




		} else if (transmit == 2) {

			system("cls");
			printf("\nWelcome to the Audio version\n");
			printf("=======================================================\n");
			printf("1.record\n");
			printf("2.Play\n");
			printf("3.send\n");
			printf("4.load\n");




		}
		


	}

	if (userInput == 2) { //recieve menu

		system("cls");
		printf("\nWelcome to the recieve menu\n");
		printf("1.Text\n");
		printf("2.Audio\n");
		scanf_s("%d", &recieve);


		if (recieve == 1) {
			system("cls");
			printf("1.View\n");
			printf("2.Rx\n");

		}
		else if (recieve == 2) {
			system("cls");
			printf("1.View\n");
			printf("2.Rx\n");

		}
		



	}
	if (userInput == 3) {   //communication settings 

		printf("\n=====setting menu======\n");
		system("cls");
		printf("1.Bit rate\n");
		printf("2.comm/ttys port\n");
		printf("3.Rx ID\n");
		printf("4.ENCRYPTION\n");
		printf("5.COMPRESSION\n");
		printf("6.TIMEOUT\n");
		printf("7.OPTIONST\n");



	}



	}


	}

