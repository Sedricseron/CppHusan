#include<iostream>
#include<time.h>

using namespace std;

double** ReserveArray(int r, int col) {	double** mas = new double* [r];	for (int i = 0; i < r; i++)		mas[i] = new double[col];	return mas;}
void FreeArray(double** mas, int r) {	for (int i = 0; i < r; i++)		delete[]mas[i];	delete[]mas;}void EnterArray(double** mas, int row, int col){	for (int i = 0; i < row; i++)		for (int j = 0; j < col; j++)		{			mas[i][j] = rand() % 20;		}}
void PrintArray(double** mas, int row, int col){	for (int i = 0; i < row; i++)	{		for (int j = 0; j < col; j++)			cout << "\t" << mas[i][j];		cout << endl;	}}

int FindIndex(double** mas, int row, int col)
{

	double** t = ReserveArray(row, col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			t[i][j] = mas[i][j];
		}
	}
	double max_el = t[0][0];
	int ind_row = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (t[i][j] > max_el) {
				max_el = t[i][j];
				ind_row = i;
			}
		}
	}
	FreeArray(t, row);
	return ind_row;
}

double** DeleteMaxRow(double** mas, int row, int col)
{
	int index = FindIndex(mas, row, col);
	double** t = ReserveArray(row - 1, col);
	for (int i = 0, k = 0; i < row; i++)
	{
		if (i  == index) continue;
		for (int j = 0; j < col; j++)
		{
			t[k][j] = mas[i][j];
		}
		k++;
	}
	FreeArray(mas, row);
	return t;
}

int main()
{
	srand(time(0));
	size_t row, col;	cout << " Enter row = ";	cin >> row;	cout << " Enter col = ";	cin >> col;	double** mas = ReserveArray(row, col);	EnterArray(mas, row, col);	PrintArray(mas, row, col);	mas = DeleteMaxRow(mas, row, col);	cout << "||||||||||||||||||||||||||" << endl;	PrintArray(mas, row, col);	FreeArray(mas, row);	system("pause");
}