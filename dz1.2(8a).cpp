#include <iostream>

using namespace std;

int main() {
	int n;
	double a = 2;
	cin >> n;
	for (int i = 1; i < n; i++) {
		a = 2 + sqrt(a);
	}
	cout << sqrt(a);
}