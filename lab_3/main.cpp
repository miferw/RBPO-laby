#include<iostream>
#include<cmath>

import Math;
using namespace Math;
int main()
{
	setlocale(LC_ALL, "rus");
	int y;
	std::cout << "�������� z: ";
	std::cin >> y;
	std::cout <<"�����������: " << f((Math::Complex)y) << std::endl;
	std::cout <<"������������: " << f((Math::Rational)y) << std::endl;
	double f2 = f(y);
	std::cout<<"f2: " << f2;
	return 0;

}