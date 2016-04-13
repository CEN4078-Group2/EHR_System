#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
#include "userInterface.h"


/*This function prompts the user for their user ID and password. It validates the input of the password then fetches the user data from the file. If the password doesn't match it prompts the user to enter their credentials again.*/
void printLogon(char* tempID, char* password, patientRecord* patientLookUp, size_t len){
	int roleBool = false;
	int userID = 0;
	char *ptr;
	do{
		roleBool = false;
		printf("Enter user ID: ");
		if(fgets(tempID, len, stdin) == NULL){
			printf("\nError, userID operation not done");
			roleBool = true;
			printf("\nPress Enter To Continue.");
			while ( (getchar()) != '\n');
		}else if(digitOrNot(tempID) == -1){
				printf("Number out of range, try again.\n");
				roleBool = true;
				printf("\nPress Enter To Continue.");
				while ( (getchar()) != '\n');
			}else{
				userID = strtol(tempID,&ptr,10);
				printf("\nPress Enter To Continue.");
				while ( (getchar()) != '\n');
				printf("Enter password: ");
			if(fgets(password, len, stdin) == NULL){
				printf("\nError, password operation not done");
				roleBool = true;
				printf("\nPress Enter To Continue.");
				while ( (getchar()) != '\n');
			}else if(inputValidation(tempID) == -1){
				printf("Number out of range, try again.\n");
				roleBool = true;
				printf("\nPress Enter To Continue.");
				while ( (getchar()) != '\n');
			}else{
				if(inputValidation(password) == -1){
					printf("\nInput invalid try again.");
					roleBool = true;
					printf("\nPress Enter To Continue.");
					while ( (getchar()) != '\n');
				}else{
					
					roleChoice(userID, patientLookUp);
					if(patientLookUp->patientID == -1){
						roleBool = true;
					}else if(patientLookUp->patientID == -2){
						roleBool = true;
					}else{
						if(strncmp(password, patientLookUp->password, strlen(patientLookUp->password)) != 0){
							printf("\nIncorrect password, try again.");
							roleBool = true;
							printf("\nPress Enter To Continue.");
							while ( (getchar()) != '\n');
						}
					}
				}
			}
		}
	}while(roleBool);
}

