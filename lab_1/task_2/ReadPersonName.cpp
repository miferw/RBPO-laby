#include "ReadPersonName.h"
#include <iostream>
#include <string>
using namespace std;
std::string name; //ÿâíîå óêàçàíèå íà ÷àñòü ïðîñòðàíñòâà èìåí
string ReadPersonName() {
   
    cout << "Enter name: ";
    cin >> name;
    return name;
}
