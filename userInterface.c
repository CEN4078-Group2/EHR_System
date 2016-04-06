#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include "userInterface.h"

#define true 1
#define false 0

void printLogon(int userID, char* password, patientRecord* patientLookUp){
	int roleBool = false;
	do{
		roleBool = false;
		printf("Enter user ID: ");
		if(scanf("%d%*c", &userID) != 1){
			printf("\nError, userID operation not done");
			roleBool = true;
		}else if (ERANGE == errno) {
  			if(puts("Number out of range, try again.\n") == EOF) {
      			roleBool = true;
  			}
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
	int loopBreakOne = false;
	unsigned int selectChoiceDoc = 0;
	patientRecord* tempUserDoc = (patientRecord*)malloc(sizeof(patientRecord));
	if(tempUserDoc == NULL){
		printf("Unable to allocate memory.");
		exit(1);
	}
	memset(tempUserDoc, 0, sizeof(patientRecord));
	while(true){
		
		
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
		if(fscanf(stdin, "%d%*c", &selectChoiceDoc) != 1){
			selectChoiceDoc = 0;
		}else if (ERANGE == errno) {
  			if(puts("Number out of range, try again.\n") == EOF) {
				selectChoiceDoc = 0; 
  			}
		}

		switch(selectChoiceDoc){
      		case 1 :
			fileRead(tempUserDoc);
			printf("Enter CPOE: ");
			if(fgets(tempUserDoc->CPOE, sizeof(tempUserDoc->CPOE),stdin) == NULL){
				printf("Input is invalid");
				break;
			}
			fileWrite(tempUserDoc);
			break;
      		case 2 :
			fileRead(tempUserDoc);
			printf("Enter drug interaction check: ");
			if(fgets(tempUserDoc->CPOE, sizeof(tempUserDoc->CPOE),stdin) == NULL){
				printf("Input is invalid");
				break;
			}
			fileWrite(tempUserDoc);
			break;
      		case 3 :
			fileRead(tempUserDoc);
			printf("Enter patient history: ");
			if(fgets(tempUserDoc->CPOE, sizeof(tempUserDoc->CPOE),stdin) == NULL){
				printf("Input is invalid");
				break;
			}
			fileWrite(tempUserDoc);
			break;
		case 4 :
			fileRead(tempUserDoc);
			printf("Enter E-Prescription: ");
			if(fgets(tempUserDoc->CPOE, sizeof(tempUserDoc->CPOE),stdin) == NULL){
				printf("Input is invalid");
				break;
			}
			fileWrite(tempUserDoc);
			break;
		case 5 :
			fileRead(tempUserDoc);
			printf("Enter avtive medications: ");
			if(fgets(tempUserDoc->CPOE, sizeof(tempUserDoc->CPOE),stdin) == NULL){
				printf("Input is invalid");
				break;
			}
			fileWrite(tempUserDoc);
			break;
		case 6 :
			fileRead(tempUserDoc);
			printf("Enter medication allergy list: ");
			if(fgets(tempUserDoc->CPOE, sizeof(tempUserDoc->CPOE),stdin) == NULL){
				printf("Input is invalid");
				break;
			}
			fileWrite(tempUserDoc);
			break;
		case 7 :
			fileRead(tempUserDoc);
			printf("Enter Demographics for- \n");
			printf("address: \n");
			if(fgets(tempUserDoc->CPOE, sizeof(tempUserDoc->CPOE),stdin) == NULL){
				printf("Input is invalid");
				break;
			}
			fileWrite(tempUserDoc);
			break;
		case 8 :
			fileRead(tempUserDoc);
			printf("Enter vital signs: ");
			if(fgets(tempUserDoc->CPOE, sizeof(tempUserDoc->CPOE),stdin) == NULL){
				printf("Input is invalid");
				break;
			}
			fileWrite(tempUserDoc);
			break;
		case 9 :
			fileRead(tempUserDoc);
			printf("Enter smoking status: ");
			if(fgets(tempUserDoc->CPOE, sizeof(tempUserDoc->CPOE),stdin) == NULL){
				printf("Input is invalid");
				break;
			}
			fileWrite(tempUserDoc);
			break;
     		default :
         	printf("Invalid Option, try again.\n" );
		loopBreakOne = true;
		break;
   		}
		if(loopBreakOne == true){
			break;
		}
	}
	free(tempUserDoc);
}

void roleAdmin(void){
	int loopBreakOne = true;
	unsigned int selectChoiceAdmin = 0;
	patientRecord* tempUserAdmin = (patientRecord*)malloc(sizeof(patientRecord));
	if(tempUserAdmin == NULL){
		printf("Unable to allocate memory.");
		exit(1);
	}
	memset(tempUserAdmin, 0, sizeof(patientRecord));
	while(true){

		printf("1. Enter a new user.\n");
		printf("2. Delete a current user.\n");
		printf("3. Edit a current user.\n");
		printf("Enter the number of the option desired: ");
		if(fscanf(stdin, "%d%*c", &selectChoiceAdmin) != 1){
			selectChoiceAdmin = 0;
		}else if (ERANGE == errno) {
  			if(puts("Number out of range, try again.\n") == EOF) {
				selectChoiceAdmin = 0; 
  			}
		}

		
		switch(selectChoiceAdmin){
      		case 1 :
         		createNewPatient();
         		break;
      		case 2 :
			fileRead(tempUserAdmin);
			tempUserAdmin->deleted = true;
			fileWrite(tempUserAdmin);
			printf("User deleted.");
			break;
      		case 3 :
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
		loopBreakOne = true;
		break;
   		}
		if(loopBreakOne == true){
			break;
		}
	}
	free(tempUserAdmin);
}

void roleNurse(void){
	int loopBreakOne = true;
	unsigned int selectChoiceNurse = 0;
	patientRecord* tempUserNurse = (patientRecord*)malloc(sizeof(patientRecord));
	if(tempUserNurse == NULL){
		printf("Unable to allocate memory.");
		exit(1);
	}
	memset(tempUserNurse, 0, sizeof(patientRecord));
	while(true){
		printf("1. View patient list.\n");
		printf("2. Edit vital signs.\n");
		printf("3. Edit patient reminders.\n");
		printf("Enter the number of the option desired: ");		
		if(fscanf(stdin, "%d%*c", &selectChoiceNurse) != 1){
			selectChoiceNurse = 0;
		}else if (ERANGE == errno) {
  			if(puts("Number out of range, try again.\n") == EOF) {
				selectChoiceNurse = 0; 
  			}
		}

		FILE *patientFile;
			if((patientFile = fopen("patients.bin", "rb")) == NULL){
				printf("File not found, exiting.");
				exit(1);
			}
		switch(selectChoiceNurse){
      		case 1 :
			while(!feof(patientFile)){
				fReader(tempUserNurse, patientFile);
				if(tempUserNurse->role == 4){
					printf("Name: %s", tempUserNurse->name);
				}
			}
			fclose(patientFile);
         		break;
      		case 2 :
			break;
      		case 3 :	
         		break;
      		default :
         	printf("Invalid Option, try again.\n" );
		loopBreakOne = true;
		break;
   		}
		if(loopBreakOne == true){
			break;
		}
	}
	free(tempUserNurse);
}

void createNewPatient(void){	
	FILE *patientFile;
	if((patientFile = fopen("patients.bin", "a+b")) == NULL){
		printf("File not found, exiting.");
		exit(1);
	}	
	patientRecord* writeUser = (patientRecord*)malloc(sizeof(patientRecord));
	if(writeUser == NULL){
		printf("Unable to allocate memory.");
		exit(1);
	}
	memset(writeUser, 0, sizeof(patientRecord));
	
	patientRecord* tempUserOne = (patientRecord*)malloc(sizeof(patientRecord));
	if(tempUserOne == NULL){
		printf("Unable to allocate memory.");
		exit(1);
	}
	memset(writeUser, 0, sizeof(patientRecord));
	
	while(true){
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
	fclose(patientFile);
	free(writeUser);
}

void fileRead(patientRecord *patientLookUp){
	int tempID;
	int readBool = true;
	printf("Enter the ID of the user you wish to lookup.");
	while(readBool){
		if(fscanf(stdin, "%d%*c", &tempID) != 1){
			printf("\nError, userID operation not done");		
		}else if (ERANGE == errno) {
	  		if(puts("Number out of range, try again.\n") == EOF) {
					 
	  		}
		}else{
			readBool = false;
		}
	}
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
	if(tempPatient == NULL){
		printf("Unable to allocate memory.");
		exit(1);
	}
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
	fclose(patientFile);
	free(tempPatient);
}

void userFillNew(patientRecord *writeUser){
	int boolUserNew = true;
	char natta[] = "n/a";
	while(boolUserNew){
		printf("Enter the users name.");
		if(fgets(writeUser->name, sizeof(writeUser->name),stdin) == NULL){
			printf("Inproper input for name, try again.");		
		}else{
			boolUserNew = false;
		}
	
		printf("Enter the users ID.");
		if(fscanf(stdin, "%d%*c", &writeUser->patientID) != 1){
			printf("\nError, userID operation not done");		
		}else if (ERANGE == errno) {
	  		if(puts("Number out of range, try again.\n") == EOF) {
					 
	  		}
		}else{
			boolUserNew = false;
		}
		printf("Enter the users password.");
		if(fgets(writeUser->password, sizeof(writeUser->password),stdin) == NULL){
			printf("Inproper input for password, try again.");		
		}else{
			boolUserNew = false;
		}
		printf("Enter the users role.");
		if(fscanf(stdin, "%d%*c", &writeUser->role) != 1){
			printf("\nError, userID operation not done");		
		}else if (ERANGE == errno) {
	  		if(puts("Number out of range, try again.\n") == EOF) {
					 
	  		}
		}else{
			boolUserNew = false;
		}
	}
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
	if(fread(&readUser->name,sizeof(readUser->name), 1, patientFile) == false){
		printf("Read failed.");
	}	
	if(fread(&readUser->patientID,sizeof(readUser->patientID), 1, patientFile) == false){
		printf("Read failed.");
	}
	if(fread(&readUser->password,sizeof(readUser->password), 1, patientFile)== false){
		printf("Read failed.");
	}
	if(fread(&readUser->role,sizeof(readUser->role), 1, patientFile)== false){
		printf("Read failed.");
	}
	if(fread(&readUser->deleted,sizeof(readUser->deleted), 1, patientFile)== false){
		printf("Read failed.");
	}
	if(fread(&readUser->CPOE,sizeof(readUser->CPOE), 1, patientFile)== false){
		printf("Read failed.");
	}
	if(fread(&readUser->address,sizeof(readUser->address), 1, patientFile)== false){
		printf("Read failed.");
	}
	if(fread(&readUser->drugInteraction,sizeof(readUser->drugInteraction), 1, patientFile)== false){
		printf("Read failed.");
	}
	if(fread(&readUser->fastPatHist,sizeof(readUser->fastPatHist), 1, patientFile)== false){
		printf("Read failed.");
	}
	if(fread(&readUser->ePrescription,sizeof(readUser->ePrescription), 1, patientFile)== false){
		printf("Read failed.");
	}
	if(fread(&readUser->activeMedList,sizeof(readUser->activeMedList), 1, patientFile)== false){
		printf("Read failed.");
	}
	if(fread(&readUser->medAllergyList,sizeof(readUser->medAllergyList), 1, patientFile)== false){
		printf("Read failed.");
	}
	if(fread(&readUser->sex,sizeof(readUser->sex), 1, patientFile)== false){
		printf("Read failed.");
	}
	if(fread(&readUser->insurance,sizeof(readUser->insurance), 1, patientFile)== false){
		printf("Read failed.");
	}
	if(fread(&readUser->vitalSigns,sizeof(readUser->vitalSigns), 1, patientFile)== false){
		printf("Read failed.");
	}
	if(fread(&readUser->smokingStatus,sizeof(readUser->smokingStatus), 1, patientFile)== false){
		printf("Read failed.");
	}
	if(fread(&readUser->birthDate,sizeof(readUser->birthDate), 1, patientFile)== false){
		printf("Read failed.");
	}
	if(fread(&readUser->deleted,sizeof(readUser->deleted), 1, patientFile)== false){
		printf("Read failed.");
	}
}
void fWriter(patientRecord *writeUser, FILE *patientFile){
	if(fwrite(&writeUser->name,sizeof(writeUser->name), 1, patientFile) == false){
		printf("Read failed.");
	}	
	if(fwrite(&writeUser->patientID,sizeof(writeUser->patientID), 1, patientFile) == false){
		printf("Read failed.");
	}
	if(fwrite(&writeUser->password,sizeof(writeUser->password), 1, patientFile)== false){
		printf("Read failed.");
	}
	if(fwrite(&writeUser->role,sizeof(writeUser->role), 1, patientFile)== false){
		printf("Read failed.");
	}
	if(fwrite(&writeUser->deleted,sizeof(writeUser->deleted), 1, patientFile)== false){
		printf("Read failed.");
	}
	if(fwrite(&writeUser->CPOE,sizeof(writeUser->CPOE), 1, patientFile)== false){
		printf("Read failed.");
	}
	if(fwrite(&writeUser->address,sizeof(writeUser->address), 1, patientFile)== false){
		printf("Read failed.");
	}
	if(fwrite(&writeUser->drugInteraction,sizeof(writeUser->drugInteraction), 1, patientFile)== false){
		printf("Read failed.");
	}
	if(fwrite(&writeUser->fastPatHist,sizeof(writeUser->fastPatHist), 1, patientFile)== false){
		printf("Read failed.");
	}
	if(fwrite(&writeUser->ePrescription,sizeof(writeUser->ePrescription), 1, patientFile)== false){
		printf("Read failed.");
	}
	if(fwrite(&writeUser->activeMedList,sizeof(writeUser->activeMedList), 1, patientFile)== false){
		printf("Read failed.");
	}
	if(fwrite(&writeUser->medAllergyList,sizeof(writeUser->medAllergyList), 1, patientFile)== false){
		printf("Read failed.");
	}
	if(fwrite(&writeUser->sex,sizeof(writeUser->sex), 1, patientFile)== false){
		printf("Read failed.");
	}
	if(fwrite(&writeUser->insurance,sizeof(writeUser->insurance), 1, patientFile)== false){
		printf("Read failed.");
	}
	if(fwrite(&writeUser->vitalSigns,sizeof(writeUser->vitalSigns), 1, patientFile)== false){
		printf("Read failed.");
	}
	if(fwrite(&writeUser->smokingStatus,sizeof(writeUser->smokingStatus), 1, patientFile)== false){
		printf("Read failed.");
	}
	if(fwrite(&writeUser->birthDate,sizeof(writeUser->birthDate), 1, patientFile)== false){
		printf("Read failed.");
	}
	if(fwrite(&writeUser->deleted,sizeof(writeUser->deleted), 1, patientFile)== false){
		printf("Read failed.");
	}
}

int inputValidation(int userID, char* myString){
    	for(size_t i = 0; myString[i] != '\0'; ++i) {
        	if(('%' == myString[i]) ){
			const unsigned char percentChar = '%';
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
