#include<iostream>
#include<cmath>

import Math;
using namespace Math;
int main()
{
	setlocale(LC_ALL, "rus");
	int y;
	std::cout << "параметр z: ";
	std::cin >> y;
	std::cout <<"Комплексное: " << f((Math::Complex)y) << std::endl;
	std::cout <<"Рациональное: " << f((Math::Rational)y) << std::endl;
	double f2 = f(y);
	std::cout<<"f2: " << f2;
	return 0;

}