/*This function displays the options for the doctor role. It fetches the user data from the file and depending on what choice is made will memset a particular value before taking the new one from the user.*/
void roleDoctor(char* tempID, size_t len){
	int loopBreakOne = false;
	char *ptr;
	char buffer[100];
	unsigned int selectChoiceDoc = 0;
	patientRecord tempUserDocStruct;
	patientRecord *tempUserDoc = &tempUserDocStruct;
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
		printf("10. Reminders.\n");
		printf("11. Logout.\n");
		printf("Enter the number of the option desired: ");
		memset(tempID, 0, sizeof(char)*100);
		if(fgets(tempID, len, stdin) == NULL){
			selectChoiceDoc = 0;
		}else if (digitOrNot(tempID) == -1) {
  			if(puts("Number out of range, try again.\n") == EOF) {
				selectChoiceDoc = 0; 
  			}
		}else{
			selectChoiceDoc = strtol(tempID,&ptr,10);
		}
		printf("\nPress Enter To Continue.");
		while ( (getchar()) != '\n');

		switch(selectChoiceDoc){
      		case 1 :
			do{
				fileRead(tempUserDoc, sizeof(tempUserDoc->name));
			}while(tempUserDoc->deleted == true);
			printf("Enter CPOE: ");
			memset(tempUserDoc->CPOE, 0, sizeof(tempUserDoc->CPOE));
			if(fgets(buffer, sizeof(char) * 99,stdin) == NULL){
				printf("Input is invalid");
				printf("\nPress Enter To Continue.");
				while ( (getchar()) != '\n');
				break;
			}
			strncpy(tempUserDoc->CPOE, buffer, sizeof(tempUserDoc->CPOE));
			fileWrite(tempUserDoc);
			printf("\nPress Enter To Continue.");
			while ( (getchar()) != '\n');
			break;
      		case 2 :
			do{
				fileRead(tempUserDoc, sizeof(tempUserDoc->name));
			}while(tempUserDoc->deleted == true);
			printf("Enter drug interaction check: ");
			memset(tempUserDoc->drugInteraction, 0, sizeof(tempUserDoc->drugInteraction));
			if(fgets(buffer, sizeof(char) * 99,stdin) == NULL){
				printf("Input is invalid");
				printf("\nPress Enter To Continue.");
				while ( (getchar()) != '\n');
				break;
			}
			strncpy(tempUserDoc->drugInteraction, buffer, sizeof(tempUserDoc->drugInteraction));
			fileWrite(tempUserDoc);
			printf("\nPress Enter To Continue.");
			while ( (getchar()) != '\n');
			break;
      		case 3 :
			do{
				fileRead(tempUserDoc, sizeof(tempUserDoc->name));
			}while(tempUserDoc->deleted == true);
			printf("Enter patient history: ");
			memset(tempUserDoc->fastPatHist, 0, sizeof(tempUserDoc->fastPatHist));
			if(fgets(buffer, sizeof(char) * 99,stdin) == NULL){
				printf("Input is invalid");
				printf("\nPress Enter To Continue.");
				while ( (getchar()) != '\n');
				break;
			}
			strncpy(tempUserDoc->fastPatHist, buffer, sizeof(tempUserDoc->fastPatHist));
			fileWrite(tempUserDoc);
			printf("\nPress Enter To Continue.");
			while ( (getchar()) != '\n');
			break;
		case 4 :
			do{
				fileRead(tempUserDoc, sizeof(tempUserDoc->name));
			}while(tempUserDoc->deleted == true);
			printf("Enter E-Prescription: ");
			memset(tempUserDoc->ePrescription, 0, sizeof(tempUserDoc->ePrescription));
			if(fgets(buffer, sizeof(char) * 99,stdin) == NULL){
				printf("Input is invalid");
				printf("\nPress Enter To Continue.");
				while ( (getchar()) != '\n');
				break;
			}
			strncpy(tempUserDoc->ePrescription, buffer, sizeof(tempUserDoc->ePrescription));
			fileWrite(tempUserDoc);
			printf("\nPress Enter To Continue.");
			while ( (getchar()) != '\n');
			break;
		case 5 :
			do{
				fileRead(tempUserDoc, sizeof(tempUserDoc->activeMedList));
			}while(tempUserDoc->deleted == true);
			printf("Enter active medications: ");
			memset(tempUserDoc->activeMedList, 0, sizeof(tempUserDoc->activeMedList));
			if(fgets(buffer, sizeof(char) * 99,stdin) == NULL){
				printf("Input is invalid");
				printf("\nPress Enter To Continue.");
				while ( (getchar()) != '\n');
				break;
			}
			strncpy(tempUserDoc->activeMedList, buffer, sizeof(tempUserDoc->activeMedList));
			fileWrite(tempUserDoc);
			printf("\nPress Enter To Continue.");
			while ( (getchar()) != '\n');
			break;
		case 6 :
			do{
				fileRead(tempUserDoc, sizeof(tempUserDoc->name));
			}while(tempUserDoc->deleted == true);
			printf("Enter medication allergy list: ");
			memset(tempUserDoc->medAllergyList, 0, sizeof(tempUserDoc->medAllergyList));
			if(fgets(buffer, sizeof(char) * 99,stdin) == NULL){
				printf("Input is invalid");
				printf("\nPress Enter To Continue.");
				while ( (getchar()) != '\n');
				break;
			}
			strncpy(tempUserDoc->medAllergyList, buffer, sizeof(tempUserDoc->medAllergyList));
			fileWrite(tempUserDoc);
			printf("\nPress Enter To Continue.");
			while ( (getchar()) != '\n');
			break;
		case 7 :
			do{
				fileRead(tempUserDoc, sizeof(tempUserDoc->name));
			}while(tempUserDoc->deleted == true);
			printf("Enter Demographics for: %s", tempUserDoc->name);
			printf("Address: \n");
			memset(tempUserDoc->address, 0, sizeof(tempUserDoc->address));
			if(fgets(buffer, sizeof(char) * 99,stdin) == NULL){
				printf("Input is invalid");
				printf("\nPress Enter To Continue.");
				while ( (getchar()) != '\n');
				break;
			}
			strncpy(tempUserDoc->address, buffer, sizeof(tempUserDoc->address));
			printf("Sex: \n");
			memset(tempUserDoc->sex, 0, sizeof(tempUserDoc->sex));
			if(fgets(buffer, sizeof(char) * 9,stdin) == NULL){
				printf("Input is invalid");
				printf("\nPress Enter To Continue.");
				while ( (getchar()) != '\n');
				break;
			}
			strncpy(tempUserDoc->sex, buffer, sizeof(tempUserDoc->sex));
			printf("Insurance: \n");
			memset(tempUserDoc->insurance, 0, sizeof(tempUserDoc->insurance));
			if(fgets(buffer, sizeof(char) * 99,stdin) == NULL){
				printf("Input is invalid");
				printf("\nPress Enter To Continue.");
				while ( (getchar()) != '\n');
				break;
			}
			strncpy(tempUserDoc->insurance, buffer, sizeof(tempUserDoc->insurance));
			printf("Date of birth: \n");
			memset(tempUserDoc->birthDate, 0, sizeof(tempUserDoc->birthDate));
			if(fgets(buffer, sizeof(char) * 99,stdin) == NULL){
				printf("Input is invalid");
				printf("\nPress Enter To Continue.");
				while ( (getchar()) != '\n');
				break;
			}
			strncpy(tempUserDoc->birthDate, buffer, sizeof(tempUserDoc->birthDate));
			fileWrite(tempUserDoc);
			printf("\nPress Enter To Continue.");
			while ( (getchar()) != '\n');
			break;
		case 8 :
			do{
				fileRead(tempUserDoc, sizeof(tempUserDoc->vitalSigns));
			}while(tempUserDoc->deleted == true);
			printf("Enter vital signs: ");
			memset(tempUserDoc->vitalSigns, 0, sizeof(tempUserDoc->vitalSigns));
			if(fgets(buffer, sizeof(char) * 99,stdin) == NULL){
				printf("Input is invalid");
				printf("\nPress Enter To Continue.");
				while ( (getchar()) != '\n');
				break;
			}
			strncpy(tempUserDoc->vitalSigns, buffer, sizeof(tempUserDoc->vitalSigns));
			fileWrite(tempUserDoc);
			printf("\nPress Enter To Continue.");
			while ( (getchar()) != '\n');
			break;
		case 9 :
			do{
				fileRead(tempUserDoc, sizeof(tempUserDoc->smokingStatus));
			}while(tempUserDoc->deleted == true);
			printf("Enter smoking status: ");
			memset(tempUserDoc->smokingStatus, 0, sizeof(tempUserDoc->smokingStatus));
			if(fgets(buffer, sizeof(char) * 99,stdin) == NULL){
				printf("Input is invalid");
				printf("\nPress Enter To Continue.");
				while ( (getchar()) != '\n');
				break;
			}
			strncpy(tempUserDoc->smokingStatus, buffer, sizeof(tempUserDoc->smokingStatus));
			fileWrite(tempUserDoc);
			printf("\nPress Enter To Continue.");
			while ( (getchar()) != '\n');
			break;
		case 10 :
			do{				
				fileRead(tempUserDoc, sizeof(tempUserDoc->reminders));
			}while(tempUserDoc->deleted == true);
			printf("Enter reminders: ");
			memset(tempUserDoc->reminders, 0, sizeof(tempUserDoc->reminders));
			if(fgets(buffer, sizeof(char) * 99,stdin) == NULL){
				printf("Input is invalid");
				printf("\nPress Enter To Continue.");
				while ( (getchar()) != '\n');
				break;
			}
			strncpy(tempUserDoc->reminders, buffer, sizeof(tempUserDoc->reminders));
			fileWrite(tempUserDoc);
			printf("\nPress Enter To Continue.");
			while ( (getchar()) != '\n');
			break;
		case 11 :
         		loopBreakOne = true;
         		printf("\nPress Enter To Continue.");
         		while ( (getchar()) != '\n');
         		break;
     		default :
         		printf("Invalid Option, try again.\n" );
         		printf("\nPress Enter To Continue.");
         		while ( (getchar()) != '\n');
			break;
   		}
		if(loopBreakOne == true){
			break;
		}
	}
}

