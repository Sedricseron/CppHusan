#include<iostream>

/**
*  ласс ќдиночка предоставл€ет метод `GetInstance`, который ведЄт себ€ как
* альтернативный конструктор и позвол€ет клиентам получать один и тот же
* экземпл€р класса при каждом вызове.
*/
using namespace std;

class Singleton
{
protected:
	Singleton(const std::string value) : value_(value)
	{
	}

	static Singleton* singleton_;

	std::string value_;

public:

	Singleton(Singleton &other) = delete;
	void operator=(const Singleton &) = delete;

	static Singleton *GetInstance(const std::string& value);
	

	std::string value() const {
		return value_;
	}
};

Singleton* Singleton::singleton_ = nullptr;;

Singleton *Singleton::GetInstance(const std::string& value)
{
	if (singleton_ == nullptr) {
		singleton_ = new Singleton(value);
	}
	return singleton_;
}
class Monomial {protected:
	Monomial(const std::string value) : value_(value)
	{
	}

	static Singleton* singleton_;

	std::string value_;private:	int deg;	double aval;	static int count;public:	Monomial();	~Monomial();	Monomial(int n, double a) : deg(n), aval(a) { count++; };	static int show_count() {		return count;	}	static double power(double x, unsigned n);	static double pi() { return 3.14159265; }	void setDegree(int m) {		deg = m;	}	void setAval(double p) {		aval = p;	}	int getDegree() {		return deg;	}	double getAval() {		return aval;	}	double value(double x) {		return aval*power(x, deg);	}};Monomial::Monomial() {	count++;}Monomial::~Monomial() {	count--;}double Monomial::power(double x, unsigned n) {	if (n == 1) return x;	double res = power(x, n / 2);	if (n & 1) {		return x*res*res;	}	return res * res;}


//void ThreadFoo() {
//	// Ётот код эмулирует медленную инициализацию.
//	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//	Singleton* singleton = Singleton::GetInstance("FOO");
//	std::cout << singleton->value() << "\n";
//}
//
//void ThreadBar() {
//	// Ётот код эмулирует медленную инициализацию.
//	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//	Singleton* singleton = Singleton::GetInstance("BAR");
//	std::cout << singleton->value() << "\n";
//}


int main()
{
	std::cout << "If you see the same value, then singleton was reused (yay!\n" <<
		"If you see different values, then 2 singletons were created (booo!!)\n\n" <<
		"RESULT:\n";
	
	return 0;
}