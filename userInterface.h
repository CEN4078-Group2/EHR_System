#include <stdio.h>
#include "patient.h"


void printLogon(int userID,char* password, patientRecord* patientLookUp);
void roleChoice(int userID, char* password, patientRecord* patientLookUp);
void roleAdmin(void);
void roleDoctor(void);
void roleNurse(void);
void rolePatient(void);
void createNewPatient();
void fileRead(patientRecord *patientLookUp);
void fileWrite(patientRecord *writeuser);
void userFillNew(patientRecord *writeUser);
void fReader(patientRecord *readUser, FILE *patientFile);
void fWriter(patientRecord *writeUser, FILE *patientFile);
int inputValidation(int userID, char* myString);