/*This function displays the admin role. It fetches the user data from the file and allows the current user to delete the desired user or changed basic administrative data.*/
void roleAdmin(char* tempID, size_t len){
	int loopBreakOne = false;
	unsigned int selectChoiceAdmin = 0;
	char *ptr;
	patientRecord tempUserAdminStruct;
	patientRecord *tempUserAdmin = &tempUserAdminStruct;
	memset(tempUserAdmin, 0, sizeof(patientRecord));
	while(true){

		printf("1. Enter a new user.\n");
		printf("2. Delete a current user.\n");
		printf("3. Edit a current user.\n");
		printf("4. Logout.\n");
		printf("\nEnter the number of the option desired: ");
		if(fgets(tempID, len, stdin) == NULL){
			selectChoiceAdmin = 0;
		}else if (digitOrNot(tempID) == -1) {
  			if(puts("Number out of range, try again.\n") == EOF) {
				selectChoiceAdmin = 0; 
  			}
		}else{
			selectChoiceAdmin = strtol(tempID,&ptr,10);
		}

		
		switch(selectChoiceAdmin){
      		case 1 :
         		createNewPatient();
         		printf("\nPress Enter To Continue.");
         		while ( (getchar()) != '\n');
         		break;
      		case 2 :
			do{
         			fileRead(tempUserAdmin, sizeof(tempUserAdmin->name));
         		}while(tempUserAdmin->deleted == true);
			tempUserAdmin->deleted = true;
			fileWrite(tempUserAdmin);
			printf("User deleted.");
			printf("\nPress Enter To Continue.");
			while ( (getchar()) != '\n');
			break;
      		case 3 :
      			do{
         			fileRead(tempUserAdmin, sizeof(tempUserAdmin->name));
         		}while(tempUserAdmin->deleted == true);
			printf("This is the current user: \n");
			printf("Name: %s", tempUserAdmin->name);
			printf("User ID: %d\n", tempUserAdmin->patientID);
			printf("Password: %s", tempUserAdmin->password);
			printf("Role: %d\n", tempUserAdmin->role);
			userFillNew(tempUserAdmin, sizeof(tempUserAdmin->name));
			fileWrite(tempUserAdmin);
			printf("\nPress Enter To Continue.");
			while ( (getchar()) != '\n');	
         		break;
         	case 4 :
         		loopBreakOne = true;
         		printf("\nPress Enter To Continue.");
         		while ( (getchar()) != '\n');
         		break;
      		default:
         		printf("Invalid Option, try again.\n" );
         		printf("\nPress Enter To Continue.");
         		while ( (getchar()) != '\n');
			break;
   		}
		if(loopBreakOne == true){
			break;
		}
	}
}

