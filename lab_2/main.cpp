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
		cout << "������� ��������� ��� ����������:\
					\n������ 1 �������:\t\'1\'\
					\n������ 2 �������:\t\'2\'\
					\n������ 3 �������:\t\'3\'\
					\n������ 4 �������:\t\'4\'\
					\n������ 5 �������:\t\'5\'\
					\n��������� ����:\t\'k\'" << endl;
		cin >> k;
		switch ((Choice)k) {
			unsigned long long n; double x, eps;
		case Task1:
			cout << "������� 1 �������." << endl
				<< "������ x, n � eps:" << endl;
			cin >> x >> n >> eps;
			cout << "f1(x) = " << RBPO::Lab2::Variant18::Task1::f1(x) << endl
				<< "f2(x) = " << RBPO::Lab2::Variant18::Task1::f2(x) << endl
				<< "f3(n) = " << RBPO::Lab2::Variant18::Task1::f3(n) << endl
				<< "f4(eps) = " << RBPO::Lab2::Variant18::Task1::f4(eps) << endl;
			break;
		case Task2:
			cout << "������� 2 �������." << endl
				<< "������ x, n � eps:" << endl;
			cin >> x >> n >> eps;
			cout << "f1(x) = " << RBPO::Lab2::Variant18::Task2::f1(x) << endl
				<< "f2(x) = " << RBPO::Lab2::Variant18::Task2::f2(x) << endl
				<< "f3(n) = " << RBPO::Lab2::Variant18::Task2::f3(n) << endl
				<< "f4(eps) = " << RBPO::Lab2::Variant18::Task2::f4(eps) << endl;
			break;
		case Task3:
			cout << "������� 3 �������." << endl
				<< "������ x, n � eps:" << endl;
			cin >> x >> n >> eps;
			cout << "f1(x) = " << RBPO::Lab2::Variant18::Task3::f1(x) << endl
				<< "f2(x) = " << RBPO::Lab2::Variant18::Task3::f2(x) << endl
				<< "f3(n) = " << RBPO::Lab2::Variant18::Task3::f3(n) << endl
				<< "f4(eps) = " << RBPO::Lab2::Variant18::Task3::f4(eps) <<endl;
			break;
		case Task4:
			cout << "������� 4 �������." << endl
				<< "������ x, n � eps:" << endl;
			cin >> x >> n >> eps;
			cout << "f1(x) = " << RBPO::Lab2::Variant18::Task4::f1(x) << endl
				<< "f2(x) = " << RBPO::Lab2::Variant18::Task4::f2(x) << endl
				<< "f3(n) = " << RBPO::Lab2::Variant18::Task4::f3(n) << endl
				<< "f4(eps) = " << RBPO::Lab2::Variant18::Task4::f4(eps) << endl;
			break;
		case Task5:
			cout << "������� 5 �������." << endl
				<< "������ x, n � eps:" << endl;
			cin >> x >> n >> eps;
			cout << "f1(x) = " << RBPO::Lab2::Variant18::Task5::f1(x) << endl
				<< "f2(x) = " << RBPO::Lab2::Variant18::Task5::f2(x) << endl
				<< "f3(n) = " << RBPO::Lab2::Variant18::Task5::f3(n) << endl
				<< "f4(eps) = " << RBPO::Lab2::Variant18::Task5::f4(eps) <<endl;
			break;
		case 'k':
			break;
		default:
			cout << "������ �������." << endl;
			break;
		}
	} while (k != 'k');
	return 0;
};
