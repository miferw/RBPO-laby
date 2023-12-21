module;
#include <cmath>

module Tagoyev1bib21023;

namespace RBPO {
    namespace Lab2 {
        namespace Variant18 {
            namespace Task2 {
                double f1(double);
                double f2(double);
                double f3(unsigned long long);
                double f4(double);
                double a(long long);
            };
        };
    };
};

double RBPO::Lab2::Variant18::Task2::f1(double x) {
    return ((x + 2) / sqrt(2 * x) - x / (sqrt(2 * x) + 2) + 2 / (x - sqrt(2 * x))) * (sqrt(x) - sqrt(2)) / (x + 2);
}

double RBPO::Lab2::Variant18::Task2::f2(double x) {
    if (x <= -3) {
        return -x * x - 1.1 * x + 9;
    }
    else {
        return log(x + 3) / (x * x + 9);
    }
}

double RBPO::Lab2::Variant18::Task2::f3(unsigned long long n) {
    double sum = a(0); unsigned long long i = 0;
    while (i < n)
        sum += a(++i);
    return sum;
}

double RBPO::Lab2::Variant18::Task2::f4(double eps) {
    double sum = a(0), temp = a(1), temp1 = a(2); unsigned long long i = 2;
    while (eps < abs(temp - temp1))
        sum += temp, temp = temp1, temp1 = a(++i);
    return sum;
}

double RBPO::Lab2::Variant18::Task2::a(long long i) {
    double numerator = pow(-1, i) * (i + 1);
    double denominator = i * i + 1;
    return numerator / denominator;
}