/*This function displays the nurse role options. It fetches the user data from the file and allows the current user to view patient lists and edit vital signs as well as update reminders.*/
void roleNurse(char* tempID, size_t len){
	FILE *patientFile;
	int loopBreakOne = false;
	unsigned int selectChoiceNurse = 0;
	char *ptr;
	char buffer[100];
	patientRecord tempUserNurseStruct;
	patientRecord *tempUserNurse = &tempUserNurseStruct;
	memset(tempUserNurse, 0, sizeof(patientRecord));
	while(true){
		printf("1. View patient list.\n");
		printf("2. Edit vital signs.\n");
		printf("3. Edit patient reminders.\n");
		printf("4. Logout.\n");
		printf("Enter the number of the option desired: ");		
		if(fgets(tempID, len, stdin) == NULL){
			selectChoiceNurse = 0;
		}else if (digitOrNot(tempID) == -1) {
  			if(puts("Number out of range, try again.\n") == EOF) {
				selectChoiceNurse = 0; 
  			}
		}else{
			selectChoiceNurse = strtol(tempID,&ptr,10);
		}

		switch(selectChoiceNurse){
      		case 1 :
      			privilegeEscalate();		
			if((patientFile = fopen("patients.bin", "r+b")) == NULL){
				printf("File not found, exiting.");
				exit(1);
			}
			while(!feof(patientFile)){
				if(tempUserNurse->role == 4){
					printf("Name: %s", tempUserNurse->name);
				}
				fReader(tempUserNurse, patientFile);
			}
			fclose(patientFile);
			deEscalatePrivilege();
         		break;
      		case 2 :
			do{
				fileRead(tempUserNurse, sizeof(tempUserNurse->vitalSigns));
			}while(tempUserNurse->deleted == true);
			printf("Enter vital signs: ");
			memset(tempUserNurse->vitalSigns, 0, sizeof(tempUserNurse->vitalSigns));
			if(fgets(buffer, sizeof(tempUserNurse->vitalSigns),stdin) == NULL){
				printf("Input is invalid");
				printf("\nPress Enter To Continue.");
				while ( (getchar()) != '\n');
				break;
			}
			strncpy(tempUserNurse->vitalSigns, buffer, sizeof(tempUserNurse->vitalSigns));
			fileWrite(tempUserNurse);
			printf("\nPress Enter To Continue.");
			while ( (getchar()) != '\n');
			break;
      		case 3 :
			do{
      				fileRead(tempUserNurse, sizeof(tempUserNurse->reminders));
			}while(tempUserNurse->deleted == true);
			printf("Enter reminders: ");
			memset(tempUserNurse->reminders, 0, sizeof(tempUserNurse->reminders));
			if(fgets(buffer, sizeof(tempUserNurse->reminders),stdin) == NULL){
				printf("Input is invalid");
				printf("\nPress Enter To Continue.");
				while ( (getchar()) != '\n');
				break;
			}
			strncpy(tempUserNurse->reminders, buffer, sizeof(tempUserNurse->reminders));
			fileWrite(tempUserNurse);
			printf("\nPress Enter To Continue.");
			while ( (getchar()) != '\n');
			break;
         	case 4 :
         		loopBreakOne = true;
         		printf("\nPress Enter To Continue.");
         		while ( (getchar()) != '\n');
         		break;
      		default :
         		printf("Invalid Option, try again.\n" );
         		printf("\nPress Enter To Continue.");
         		while ( (getchar()) != '\n');
			break;
   		}
		if(loopBreakOne == true){
			break;
		}
	}
}

