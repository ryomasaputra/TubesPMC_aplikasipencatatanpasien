#include "patient.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_patient_to_database(Patient *patient) {
    FILE *file = fopen("DataPasien.csv", "a");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    char dateString[255];
    sprintf(dateString, "%d-%d-%d", patient->birthDate.day, patient->birthDate.month, patient->birthDate.year);
    fprintf(file, "%s;%s;%s;%s;%s;%d;%s;%s\n", patient->id, patient->name, patient->address, patient->city, patient->birthplace, dateString, patient->age, patient->BPJSNumber);
    fclose(file);
}

void display_patient_info_from_database(const char *patient_id) {
    FILE *file = fopen("DataPasien.csv", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    char line[255];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ";");
        if (token != NULL && strcmp(token, patient_id) == 0) {
            printf("Patient ID: %s\n", token);
            printf("Full Name: %s\n", strtok(NULL, ";"));
            printf("Address: %s\n", strtok(NULL, ";"));
            printf("City: %s\n", strtok(NULL, ";"));
            printf("Birth Place: %s\n", strtok(NULL, ";"));
            printf("Birth Date: %s\n", strtok(NULL, ";"));
            printf("Age: %s\n", strtok(NULL, ";"));
            printf("BPJS Number: %s\n", strtok(NULL, ";"));
            break;
        }
    }

    fclose(file);
}
