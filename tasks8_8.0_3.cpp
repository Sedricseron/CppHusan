#include<iostream>

/**
* ����� �������� ������������� ����� `GetInstance`, ������� ���� ���� ���
* �������������� ����������� � ��������� �������� �������� ���� � ��� ��
* ��������� ������ ��� ������ ������.
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
class Monomial {
	Monomial(const std::string value) : value_(value)
	{
	}

	static Singleton* singleton_;

	std::string value_;


//void ThreadFoo() {
//	// ���� ��� ��������� ��������� �������������.
//	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//	Singleton* singleton = Singleton::GetInstance("FOO");
//	std::cout << singleton->value() << "\n";
//}
//
//void ThreadBar() {
//	// ���� ��� ��������� ��������� �������������.
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