#include<iostream>

using namespace std;

int main()
{
	unsigned m;
	cout << "Enter m = ";
	cin >> m;
	int j;
	cout << "Enter j = ";
	cin >> j;
	m &= ~(1 << j);
	cout << m << endl;
	cout << hex << m << endl;
	system("pause");
}