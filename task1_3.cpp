#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	unsigned long long M;
	unsigned j;

	cin >> M >> j;

	M = M & ~(1 << j);
	printf("M = %Lo %Lx", M, M);

	system("pause");
}
