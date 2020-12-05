#include <iostream>

using namespace std;

double factorial(double f)
{
	if (f == 0)
		return 1;
	return(f * factorial(f - 1));
}

int main() {
	double a1 = 1.0, a0 = 1.0, ak, sum = 3.0;
	int n;
	cout << "Enter n = ";
	cin >> n;
	if (n == 1) {
		cout << "Suma = 1";
		return 1;
	}
	if (n == 2) {
		cout << "Suma = 3";
		return 3;
	}
	double k = 3.0;
	while (k <= n)
	{
		ak = a1 + a0 / pow(2,k);
		sum += (factorial(k) / ak);
		k += 1.0;
		a0 = a1;
		a1 = ak;
	}
	cout << "Suma = " << sum << endl;
	system("pause");
}