#include <iostream>
#include <fstream>
#include<string>
#include <list>
#include<vector>
using namespace std;


class Person
{
public:
	string name;
	unsigned year;

	void input() {
		cout << "Name:";
		cin >> name;
		cout << "\nYear: ";
		cin >> year;
	}

	void print() {
		cout << name << "," << year << endl;
	}
};

class Familiar : public Person
{
public:
	string phone_number;

	void input1() {
		Person::input();
		cout << "\nPhone number: ";
		cin >> phone_number;
	}

	void print() {
		Person::print();
		cout << phone_number << endl;
	}
};

vector<Familiar> CreateDictionary(int n) {
	vector<Familiar> dct;
	Familiar a;
	for (int i = 0; i < n; i++) {
		a.input1();
		dct.push_back(a);
	}
	return dct;
}

void Add_Familiar(vector<Familiar> &dct, Familiar a) {
	dct.push_back(a);
}

void Find_Number(vector<Familiar> dct, string name) {
	for (int i = 0; i < dct.size(); i++) {
		if (dct[i].name == name) cout << dct[i].phone_number << endl;
	}
}

void Change_Number(vector<Familiar> &dct, string name, string number) {
	for (int i = 0; i < dct.size(); i++) {
		if (dct[i].name == name) dct[i].phone_number = number;
	}
}



int main() {
	vector<Familiar> dct;
	Familiar a;
	string name, number;
	int n;
	cout << "kilkist familiars: ";
	cin >> n;
	dct = CreateDictionary(n);
	cout << "add familiar: " << endl;
	a.input1();
	Add_Familiar(dct, a);
	cout << "name of familiar for finding phone number: ";
	cin >> name;
	Find_Number(dct, name);
	cout << "name for changing: ";
	cin >> name;
	cout << "number of changing: ";
	cin >> number;
	Change_Number(dct, name, number);
	for (int i = 0; i < dct.size(); i++) {
		cout << dct[i].name << ": " << dct[i].phone_number << endl;
	}
}
