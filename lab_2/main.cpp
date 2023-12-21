#include <iostream>
using namespace std;
import Tagoyev1bib21023;

enum Choice {
	Task1 = '1', Task2 = '2', Task3 = '3', Task4 = '4', Task5 = '5'
};

int main()
{
	setlocale(LC_ALL, "rus");
	char k;
	do
	{
		cout << "Выбрать программу для выполнения:\
					\nВвести 1 задание:\t\'1\'\
					\nВвести 2 задание:\t\'2\'\
					\nВвести 3 задание:\t\'3\'\
					\nВвести 4 задание:\t\'4\'\
					\nВвести 5 задание:\t\'5\'\
					\nЗакончить ввод:\t\'k\'" << endl;
		cin >> k;
		switch ((Choice)k) {
			unsigned long long n; double x, eps;
		case Task1:
			cout << "Выбрано 1 задание." << endl
				<< "Ввести x, n и eps:" << endl;
			cin >> x >> n >> eps;
			cout << "f1(x) = " << RBPO::Lab2::Variant18::Task1::f1(x) << endl
				<< "f2(x) = " << RBPO::Lab2::Variant18::Task1::f2(x) << endl
				<< "f3(n) = " << RBPO::Lab2::Variant18::Task1::f3(n) << endl
				<< "f4(eps) = " << RBPO::Lab2::Variant18::Task1::f4(eps) << endl;
			break;
		case Task2:
			cout << "Выбрано 2 задание." << endl
				<< "Ввести x, n и eps:" << endl;
			cin >> x >> n >> eps;
			cout << "f1(x) = " << RBPO::Lab2::Variant18::Task2::f1(x) << endl
				<< "f2(x) = " << RBPO::Lab2::Variant18::Task2::f2(x) << endl
				<< "f3(n) = " << RBPO::Lab2::Variant18::Task2::f3(n) << endl
				<< "f4(eps) = " << RBPO::Lab2::Variant18::Task2::f4(eps) << endl;
			break;
		case Task3:
			cout << "Выбрано 3 задание." << endl
				<< "Ввести x, n и eps:" << endl;
			cin >> x >> n >> eps;
			cout << "f1(x) = " << RBPO::Lab2::Variant18::Task3::f1(x) << endl
				<< "f2(x) = " << RBPO::Lab2::Variant18::Task3::f2(x) << endl
				<< "f3(n) = " << RBPO::Lab2::Variant18::Task3::f3(n) << endl
				<< "f4(eps) = " << RBPO::Lab2::Variant18::Task3::f4(eps) <<endl;
			break;
		case Task4:
			cout << "Выбрано 4 задание." << endl
				<< "Ввести x, n и eps:" << endl;
			cin >> x >> n >> eps;
			cout << "f1(x) = " << RBPO::Lab2::Variant18::Task4::f1(x) << endl
				<< "f2(x) = " << RBPO::Lab2::Variant18::Task4::f2(x) << endl
				<< "f3(n) = " << RBPO::Lab2::Variant18::Task4::f3(n) << endl
				<< "f4(eps) = " << RBPO::Lab2::Variant18::Task4::f4(eps) << endl;
			break;
		case Task5:
			cout << "Выбрано 5 задание." << endl
				<< "Ввести x, n и eps:" << endl;
			cin >> x >> n >> eps;
			cout << "f1(x) = " << RBPO::Lab2::Variant18::Task5::f1(x) << endl
				<< "f2(x) = " << RBPO::Lab2::Variant18::Task5::f2(x) << endl
				<< "f3(n) = " << RBPO::Lab2::Variant18::Task5::f3(n) << endl
				<< "f4(eps) = " << RBPO::Lab2::Variant18::Task5::f4(eps) <<endl;
			break;
		case 'k':
			break;
		default:
			cout << "Данные неверны." << endl;
			break;
		}
	} while (k != 'k');
	return 0;
};
