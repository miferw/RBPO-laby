#include "ReadPersonSalary.h"
#include <iostream>
using namespace std;
double salary;
unsigned short ReadPersonSalary() {
    cout << "Enter salary: ";
    cin >> salary;
    return salary;
}