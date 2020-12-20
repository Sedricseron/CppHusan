#include "DLine.h"

double DLine::abs()
{
    return sqrt(a * a + b * b + c * c);
}

bool DLine::operator > (DLine& d1)
{
    return this->abs() > d1.abs();
}

bool DLine::operator < (DLine& d1)
{
    return this->abs() < d1.abs();
}

bool DLine::operator == (DLine& d1)
{
    return d1.a == a && d1.b == b && d1.c == c;
}

ostream& operator << (ostream& stream, DLine t)
{
    stream << "DLine(a=" << t.a << ",b=" << t.b << ",c=" << t.c << ")";
    return stream;
}