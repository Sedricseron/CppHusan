#include <iostream>

using namespace std;

int same(double a, double b, double c) {
	int i = 0;
	if (a == b) i++;
	if (b == c) i++;
	if (a == c) i++;
	return i;
}

int serarf(double a, double b, double c) {
	int i = 0;
	double m = (a + b + c) / 3;
	if (a > m) i++;
	if (b > m) i++;
	if (c > m) i++;
	return i;
}

int bigthen(double a, double b, double c, double x) {
	int i = 0;
	if (a > x) i++;
	if (b > x) i++;
	if (c > x) i++;
	return i;
}

int main() {
	double a, b, c, x;
	cin >> a >> b >> c >> x;
	cout << "odnakovi: " << same(a, b, c) << endl << "rizni: " << 3 - same(a, b, c) << endl << "bilshi za sered. aryfm.: " << serarf(a, b, c) << endl << "bigger then: " << bigthen(a, b, c, x);
}