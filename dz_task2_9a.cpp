#include <iostream>
#include <cmath>

using namespace std;

bool prime(int k) {
	for (int i = 2; i <= sqrt(k); i++) {
		if (k % i == 0){
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	float b;
	cin >> n;
	int arr[10];
	for (int i = 0; i < n; i++) {
		cout << "[" << i + 1 << "]" << ": ";
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		b = arr[i];
		if ((sqrt(arr[i]) == sqrt(b))&&(arr[i] != 1)){
			if (prime(sqrt(arr[i])) == true){
				cout << arr[i] << endl;
			}
		}
	}
}