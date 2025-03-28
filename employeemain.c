#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "employee.h"

PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *nameToFind);

// Function pointer-based
PtrToEmployee searchEmployeeGeneric(const Employee table[], int sizeTable, void *target, int (*cmp)(PtrToConstEmployee, void *));
int compareByPhone(PtrToConstEmployee emp, void *targetPhone);


extern Employee EmployeeTable[];
extern const int EmployeeTableEntries;

int main(void) {
    PtrToEmployee matchPtr;

    //Search by Number
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);
    if(matchPtr != NULL)
        printf("Employee ID 1045 is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID is NOT found in the record\n");

    //Search by Name
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if(matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");

    // Search by Phone (Match)
    char *targetPhone = "310-555-1215";
    matchPtr = searchEmployeeGeneric(EmployeeTable, EmployeeTableEntries, targetPhone, compareByPhone);
    if(matchPtr != NULL)
        printf("Employee with phone %s is in record %ld\n", targetPhone, matchPtr - EmployeeTable);
    else
        printf("Phone number %s is NOT found in the record\n", targetPhone);

    //Search by Phone (No Match)
    targetPhone = "000-000-0000";
    matchPtr = searchEmployeeGeneric(EmployeeTable, EmployeeTableEntries, targetPhone, compareByPhone);
    if(matchPtr != NULL)
        printf("Employee with phone %s is in record %ld\n", targetPhone, matchPtr - EmployeeTable);
    else
        printf("Phone number %s is NOT found in the record\n", targetPhone);

    return EXIT_SUCCESS;
}
