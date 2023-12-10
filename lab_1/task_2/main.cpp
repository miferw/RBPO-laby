
#include "ReadPersonAge.h"
#include "ReadPersonName.h"
#include "ReadPersonHeight.h"
#include "ReadPersonWeight.h"
#include "ReadPersonSalary.h"
#include "ReadPersonData.h"
#include "WritePersonData.h"
#include <iostream>
#include <string>
using namespace std;
int main() {
    unsigned short age;
    //extern - внешние переменные доступны везде, где описаны, а не только там, где определены
    extern string name;
    extern unsigned short height, weight;
    extern double salary;
   
    ReadPersonData(name, age, height, weight, salary);
    WritePersonData(name, age, height, weight, salary);

    return 0;
}