/*This function displays the patient role options. It fetches the data of the current user and allows them to view 
their medical information.*/
void rolePatient(char* tempID, size_t len, patientRecord* logonUser){
	int loopBreakOne = false;
	unsigned int selectChoicePatient = 0;
	char *ptr;
	while(true){
		printf("1. View Patient Info.\n");
		printf("2. Logout.\n");
		printf("Enter the number of the option desired: ");		
		if(fgets(tempID, len, stdin) == NULL){
			selectChoicePatient = 0;
		}else if (digitOrNot(tempID) == -1) {
  			if(puts("Number out of range, try again.\n") == EOF) {
				selectChoicePatient = 0; 
  			}
		}else{
			selectChoicePatient = strtol(tempID,&ptr,10);
		}
		switch(selectChoicePatient){
      			case 1  :
				printf("\nName: %s", logonUser->name);
				printf("\nPatient ID: %d", logonUser->patientID);
				printf("\nDOB: %s", logonUser->birthDate);
				printf("\nAddress: %s", logonUser->address);
				printf("\nInsurance: %s", logonUser->insurance);
				printf("\nSex: %s", logonUser->sex);
				printf("\nReminders: %s", logonUser->reminders);
				printf("\nVital Signs: %s", logonUser->vitalSigns);
				printf("\nSmoking Status: %s", logonUser->smokingStatus);
				printf("\nPatient History: %s", logonUser->fastPatHist);
				printf("\nMedications on Order: %s", logonUser->ePrescription);
				printf("\nActive Medications: %s", logonUser->activeMedList);
				printf("\nMedicinal Allergies: %s", logonUser->medAllergyList);
				printf("\nDrug Interactions: %s\n", logonUser->drugInteraction);
				printf("\nPress Enter To Continue.");
				while ( (getchar()) != '\n');
				break;
			case 2 :
				loopBreakOne = true;
				printf("\nPress Enter To Continue.");
				while ( (getchar()) != '\n');
         			break;
      			default:
         			printf("Invalid Option, try again.\n" );
         			printf("\nPress Enter To Continue.");
         			while ( (getchar()) != '\n');
				break;
   		}
		if(loopBreakOne == true){
		break;
		}
	}
}

