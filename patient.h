#include "stdlib.h"
#include <stdio.h>
#include <string.h>

typedef struct patient
{
	char name[100];
	char CPOE[100];
	char address[100];
	char password[100];
	char drugInteraction[100];
	char fastPatHist[500];
	char ePrescription[100];
	char activeMedList[100];
	char medAllergyList[100];
	char sex[10];
	char insurance[50];
	char vitalSigns[100];
	char smokingStatus[100];
	char birthDate[50];
	int patientID;
	int role;
	int deleted;	 
}patientRecord;
