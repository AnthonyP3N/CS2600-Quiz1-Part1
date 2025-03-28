#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "employee.h"

PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *nameToFind);

// Function pointer-based
PtrToEmployee searchEmployeeGeneric(const Employee table[], int sizeTable, void *target, int (*cmp)(PtrToConstEmployee, void *));
int compareBySalary(PtrToConstEmployee emp, void *targetSalary);

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

    // Seach by Name
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if(matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %ld\n", matchPtr - EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");

    // Match of Search by Salary
    double targetSalary = 8.78;
    matchPtr = searchEmployeeGeneric(EmployeeTable, EmployeeTableEntries, &targetSalary, compareBySalary);
    if(matchPtr != NULL)
        printf("Employee with salary %.2f is in record %ld\n", targetSalary, matchPtr - EmployeeTable);
    else
        printf("Salary %.2f is NOT found in the record\n", targetSalary);

    // Match of Search by Salary
    targetSalary = 100.00;
    matchPtr = searchEmployeeGeneric(EmployeeTable, EmployeeTableEntries, &targetSalary, compareBySalary);
    if(matchPtr != NULL)
        printf("Employee with salary %.2f is in record %ld\n", targetSalary, matchPtr - EmployeeTable);
    else
        printf("Salary %.2f is NOT found in the record\n", targetSalary);

    return EXIT_SUCCESS;
}