/*Initialises a new patient structure for writing to a file. Only accessible from the admin role.*/
void createNewPatient(void){		
	patientRecord writeUserStruct;
	patientRecord *writeUser = &writeUserStruct;
	memset(writeUser, 0, sizeof(patientRecord));
	patientRecord tempUserOneStruct;
	patientRecord *tempUserOne = &tempUserOneStruct;
	memset(tempUserOne, 0, sizeof(patientRecord));
	while(true){
		userFillNew(writeUser, sizeof(writeUser->name));
		roleChoice(writeUser->patientID, tempUserOne);
		if(writeUser->patientID == tempUserOne->patientID){
			printf("That user already exists, try again.\n");
		}else if(inputValidation(writeUser->password) == -1){
			printf("\nPassword Input invalid try again.");
		
		}else{
			break;
		}
	}
      	privilegeEscalate();
	FILE *patientFile;
	if((patientFile = fopen("patients.bin", "a+b")) == NULL){
		printf("File not found, exiting.");
		exit(1);
	}
	fWriter(writeUser, patientFile);
	fclose(patientFile);
	deEscalatePrivilege();
}

/*Takes the ID of the user desired for look and populates a temporary struct with that data so that work
may be done upon it.*/
void fileRead(patientRecord *patientLookUp, size_t len){
	FILE *patientFile;
	char* tempUserID = (char*)malloc(sizeof(char) * 100);
	if(tempUserID == NULL){
		printf("Unable to allocate memory.");
		exit(1);
	}
	memset(tempUserID, 0, sizeof(char)*100);
	int tempID;
	char *ptr; 
	while(true){
		printf("\nEnter the ID of the user you wish to lookup:");
		if(fgets(tempUserID, 7, stdin) == NULL){
			printf("\nError, userID operation not done, try again.");
			printf("\nPress Enter To Continue.");
			while ( (getchar()) != '\n');		
		}else if (digitOrNot(tempUserID) == -1) {
	  		printf("\nNumber out of range, try again.\n");
	  		printf("\nPress Enter To Continue.");
	  		while ( (getchar()) != '\n');
		}else{
			tempID = strtol(tempUserID,&ptr,10);
			break;
		}
	}
      	privilegeEscalate();
	if((patientFile = fopen("patients.bin", "rb")) == NULL){
		printf("File not found, exiting.");
		exit(1);
	}
	do{
		fReader(patientLookUp, patientFile);
	}while(patientLookUp->patientID != tempID && !feof(patientFile));
	if(feof(patientFile)){
		printf("End of file reached, user not found.");
	}else if (patientLookUp->deleted == true){
		printf("That user was deleted, try again.");
	}
	deEscalatePrivilege();
	fclose(patientFile);
	free(tempUserID);
}

/*searches for the user that needs to be updated and overwrites the struct in the file.*/
void fileWrite(patientRecord *writeUser){
	
	FILE *patientFile;
	patientRecord tempPatient;
	patientRecord* tempPatientPtr = &tempPatient;
	memset(tempPatientPtr, 0, sizeof(patientRecord));
	privilegeEscalate();
	if((patientFile = fopen("patients.bin", "rb+")) == NULL){
		printf("File not found, exiting.");
		exit(1);
	}
	while(tempPatientPtr->patientID != writeUser->patientID){
		fReader(tempPatientPtr, patientFile);
	}
	if(writeUser->patientID == tempPatientPtr->patientID){	
		if(fseek(patientFile, -1424, SEEK_CUR)== -1){
			printf("Seek operation failed.");
			exit(1);		
		}
		fWriter(writeUser, patientFile);
	}else{
		printf("Read/Write Failure.");
		exit(1);
	}		
	fclose(patientFile);
	deEscalatePrivilege();
}

