
#include <iostream>
using namespace std;
unsigned short weight;
unsigned short ReadPersonWeight(unsigned short & weight) {
    cout << "Enter weight: ";
    cin >> weight;
    return weight;
}