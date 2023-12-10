
#include "ReadPersonName.h"
#include "ReadPersonAge.h"
#include "ReadPersonSalary.h"
#include "ReadPersonHeight.h"
#include "ReadPersonWeight.h"
#include <iostream>
#include <string>
using namespace std;
/*void ReadPersonData(string& name, unsigned short& age, double& salary) {//Имя, возраст, зарплата
    name = ReadPersonName();
    age = ReadPersonAge();
    salary = ReadPersonSalary();
}*/

void ReadPersonData(string& name, unsigned short& age, unsigned short& height, unsigned short& weight, double& salary) {
    name = ReadPersonName();
    age = ReadPersonAge();
    height= ReadPersonHeight(height);
    weight=ReadPersonWeight(weight);
    salary = ReadPersonSalary();
   
}