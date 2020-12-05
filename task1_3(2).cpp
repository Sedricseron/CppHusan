#include<iostream>

using namespace std;

int main()
{
	unsigned n, k;
	cout << "Enter n, k = ";
	cin >> n >> k;

	n = n | (1 << k);
	cout << n << endl;
	system("pause");
}
