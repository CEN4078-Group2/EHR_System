#include <stdio.h>
#include "patient.h"
#define structSize sizeof(patientRecord)

void printLogon(char* tempID,char* password, patientRecord* patientLookUp, size_t len);
void roleChoice(int userID, patientRecord* patientLookUp);
void roleAdmin(char* tempID, size_t len);
void roleDoctor(char* tempID, size_t len);
void roleNurse(char* tempID, size_t len);
void rolePatient(char* tempID, size_t len, patientRecord* logonUser);
void createNewPatient(void);
void fileRead(patientRecord *patientLookUp, size_t len);
void fileWrite(patientRecord *writeuser);
void userFillNew(patientRecord *writeUser, size_t len);
void fReader(patientRecord *readUser, FILE *patientFile);
void fWriter(patientRecord *writeUser, FILE *patientFile);
int inputValidation(int userID, char* myString);
void privilegeEscalate(void);
void deEscalatePrivilege(void);
int digitOrNot(char *myString);

