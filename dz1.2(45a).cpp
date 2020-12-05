#include <iostream>
#include <cmath>

using namespace std;

double factorial(double f)
{
	if (f == 0)
		return 1;
	return(f * factorial(f - 1));
}

int main() {
	double e, x;
	int i = 1;
	cin >> x >> e;
	double s = x;
	while (abs(sin(x) - s) >= e) {
		s = s + pow(-1, i) * pow(x, 2 * i + 1) / factorial(2 * i + 1);
		i++;
	}
	cout << s;
}