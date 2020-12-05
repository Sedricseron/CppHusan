#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int** x = new int* [n];
	for (int i = 0; i < n; i++)
		x[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> x[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			float b;
			b = x[i][j];
			x[i][j] = x[i][n - 1 - j];
			x[i][n - 1 - j] = b;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << x[i][j] << " ";
		cout << endl;
	}
}