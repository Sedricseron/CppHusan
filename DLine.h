#pragma once
#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <climits>

using namespace std;

class DLine {
private:
    double a, b, c;

public:

    DLine() : a(0.0), b(0.0), c(0.0) {}

    DLine(double a, double b, double c) : a(a), b(b), c(c) {}

    double abs();

    bool operator > (DLine& d1);

    bool operator < (DLine& d1);

    bool operator == (DLine& d1);

    friend ostream& operator << (ostream& stream, DLine t);

};

const DLine dline_minv(0.0, 0.0, 0.0);