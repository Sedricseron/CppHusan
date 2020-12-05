#include<iostream>

using namespace std;

int main()
{
	unsigned char n;

	unsigned long long m;

	cin >> n;
	m = 1 << n;
	cout << "m = " << m << endl;
	system("pause");
}