#include "ReadPersonName.h"
#include <iostream>
#include <string>
using namespace std;
std::string name; //явное указание на часть пространства имен
string ReadPersonName() {
   
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    return name;
}