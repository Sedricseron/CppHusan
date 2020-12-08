#include <iostream>
#include <exception>
#include <random>
#include <utility>


using namespace std;

class Time {
private:
    int hour, min, sec;

public:
    Time() = default;
    Time(int hour, int min, int sec) :
        hour(hour), min(min), sec(sec) {
        if (hour < 0 || hour > 24 || min < 0
            || min > 60 || sec < 0 || sec > 60) {
            throw std::invalid_argument("Wrong data");
        }
    }

    Time operator+(const Time& val) const {
        return Time(((val.hour + hour) + (val.min + min + (val.sec + sec) / 60) / 60) % 24,
            (val.min + min + (val.sec + sec) / 60) % 60,
            (val.sec + sec) % 60);
    }



    friend ostream& operator<< (ostream& out, const Time& c) {
        out << c.hour << ':' << c.min << ':' << c.sec;
        return out;
    }

    friend istream& operator>> (istream& in, Time& c) {
        in >> c.hour >> c.min >> c.sec;
        return in;
    }

    const int& getHour() const {
        return hour;
    }

    void setHour(const int& hour) {
        if (hour < 0 || hour > 24) {
            throw std::invalid_argument("Wrong hour argument");
        }
        Time::hour = hour;
    }

    const int& getMin() const {
        return min;
    }

    void setMin(const int& min) {
        if (min < 0 || min > 60) {
            throw std::invalid_argument("Wrong minute argument");
        }
        Time::min = min;
    }

    const int& getSec() const {
        return sec;
    }

    void setSec(const int& sec) {
        if (sec < 0 || sec > 60) {
            throw std::invalid_argument("Wrong second argument");
        }
        Time::sec = sec;
    }
};

class Date {
private:
    int year, month, day;

public:
    Date() = default;
    Date(int day, int month, int year) :
        year(year), month(month), day(day) {
        if (day < 0 || day > 31 || month < 0 || month > 12) {
            throw std::invalid_argument("Wrong data");
        }
    }

    Date operator+(const Date& val) const {
        return Date((val.year + year) + (val.month + month + (val.day + day) / 30)/ 12,
            (val.month + month + (val.day + day) / 30) % 12,
            (val.day + day) % 30);
    }

    friend ostream& operator<< (ostream& out, const Date& c) {
        out << c.year << '-' << c.month << '-' << c.day;
        return out;
    }

    friend istream& operator>> (istream& in, Date& c) {
        in >> c.year >> c.month >> c.day;
        return in;
    }

    int getYear() const {
        return year;
    }

    void setYear(int year) {
        Date::year = year;
    }

    int getMonth() const {
        return month;
    }

    void setMonth(int  month) {
        if (month < 0 || month > 12) {
            throw std::invalid_argument("Wrong month argument");
        }
        Date::month = month;
    }

    int getDay() const {
        return day;
    }

    void setDay(int day) {
        if (day < 0 || day > 31) {
            throw std::invalid_argument("Wrong day argument");
        }
        Date::day = day;
    }
};

class Currency {
private:
    std::string name;
    int value, cent;

public:
    Currency() = default;
    Currency(std::string name, int value, int cent) :
        name(std::move(name)), value(value), cent(cent) {
        if (cent < 0 || cent > 100) {
            throw std::invalid_argument("Wrong data");
        }
    }

    Currency operator+(const Currency& val) const {
        if (name == val.name) {
            return Currency(name, (val.value + value + (val.cent + cent) / 100),
                (val.cent + cent) % 100);
        }
        else {
            throw std::logic_error("Cannot add different currencies");
        }
    }

    friend ostream& operator<< (ostream& out, const Currency& c) {
        out << c.name << '.' << c.value << '.' << c.cent;
        return out;
    }

    friend istream& operator>> (istream& in, Currency& c) {
        in >> c.name >> c.value >> c.cent;
        return in;
    }

    const string& getName() const {
        return name;
    }

    void setName(const string& name) {
        Currency::name = name;
    }

    int getValue() const {
        return value;
    }

    void setValue(int value) {
        Currency::value = value;
    }

    int getCent() const {
        return cent;
    }

    void setCent(int cent) {
        if (cent < 0 || cent > 12) {
            throw std::invalid_argument("Wrong month argument");
        }
        Currency::cent = cent;
    }
};


int main() {
    Time t1, t2, t3;
    cout << "input hour, min, sec of t1, then input hour, min, sec of t2" << endl;
    cin >> t1 >> t2;
    t3 = t1 + t2;
    cout << "t1 + t2" << endl;
    cout << t3 << endl;
    Date d1, d2, d3;
    cout << "input year, month, day of d1, then input how many years, months and days you want to +" << endl;
    cin >> d1 >> d2;
    d3 = d1 + d2;
    cout << "d1 + d2" << endl;
    cout << d3 << endl;
    Currency c1, c2, c3;
    cout << "input name, value, cent of c1, then input c2" << endl;
    cin >> c1 >> c2;
    c3 = c1 + c2;
    cout << "c1 + c2" << endl;
    cout << c3 << endl;
}