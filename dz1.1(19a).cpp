#include <iostream>

using namespace std;

int onestep(double x) {
	if (x >= 0) return 1;
	if (x < 0) return 0;
}

int main() {
	double x;
	cin >> x;
	cout << "onestep: " << onestep(x) << endl << "derivate always = 0";
}