module;
#include <cmath>
module Tagoyev1bib21023;

namespace RBPO {
	namespace Lab2 {
		namespace Variant18 {
			namespace Task3 {
				double f2(double);
			};
		};
	};
};

double RBPO::Lab2::Variant18::Task3::f2(double x) {
	if (x <= -3) {
		return -x * x - 1.1 * x + 9;
	}
	else {
		return log(x + 3) / (x * x + 9);
	}
}
