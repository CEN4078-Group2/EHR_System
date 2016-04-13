
CC = gcc
CFLAGS  = -g -Wall -std=c99 -D_GNU_SOURCE

default: MHR

MHR:  MedicalHealthRecords.o userInterface.o 
	$(CC) $(CFLAGS) -o MHR MedicalHealthRecords.o userInterface.o

MedicalHealthRecords.o:  MedicalHealthRecords.c userInterface.h patient.h
	$(CC) $(CFLAGS) -c MedicalHealthRecords.c

userInterface.o:  userInterface.c userInterface.h patient.h 
	$(CC) $(CFLAGS) -c userInterface.c

clean: 
	$(RM) *.o MedicalHealthRecords.o userInterface.o 
