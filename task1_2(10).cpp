#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int m, k = 0;
	cout << "Enter m = ";
	cin >> m;
	while (pow(4, k) <= m)
	{
		k++;
	}
	//������ �� ����� ���� ������� ������, ��� ��� ��� ������
	cout << "k = " << k-1 << endl;
	system("pause");
}
