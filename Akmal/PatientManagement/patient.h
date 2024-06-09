#ifndef PATIENT_H
#define PATIENT_H

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char id[20];
    char name[100];
    char address[150];
    char city[50];
    char birthplace[50];
    Date birthDate;
    int age;
    char BPJSNumber[20];
} Patient;

#endif // PATIENT_H
