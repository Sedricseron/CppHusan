#include <iostream>

using namespace std;

int main() {
	double a;
	double s = 0;
	double k = 1;
	int i;
	for (i = 1; ; i++) {
		cin >> a;
		if (a == 0) {
			break;
		}
		s = s + a;
		k = k * a;
	}
	cout << "seredne aryf: " << s / (i-1) << endl << "ser. geom: " << pow(k,1.0/((double)i-1.0));
}