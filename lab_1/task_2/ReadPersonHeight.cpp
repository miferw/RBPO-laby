
#include "ReadPersonHeight.h"
#include <iostream>
using namespace std;
unsigned short height;
unsigned short ReadPersonHeight(unsigned short &height) {
    cout << "Enter height: ";
    cin >> height;
    return height;
}