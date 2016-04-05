#include <stdio.h>
#include "userInterface.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void printLogon(int userID, char* password, patientRecord* patientLookUp){
	bool roleBool = false;
	do{
		roleBool = false;
		printf("Enter user ID: ");
		if(scanf("%d%*c", &userID) == 0){
			printf("\nError, userID operation not done");
			roleBool = true;
		}else{
			printf("Enter password: ");
			if(fgets(password, sizeof(password), stdin) == NULL){
				printf("\nError, password operation not done");
				roleBool = true;
			}else{
				if(inputValidation(userID, password) == -1){
					printf("\nInput invalid try again.");
					roleBool = true;
				}else{
					roleChoice(userID, password, patientLookUp);
					if(patientLookUp->patientID == -1){
						roleBool = true;
					}else if(patientLookUp->patientID == -2){
						roleBool = true;
					}else{
						if(strncmp(password, patientLookUp->password, strlen(patientLookUp->password)) != 0){
							printf("\nIncorrect password, try again.");
							roleBool = true;
						}
					}
				}
			}
		}	
	}while(roleBool);
}

void roleDoctor(void){
	bool loopBreakOne = true;
	unsigned int select = 0;
	patientRecord* tempUserDoc = (patientRecord*)malloc(sizeof(patientRecord));
	memset(tempUserDoc, 0, sizeof(patientRecord));
	while(loopBreakOne){
		
		
		printf("1. Computerized physician order entry(CPOE).\n");
		printf("2. Drug interaction check.\n");
		printf("3. Fast overview of patient history.\n");
		printf("4. E-Precription.\n");
		printf("5. Active medications.\n");
		printf("6. Medication Allergy list.\n");
		printf("7. Demographics.\n");
		printf("8. Vital Signs.\n");
		printf("9. Smoking status.\n");
		printf("Enter the number of the option desired: ");
		fscanf(stdin, "%d%*c", &select);

		switch(select){
      		case 1 :
			fileRead(tempUserDoc);
			printf("Enter CPOE: ");
			fgets(tempUserDoc->CPOE, sizeof(tempUserDoc->CPOE),stdin);
			fileWrite(tempUserDoc);
			break;
      		case 2 :
			fileRead(tempUserDoc);
			printf("Enter drug interaction check: ");
			fgets(tempUserDoc->CPOE, sizeof(tempUserDoc->CPOE),stdin);
			fileWrite(tempUserDoc);
			break;
      		case 3 :
			fileRead(tempUserDoc);
			printf("Enter patient history: ");
			fgets(tempUserDoc->CPOE, sizeof(tempUserDoc->CPOE),stdin);
			fileWrite(tempUserDoc);
			break;
		case 4 :
			fileRead(tempUserDoc);
			printf("Enter E-Prescription: ");
			fgets(tempUserDoc->CPOE, sizeof(tempUserDoc->CPOE),stdin);
			fileWrite(tempUserDoc);
			break;
		case 5 :
			fileRead(tempUserDoc);
			printf("Enter avtive medications: ");
			fgets(tempUserDoc->CPOE, sizeof(tempUserDoc->CPOE),stdin);
			fileWrite(tempUserDoc);
			break;
		case 6 :
			fileRead(tempUserDoc);
			printf("Enter medication allergy list: ");
			fgets(tempUserDoc->CPOE, sizeof(tempUserDoc->CPOE),stdin);
			fileWrite(tempUserDoc);
			break;
		case 7 :
			fileRead(tempUserDoc);
			printf("Enter Demographics for- \n");
			printf("address: \n");
			fgets(tempUserDoc->CPOE, sizeof(tempUserDoc->CPOE),stdin);
			fileWrite(tempUserDoc);
			break;
		case 8 :
			fileRead(tempUserDoc);
			printf("Enter vital signs: ");
			fgets(tempUserDoc->CPOE, sizeof(tempUserDoc->CPOE),stdin);
			fileWrite(tempUserDoc);
			break;
		case 9 :
			fileRead(tempUserDoc);
			printf("Enter smoking status: ");
			fgets(tempUserDoc->CPOE, sizeof(tempUserDoc->CPOE),stdin);
			fileWrite(tempUserDoc);
			break;
     		default :
         	printf("Invalid Option, try again.\n" );
		break;
   		}
	}
	free(tempUserDoc);
}

