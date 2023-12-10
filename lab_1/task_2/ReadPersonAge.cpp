
#include "ReadPersonAge.h"
#include <iostream>
using namespace std;
unsigned short age;
unsigned short ReadPersonAge() {
    unsigned short age;
    cout << "Enter age: ";
    cin >> age;
    return age;
}