#include "ReadPersonName.h"
#include <iostream>
#include <string>
using namespace std;
std::string name; //����� �������� �� ����� ������������ ����
string ReadPersonName() {
   
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    return name;
}