void roleAdmin(void){
	bool loopBreakOne = true;
	unsigned int select = 0;
	patientRecord* tempUserAdmin = (patientRecord*)malloc(sizeof(patientRecord));
	memset(tempUserAdmin, 0, sizeof(patientRecord));
	while(loopBreakOne){
		
		
		printf("1. Enter a new user.\n");
		printf("2. Delete a current user.\n");
		printf("3. Edit a current user.\n");
		printf("Enter the number of the option desired: ");
		fscanf(stdin, "%d%*c", &select);

		
		switch(select){
      		case 1 :
         		createNewPatient();
         		break;
      		case 2 :
			fileRead(tempUserAdmin);
			tempUser->deleted = true;
			fileWrite(tempUserAdmin);
			printf("User deleted.");
			break;
      		case 3 :
			memset(tempUserAdmin, 0, sizeof(patientRecord));
         		fileRead(tempUserAdmin);
			printf("This is the current user: \n");
			printf("Name: %s", tempUserAdmin->name);
			printf("User ID: %d\n", tempUserAdmin->patientID);
			printf("Password: %s", tempUserAdmin->password);
			printf("Role: %d\n", tempUserAdmin->role);
			userFillNew(tempUserAdmin);
			fileWrite(tempUserAdmin);	
         		break;
      		default :
         		printf("Invalid Option, try again.\n" );
		}
	}
	free(tempUserAdmin);
}

void roleNurse(void){
	bool loopBreakOne = true;
	unsigned int select = 0;
	patientRecord* tempUserNurse = (patientRecord*)malloc(sizeof(patientRecord));
	memset(tempUserNurse, 0, sizeof(patientRecord));
	while(loopBreakOne){
		printf("1. Enter a new user.\n");
		printf("2. Delete a current user.\n");
		printf("3. Edit a current user.\n");
		printf("Enter the number of the option desired: ");		
		fscanf(stdin, "%d%*c", &select);

		
		switch(select){
      		case 1 :
         		break;
      		case 2 :
			break;
      		case 3 :	
         		break;
      		default :
         	printf("Invalid option, try again." );
		}
	}
	free(tempUserNurse);
}

void createNewPatient(void){	
	bool boolean = true;
	FILE *patientFile;
	if((patientFile = fopen("patients.bin", "a+b")) == NULL){
		printf("File not found, exiting.");
		exit(1);
	}	
	patientRecord* writeUser = (patientRecord*)malloc(sizeof(patientRecord));
	memset(writeUser, 0, sizeof(patientRecord));
	patientRecord* tempUserOne = (patientRecord*)malloc(sizeof(patientRecord));
	memset(writeUser, 0, sizeof(patientRecord));
	while(boolean){
		userFillNew(writeUser);
		do{
			fReader(tempUserOne, patientFile);
		}while(tempUserOne->patientID != writeUser->patientID && !feof(patientFile));
		if(writeUser->patientID == tempUserOne->patientID){
			printf("That user already exists, try again.\n");
		}else if (tempUserOne->deleted == true){
			printf("That user was deleted.");
		}else{
			break;
		}
	}
	fWriter(writeUser, patientFile);
	free(writeUser);
	fclose(patientFile);
}

void fileRead(patientRecord *patientLookUp){
	int tempID;
	printf("Enter the ID of the user you wish to lookup.");
	scanf("%d%*c", &tempID);
	FILE *patientFile;
	if((patientFile = fopen("patients.bin", "rb")) == NULL){
		printf("File not found, exiting.");
		exit(1);
	}
	do{
		fReader(patientLookUp, patientFile);
	}while(patientLookUp->patientID != tempID && !feof(patientFile));
	if(feof(patientFile)){
		printf("End of file reached, user not found.");
		exit(1);
	}else if (patientLookUp->deleted == true){
		printf("That user was deleted.");
	}
	fclose(patientFile);
}

void fileWrite(patientRecord *writeUser){
	FILE *patientFile;
	patientRecord* tempPatient = (patientRecord*)malloc(sizeof(patientRecord));
	memset(tempPatient, 0, sizeof(patientRecord));
	if((patientFile = fopen("patients.bin", "rb+")) == NULL){
		printf("File not found, exiting.");
		exit(1);
	}
	while(tempPatient->patientID != writeUser->patientID){
		fReader(tempPatient, patientFile);
	}
	if(writeUser->patientID == tempPatient->patientID){	
		fWriter(writeUser, patientFile);
	}else{
		printf("Read/Write Failure.");
		exit(1);
		}	
	free(tempPatient);	
	fclose(patientFile);
}

void userFillNew(patientRecord *writeUser){
	char natta[] = "n/a";
	printf("Enter the users name.");
	fgets(writeUser->name, sizeof(writeUser->name),stdin);
	printf("Enter the users ID.");
	scanf("%d%*c", &writeUser->patientID);
	printf("Enter the users password.");
	fgets(writeUser->password, sizeof(writeUser->password),stdin);
	printf("Enter the users role.");
	scanf("%d%*c", &writeUser->role);
	strncpy(writeUser->address, natta, sizeof(natta));
	strncpy(writeUser->drugInteraction, natta, sizeof(natta));
	strncpy(writeUser->fastPatHist, natta, sizeof(natta));
	strncpy(writeUser->ePrescription, natta, sizeof(natta));
	strncpy(writeUser->activeMedList, natta, sizeof(natta));
	strncpy(writeUser->medAllergyList, natta, sizeof(natta));
	strncpy(writeUser->sex, natta, sizeof(natta));
	strncpy(writeUser->insurance, natta, sizeof(natta));
	strncpy(writeUser->vitalSigns, natta, sizeof(natta));
	strncpy(writeUser->smokingStatus, natta, sizeof(natta));
	strncpy(writeUser->birthDate, natta, sizeof(natta));
	writeUser->deleted = false;	
}

