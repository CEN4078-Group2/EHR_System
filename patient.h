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

/*Enter the users name.nate
Enter the users ID.1212
Enter the users password.pass 
Enter the users role.1

Enter the users name.mike
Enter the users ID.4343
Enter the users password.ssap
Enter the users role.2

Enter the users name.john
Enter the users ID.1234
Enter the users password.rood
Enter the users role.3

Enter the users name.anna
Enter the users ID.4321
Enter the users password.catl
Enter the users role.4*/
