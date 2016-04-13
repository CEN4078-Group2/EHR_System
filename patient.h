#include "stdlib.h"
#include <stdio.h>
#include <string.h>

#define true 1
#define false 0
#define prec sizeof(char) * 3

typedef struct patient
{
	char name[100];
	char CPOE[100];
	char address[100];
	char password[100];
	char drugInteraction[100];
	char fastPatHist[100];
	char ePrescription[100];
	char activeMedList[100];
	char medAllergyList[100];
	char sex[10];
	char insurance[100];
	char vitalSigns[100];
	char smokingStatus[100];
	char birthDate[100];
	int patientID;
	int role;
	int deleted;
	char reminders[100];	 
}patientRecord;


