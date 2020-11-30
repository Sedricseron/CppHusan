#include <iostream>

using namespace std;

int main() {
	double x;
	int n;
	cin >> x >> n;
	double f = x;
	cout << f << endl;
	for (int i = 1; i < n; i++) {
		f = f * x * x / (2 * i) / (2 * i + 1);
		cout << f<< endl;
	}
}