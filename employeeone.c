#include <string.h>
#include "employee.h"

typedef int (*CompareFunction)(PtrToConstEmployee, void *);

PtrToEmployee searchEmployeeGeneric(const Employee table[], int sizeTable, void *target, CompareFunction cmpFn) {
    const PtrToConstEmployee endPtr = table + sizeTable;
    for (PtrToConstEmployee ptr = table; ptr < endPtr; ptr++) {
        if (cmpFn(ptr, target))
            return (PtrToEmployee) ptr;
    }
    return NULL;
}

int compareByNumber(PtrToConstEmployee emp, void *target) {
    return emp->number == *(long *)target;
}

int compareByName(PtrToConstEmployee emp, void *target) {
    return strcmp(emp->name, (char *)target) == 0;
}

int compareByPhone(PtrToConstEmployee emp, void *target) {
    return strcmp(emp->phone, (char *)target) == 0;
}

int compareBySalary(PtrToConstEmployee emp, void *target) {
    return emp->salary == *(double *)target;
}
