#include <iostream>
#include <cmath>

using namespace std;

double sigmweight(double x) {
	return (x * pow(1 + pow(2.71, -x), -1));
}
double sigmweight_derivative(double x) {
	return (pow(1 + pow(2.71, -x), -1) + x * pow(2.71, -x) * pow(1 + pow(2.71, -x), -1));
}

int main() {
	double x;
	cin >>  x;
	cout << sigmweight(x) << endl << sigmweight_derivative(x);
}

