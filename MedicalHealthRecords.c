#include <stdio.h>
#include "userInterface.h"

int main(void){
	
	char* tempUserID = (char*)malloc(sizeof(char) * 100);
	if(tempUserID == NULL){
		printf("Unable to allocate memory.");
		exit(1);
	}
	memset(tempUserID, 0, sizeof(char));
	char* tempUserPassword = (char*)malloc(sizeof(char) * 100);
	if(tempUserPassword == NULL){
		printf("Unable to allocate memory.");
		exit(1);
	}
	memset(tempUserPassword, 0, sizeof(char));
	patientRecord* logonUser = (patientRecord*)malloc(sizeof(patientRecord));
	if(logonUser == NULL){
		printf("Unable to allocate memory.");
		exit(1);
	}
	memset(logonUser, 0, sizeof(patientRecord));
	printLogon(tempUserID, tempUserPassword , logonUser, sizeof(*tempUserID));

	switch(logonUser->role){
      		case 1 :
			printf("\nWelcome Admin.\n\n");
			roleAdmin(tempUserID, sizeof(*tempUserID));
			break;
      		case 2 :
			printf("\nWelcome Doctor.\n\n");
			roleDoctor(tempUserID, sizeof(*tempUserID));
			break;
      		case 3 :
			printf("\nWelcome Nurse.\n\n");
			roleNurse(tempUserID, sizeof(*tempUserID));
			break;
		case 4 :
			break;
		default :
         		printf("This user has an invalid role.\n" );
			break;

	}
	free(tempUserID);
	tempUserID = NULL;
	free(tempUserPassword);
	tempUserPassword = NULL;
	free(logonUser);
	logonUser = NULL;
}
