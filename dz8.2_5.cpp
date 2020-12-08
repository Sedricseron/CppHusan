#include<iostream>
#include<cmath>
#include <vector>
#include<string>

using namespace std;

class Point {
private:
	double x;
	double y;
public:

	Point() {
		x = 0;
		y = 0;
	}

	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}

	Point(const Point& p) {
		this->x = p.GetX();
		this->y = p.GetY();
	}

	void SetX(double x) {
		this->x = x;
	}

	double GetX() const {
		return this->x;
	}

	void SetY(double y) {
		this->y = y;
	}

	double GetY() const {
		return this->y;
	}

	void Input() {
		cout << "Enter Point (x,y) = ";
		cin >> this->x >> this->y;
		cin.ignore();
	}

	void Show() {
		cout << "Point (" << this->x << ", " << this->y << ")" << endl;
	}

	Point
		Add(const Point& p) {
		Point tmp;
		tmp.SetX(this->x + p.GetX());
		tmp.SetY(this->y + p.GetY());
		return tmp;
	}

	Point Diff(const Point& p) {
		Point tmp;
		tmp.SetX(this->x - p.GetX());
		tmp.SetY(this->y - p.GetY());
		return tmp;
	}
};


int main() {
	double p = 0.0;
	string answer;
	vector <Point> a;
	while (1) {
		cout << "input point?";
		getline(cin, answer);
		if (answer == "No") break;
		Point t;
		t.Input();
		a.push_back(t);
	}
	for (int i = 0; i < a.size(); i++) {
		p = p + sqrt(pow((a[i].GetX() - a[(i + 1) % a.size()].GetX()), 2) + pow((a[i].GetY() - a[(i + 1) % a.size()].GetY()), 2));
	}
	cout << endl << "number of points: " << a.size() << endl;
	cout << "perimetr" << p;

	system("pause");
}