void fReader(patientRecord *readUser, FILE *patientFile){
	fread(&readUser->name,sizeof(readUser->name), 1, patientFile);
	fread(&readUser->patientID,sizeof(readUser->patientID), 1, patientFile);
	fread(&readUser->password,sizeof(readUser->password), 1, patientFile);
	fread(&readUser->role,sizeof(readUser->role), 1, patientFile);
	fread(&readUser->deleted,sizeof(readUser->deleted), 1, patientFile);
	fread(&readUser->CPOE,sizeof(readUser->CPOE), 1, patientFile);
	fread(&readUser->address,sizeof(readUser->address), 1, patientFile);
	fread(&readUser->drugInteraction,sizeof(readUser->drugInteraction), 1, patientFile);
	fread(&readUser->fastPatHist,sizeof(readUser->fastPatHist), 1, patientFile);
	fread(&readUser->ePrescription,sizeof(readUser->ePrescription), 1, patientFile);
	fread(&readUser->activeMedList,sizeof(readUser->activeMedList), 1, patientFile);
	fread(&readUser->medAllergyList,sizeof(readUser->medAllergyList), 1, patientFile);
	fread(&readUser->sex,sizeof(readUser->sex), 1, patientFile);
	fread(&readUser->insurance,sizeof(readUser->insurance), 1, patientFile);
	fread(&readUser->vitalSigns,sizeof(readUser->vitalSigns), 1, patientFile);
	fread(&readUser->smokingStatus,sizeof(readUser->smokingStatus), 1, patientFile);
	fread(&readUser->birthDate,sizeof(readUser->birthDate), 1, patientFile);
	fread(&readUser->deleted,sizeof(readUser->deleted), 1, patientFile);
}
void fWriter(patientRecord *writeUser, FILE *patientFile){
	fwrite(&writeUser->name,sizeof(writeUser->name), 1, patientFile);
	fwrite(&writeUser->patientID,sizeof(writeUser->patientID), 1, patientFile);
	fwrite(&writeUser->password,sizeof(writeUser->password), 1, patientFile);
	fwrite(&writeUser->role,sizeof(writeUser->role), 1, patientFile);
	fwrite(&writeUser->deleted,sizeof(writeUser->deleted), 1, patientFile);
	fwrite(&writeUser->CPOE,sizeof(writeUser->CPOE), 1, patientFile);
	fwrite(&writeUser->address,sizeof(writeUser->address), 1, patientFile);
	fwrite(&writeUser->drugInteraction,sizeof(writeUser->drugInteraction), 1, patientFile);
	fwrite(&writeUser->fastPatHist,sizeof(writeUser->fastPatHist), 1, patientFile);
	fwrite(&writeUser->ePrescription,sizeof(writeUser->ePrescription), 1, patientFile);
	fwrite(&writeUser->activeMedList,sizeof(writeUser->activeMedList), 1, patientFile);
	fwrite(&writeUser->medAllergyList,sizeof(writeUser->medAllergyList), 1, patientFile);
	fwrite(&writeUser->sex,sizeof(writeUser->sex), 1, patientFile);
	fwrite(&writeUser->insurance,sizeof(writeUser->insurance), 1, patientFile);
	fwrite(&writeUser->vitalSigns,sizeof(writeUser->vitalSigns), 1, patientFile);
	fwrite(&writeUser->smokingStatus,sizeof(writeUser->smokingStatus), 1, patientFile);
	fwrite(&writeUser->birthDate,sizeof(writeUser->birthDate), 1, patientFile);
	fwrite(&writeUser->deleted,sizeof(writeUser->deleted), 1, patientFile);
}

int inputValidation(int userID, char* myString){
    	for(size_t i = 0; myString[i] != '\0'; ++i) {
        	if(('%' == myString[i]) ){
			char percentChar = '%';
            		printf("The password cannot contain a %c symbol, try again.", percentChar);
            		return -1;
        	}
    	}
	return 0;
}

void roleChoice(int userID, char* password, patientRecord* patientLookUp)
{
	FILE *patientFile;
	if((patientFile = fopen("patients.bin", "rb")) == NULL){
		printf("File not found, exiting.");
		exit(1);
	}
	do{
		fReader(patientLookUp, patientFile);
	}while(patientLookUp->patientID != userID && !feof(patientFile));
	if(feof(patientFile)){
		printf("End of file reached, user not found.");
		patientLookUp->patientID = -1;
		fclose(patientFile);
	}else if (patientLookUp->deleted == true){
		printf("That user was deleted.");
		patientLookUp->patientID = -2;
		fclose(patientFile);
	}else{
		fclose(patientFile);
	}
}
