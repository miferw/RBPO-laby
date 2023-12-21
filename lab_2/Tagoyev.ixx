module;
#include <cmath>
export module Tagoyev1bib21023;

export import :F1;
export import :F2;
export import :A;
export import :F3;
export import :F4;


namespace RBPO {
	namespace Lab2 {
		namespace Variant18 {
			namespace Task1 {
				export double f1(double);
				export double f2(double);
				export double f3(unsigned long long);
				export double f4(double);
				double a(long long);
			};
			export namespace Task2 {
				double f1(double);
				double f2(double);
				double f3(unsigned long long);
				double f4(double);
			};
			namespace Task3 {
				export double f1(double);
				export double f2(double);
				export double f3(unsigned long long);
				export double f4(double);
				double a(long long);
			};
			namespace Task5 {
				export double f1(double);
				export double f2(double);
				export double f3(unsigned long long);
				export double f4(double);
				double a(long long);
			};
			namespace Task1 {
				double f1(double x) {
					return ((x + 2) / sqrt(2 * x) - x / (sqrt(2 * x) + 2) + 2 / (x - sqrt(2 * x))) * (sqrt(x) - sqrt(2)) / (x + 2);
				};

				double f2(double x) {
					if (x <= -3) {
						return -x * x - 1.1 * x + 9;
					}
					else {
						return log(x + 3) / (x * x + 9);
					}
				};

				double f3(unsigned long long n) {
					double sum = a(0);
					for (unsigned long long i = 0; i < n; sum += a(++i));
					return sum;
				};

				double f4(double eps) {
					double sum = a(0); unsigned long long i = 2;
					for (double temp = a(1), temp1 = a(2); eps < std::abs(temp - temp1); sum += temp, temp = temp1, temp1 = a(++i));
					return sum;
				};

				double a(long long i) {
					double numerator = pow(-1, i) * (i + 1);
					double denominator = i * i * i - i * i + 1;
					return numerator / denominator;
				};
			};
		};
	};
};

module :private;

namespace RBPO {
	namespace Lab2 {
		namespace Variant18 {
			namespace Task5 {
				double f1(double x) {
					return ((x + 2) / sqrt(2 * x) - x / (sqrt(2 * x) + 2) + 2 / (x - sqrt(2 * x))) * (sqrt(x) - sqrt(2)) / (x + 2);
				};

				double f2(double x) {
					if (x <= -3) {
						return -x * x - 1.1 * x + 9;
					}
					else {
						return log(x + 3) / (x * x + 9);
					}
				};

				double f3(unsigned long long n) {
					double sum = a(0);
					for (unsigned long long i = 0; i < n; sum += a(++i));
					return sum;
				};

				double f4(double eps) {
					double sum = a(0); unsigned long long i = 2;
					for (double temp = a(1), temp1 = a(2); eps < std::abs(temp - temp1); sum += temp, temp = temp1, temp1 = a(++i));
					return sum;
				};

				double a(long long i) {
					double numerator = pow(-1, i) * (i + 1);
					double denominator = i * i + 1;
					return numerator / denominator;
				};
			};
		};
	};
};