/*Populates a new struct with initial values.*/ 
void userFillNew(patientRecord *writeUser, size_t len){
	char* tempUserID = (char*)malloc(sizeof(char) * 100);
	if(tempUserID == NULL){
		printf("Unable to allocate memory.");
		exit(1);
	}
	memset(tempUserID, 0, sizeof(char));
	char *ptr; 
	int boolUserNew = true;
	const char natta[] = "n/a";
	while(boolUserNew){
		printf("Enter the users name.");
		memset(writeUser->name, 0, strlen(writeUser->name) * sizeof(char));
		if(fgets(writeUser->name, sizeof(writeUser->name),stdin) == NULL){
			printf("Inproper input for name, try again.");		
		}else{
			boolUserNew = false;
		}
	
		printf("Enter the users ID.");
		if(fgets(tempUserID, 7, stdin) == NULL){
			printf("\nError, userID operation not done");		
		}else if (digitOrNot(tempUserID) == -1) {
	  		if(puts("Number out of range, try again.\n") == EOF) {
					 
	  		}
		}else{
			writeUser->patientID = strtol(tempUserID,&ptr,10);
			boolUserNew = false;
		}
		printf("Enter the users password.");
		memset(writeUser->password, 0, strlen(writeUser->password) * sizeof(char));
		if(fgets(writeUser->password, sizeof(writeUser->password),stdin) == NULL){
			printf("Inproper input for password, try again.");		
		}else{
			boolUserNew = false;
		}
		printf("Enter the users role.");
		if(fgets(tempUserID, 7, stdin) == NULL){
			printf("\nError, userID operation not done");		
		}else if (digitOrNot(tempUserID) == -1) {
	  		if(puts("Number out of range, try again.\n") == EOF) {
					 
	  		}
		}else{
			writeUser->role = strtol(tempUserID,&ptr,10);
			boolUserNew = false;
		}
	}
	strncpy(writeUser->address, natta, sizeof(prec));
	strncpy(writeUser->drugInteraction, natta, sizeof(prec));
	strncpy(writeUser->fastPatHist, natta, sizeof(prec));
	strncpy(writeUser->ePrescription, natta, sizeof(prec));
	strncpy(writeUser->activeMedList, natta, sizeof(prec));
	strncpy(writeUser->medAllergyList, natta, sizeof(prec));
	strncpy(writeUser->sex, natta, sizeof(prec));
	strncpy(writeUser->insurance, natta, sizeof(prec));
	strncpy(writeUser->vitalSigns, natta, sizeof(prec));
	strncpy(writeUser->smokingStatus, natta, sizeof(prec));
	strncpy(writeUser->birthDate, natta, sizeof(prec));
	strncpy(writeUser->reminders, natta, sizeof(prec));
	writeUser->deleted = false;
	free(tempUserID);	
}

/*The actual read of a struct.*/
void fReader(patientRecord *readUser, FILE *patientFile){
	if(fread((char*)readUser,sizeof(*readUser), 1, patientFile)== false){
		if(!feof(patientFile)){
			printf("Read failed.");
		}
	}
	
}

/*The actual write of a struct.*/
void fWriter(patientRecord *writeUser, FILE *patientFile){	
	if(fwrite((char*)writeUser,sizeof(*writeUser), 1, patientFile)== false){
		printf("Write failed.");
	}
}

/*Checks the input for percents.*/
int inputValidation(char* myString){
    	for(size_t i = 0; myString[i] != '\0'; ++i) {
        	if(('%' == myString[i]) || myString[i] == ' '){
			const unsigned char percentChar = '%';
            		printf("The password cannot contain a %c symbol or empty space character, try again.\n", percentChar);
            		return -1;
        	}
    	}
	return 0;
}

/*A function that fetches a particular users data for use in determining the role of the user.*/
void roleChoice(int userID, patientRecord* checkUser)
{
      	privilegeEscalate();
	FILE *patientFile;
	if((patientFile = fopen("patients.bin", "rb")) == NULL){
		printf("File not found, exiting.");
		exit(1);
	}
	do{
		if(feof(patientFile)){
			printf("End of file reached, user not found.");
			checkUser->patientID = -1;
		}else if (checkUser->deleted == true){
			printf("That user was deleted.");
			checkUser->patientID = -2;
		}else{
			fReader(checkUser, patientFile);
		}
	}while(checkUser->patientID != userID && !feof(patientFile) && checkUser->deleted != true);
	fclose(patientFile);
	deEscalatePrivilege();
}

/*Escalates the privileges of the program to root.*/
void privilegeEscalate(void){
	
	if(seteuid(0) == -1)
	{
		printf("Error, permission denied.");
		exit(1);
	}

}

/*De-escalates the privileges of the program to normal user rights.*/
void deEscalatePrivilege(void){
	
	if(seteuid(1000) == -1)
	{
		printf("Error, permission denied.");
		exit(1);
	}

}

/*Checks if string has a digit or not.*/
int digitOrNot(char *myString){
	for(size_t i = 0; i < strlen(myString); i++){
		if(!isdigit(myString[i]) && myString[i] != '\n' && myString[i] != '\0'){
			return -1;
		}
	}
	return 0;
}
