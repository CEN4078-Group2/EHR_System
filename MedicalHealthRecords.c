#include <stdio.h>
#include "userInterface.h"

int main(void){
	
	int tempUserID = 0;
	char* tempUserPassword = (char*)malloc(sizeof(char) * 100);
	memset(tempUserPassword, 0, sizeof(char));
	patientRecord* logonUser = (patientRecord*)malloc(sizeof(patientRecord));
	memset(logonUser, 0, sizeof(patientRecord));
	printLogon(tempUserID, tempUserPassword , logonUser);

	switch(logonUser->role){
      		case 1 :
			printf("\nWelcome Admin.\n\n");
			roleAdmin();
			break;
      		case 2 :
			printf("\nWelcome Doctor.\n\n");
			roleDoctor();
			break;
      		case 3 :
			break;
		case 4 :
			break;
		default :
         		printf("This user has an invalid role.\n" );
			break;

	}
}
