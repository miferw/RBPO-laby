#include "ReadPersonName.h"
#include "ReadPersonAge.h"
#include "ReadPersonSalary.h"
#include "ReadPersonHeight.h"
#include "ReadPersonWeight.h"
#include <iostream>
#include <string>
using namespace std;
void ReadPersonData(string& name, unsigned short& age, double& salary) {//���, �������, ��������
    name = ReadPersonName();
    age = ReadPersonAge();
    salary = ReadPersonSalary();
}