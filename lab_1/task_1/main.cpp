

#include <iostream>
#include <string>
using namespace std;

unsigned short ReadPersonAge() {
    unsigned short age;
    cout << "Enter age: ";
    cin >> age;
    return age;
}


string ReadPersonName() {
    string name;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    return name;
}


void ReadPersonHeight(unsigned short& height) {
    cout << "Enter height: ";
    cin >> height;
}


void ReadPersonWeight(unsigned short& weight) {
    cout << "Enter weight: ";
    cin >> weight;
}


double salary; 

void ReadPersonSalary() {
    cout << "Enter salary: ";
    cin >> salary;
}


void ReadPersonData(string& name, unsigned short& age, double& salary) {
    name = ReadPersonName();
    age = ReadPersonAge();
    salary = ::salary; 
}


void ReadPersonData(string& name, unsigned short& age, unsigned short& height, unsigned short& weight, double& salary) {//Имя, возраст, рост, вес и зарплата
    name = ReadPersonName();
    age = ReadPersonAge();
    ReadPersonHeight(height);
    ReadPersonWeight(weight);
    salary = ::salary; 
}


void WritePersonData(const string& name, unsigned short age, unsigned short height, unsigned short weight, double salary) {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Height: " << height << endl;
    cout << "Weight: " << weight << endl;
    cout << "Salary: " << salary << endl;
}


#ifndef DO_NOT_DEFINE_MAIN

int main() {
    string name;
    unsigned short age, height, weight;
    ReadPersonData(name, age, height, weight, salary);
    WritePersonData(name, age, height, weight, salary);
    return 0;
}
#endif 
