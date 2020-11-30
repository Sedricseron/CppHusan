#include <iostream>

using namespace std;

int main() {
	double b, a;
	int n;
	cin >> b >> n;
	a = b;
	for (int i = 1; i <= n; i++) {
		a = b + 1 / a;
	}
	cout << a;
}