module;
#include <cmath>

module Tagoyev1bib21023;

namespace RBPO {
	namespace Lab2 {
		namespace Variant18 {
			namespace Task3 {
				double f1(double);
			};
		};
	};
};

double RBPO::Lab2::Variant18::Task3::f1(double x) {
	return ((x + 2) / sqrt(2 * x) - x / (sqrt(2 * x) + 2) + 2 / (x - sqrt(2 * x))) * (sqrt(x) - sqrt(2)) / (x + 2);
};
