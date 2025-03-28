#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "employee.h"

PtrToEmployee searchEmployeeGeneric(const Employee table[], int sizeTable, void *target, int (*cmp)(PtrToConstEmployee, void *));
int compareByNumber(PtrToConstEmployee, void *);
int compareByName(PtrToConstEmployee, void *);
int compareByPhone(PtrToConstEmployee, void *);
int compareBySalary(PtrToConstEmployee, void *);

extern Employee EmployeeTable[];
extern const int EmployeeTableEntries;

int main(void) {
    PtrToEmployee matchPtr;

    // ID Number - Found
    long idToFind = 1140;
    matchPtr = searchEmployeeGeneric(EmployeeTable, EmployeeTableEntries, &idToFind, compareByNumber);
    printf(matchPtr ? "ID %ld found in record %ld\n" : "ID %ld NOT found\n", idToFind, matchPtr - EmployeeTable);

    // ID Number - Not Found
    idToFind = 9999;
    matchPtr = searchEmployeeGeneric(EmployeeTable, EmployeeTableEntries, &idToFind, compareByNumber);
    printf(matchPtr ? "ID %ld found in record %ld\n" : "ID %ld NOT found\n", idToFind, matchPtr - EmployeeTable);

    // Name - Found
    char *nameToFind = "Tony Bobcat";
    matchPtr = searchEmployeeGeneric(EmployeeTable, EmployeeTableEntries, nameToFind, compareByName);
    printf(matchPtr ? "Name %s found in record %ld\n" : "Name %s NOT found\n", nameToFind, matchPtr - EmployeeTable);

    // Name - Not Found
    nameToFind = "Big Jack";
    matchPtr = searchEmployeeGeneric(EmployeeTable, EmployeeTableEntries, nameToFind, compareByName);
    printf(matchPtr ? "Name %s found in record %ld\n" : "Name %s NOT found\n", nameToFind, matchPtr - EmployeeTable);

    // Phone Number - Found
    char *phoneToFind = "909-555-1235";
    matchPtr = searchEmployeeGeneric(EmployeeTable, EmployeeTableEntries, phoneToFind, compareByPhone);
    printf(matchPtr ? "Phone %s found in record %ld\n" : "Phone %s NOT found\n", phoneToFind, matchPtr - EmployeeTable);

    // Phone Number - Not Found
    phoneToFind = "000-010-0000";
    matchPtr = searchEmployeeGeneric(EmployeeTable, EmployeeTableEntries, phoneToFind, compareByPhone);
    printf(matchPtr ? "Phone %s found in record %ld\n" : "Phone %s NOT found\n", phoneToFind, matchPtr - EmployeeTable);

    // Salary - Found
    double salaryToFind = 4.50;
    matchPtr = searchEmployeeGeneric(EmployeeTable, EmployeeTableEntries, &salaryToFind, compareBySalary);
    printf(matchPtr ? "Salary %.2f found in record %ld\n" : "Salary %.2f NOT found\n", salaryToFind, matchPtr - EmployeeTable);

    // Salary - Not Found
    salaryToFind = 55.0;
    matchPtr = searchEmployeeGeneric(EmployeeTable, EmployeeTableEntries, &salaryToFind, compareBySalary);
    printf(matchPtr ? "Salary %.2f found in record %ld\n" : "Salary %.2f NOT found\n", salaryToFind, matchPtr - EmployeeTable);

    return EXIT_SUCCESS;
}
