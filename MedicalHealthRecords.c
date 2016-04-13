#include <stdio.h>
#include "userInterface.h"
#include <errno.h>
#include <unistd.h>

/*The main function calls all interface functions and provides the logic that determines what role recieves
what options.*/
int main(void){
	int selectChoice = 0;
	char *ptr;
	
	FILE *patientFile;
	if((patientFile = fopen("patients.bin", "a+b")) == NULL){
		printf("File not found, exiting.");
		exit(1);
	}
	if(fseek(patientFile, 0L, SEEK_END) == -1){
		printf("Seek operation failed.");
		exit(1);
	}
	const size_t fileSize = ftell(patientFile);
	fclose(patientFile);
	
	deEscalatePrivilege();

	
	
	char* tempUserID = (char*)malloc(sizeof(char) * 100);
	if(tempUserID == NULL){
		printf("Unable to allocate memory.");
		exit(1);
	}
	memset(tempUserID, 0, sizeof(char)*100);
	char* tempChoice = (char*)malloc(sizeof(char) * 100);
	if(tempChoice == NULL){
		printf("Unable to allocate memory.");
		exit(1);
	}
	memset(tempChoice, 0, sizeof(char)*100);
	char* tempUserPassword = (char*)malloc(sizeof(char) * 100);
	if(tempUserPassword == NULL){
		printf("Unable to allocate memory.");
		exit(1);
	}
	if(fileSize == false){
		printf("There are no users currently saved, displaying admin role.\n");
		roleAdmin(tempUserID, sizeof(char) * 100);
	}
	memset(tempUserPassword, 0, sizeof(char) * 100);
	patientRecord logonUserStruct;
	patientRecord *logonUser = &logonUserStruct;
	memset(logonUser, 0, sizeof(patientRecord));
	while(1){
	
		while(true){
			printf("\nAre you at least 13 years old?");
			printf("\n1. Yes");
			printf("\n2. No");
			printf("\nEnter option: ");
			if(fgets(tempChoice, 3, stdin) == NULL){
				selectChoice = 0;
			}else if (digitOrNot(tempChoice) == -1) {
  				if(puts("Number out of range, try again.\n") == EOF) {
					selectChoice = 0; 
  				}
			}else{
				selectChoice = strtol(tempChoice,&ptr,10);
			}
			printf("\nPress Enter To Continue.");
			while ( (getchar()) != '\n');
			if(selectChoice != 1 && selectChoice != 2){
				printf("\nIncorrect option, try again");
			}else if(selectChoice == 2){
				printf("\nDenied, not old enough, come back after you're 13 or older.");
			}else if(selectChoice == 1){
				printf("\nWelcome!\n");
				break;
			}
		}
		
		printf("Would you like to sign in or exit?\n");
		printf("1. Sign in.\n");
		printf("2. Exit.\n");
		printf("Enter 1 or 2: ");
		while(true){
			if(fgets(tempChoice, 3, stdin) == NULL){
				selectChoice = 0;
			}else if (digitOrNot(tempChoice) == -1) {
	  			if(puts("Number out of range, try again.\n") == EOF) {
					selectChoice = 0; 
	  			}
			}else{
				selectChoice = strtol(tempChoice,&ptr,10);
				break;
			}
		}
		printf("\nPress Enter To Continue.");
		while ( (getchar()) != '\n');
		
		if(selectChoice == 1){
			printLogon(tempUserID, tempUserPassword , logonUser, sizeof(char) * 100);
			switch(logonUser->role){
      				case 1:
					printf("\nWelcome Admin.\n\n");
					roleAdmin(tempUserID, sizeof(char) * 100);
					break;
      				case 2 :
					printf("\nWelcome Doctor.\n\n");
					roleDoctor(tempUserID, sizeof(char) * 100);
					break;
      				case 3 :
					printf("\nWelcome Nurse.\n\n");
					roleNurse(tempUserID, sizeof(char) * 100);
					break;
				case 4 :
					printf("\nWelcome Patient.\n\n");
					rolePatient(tempUserID, sizeof(char) * 100, logonUser);
					break;
				default :
        				printf("This user has an invalid role.\n" );
					break;
			}
		}else if(selectChoice == 2){
			printf("Goodbye!\n\n");
			break;
		}else{
			printf("Inproper input, try again.");
		}	
	}
	free(tempUserPassword);	
	tempUserPassword = NULL;
	free(tempChoice);
	tempChoice = NULL;
	free(tempUserID);
	tempUserID = NULL;
}
