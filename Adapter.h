#include <iostream>
#include <tchar.h>
#include <atlstr.h>

//Client
class Target
{
public:
	virtual void SayChinese() 
	{ 
		std::cout << "say Chinese\n";
	}
};

// translator/interpreter
class Adaptee
{
public:
	void SayEnglish()
	{
		std::cout << "say English\n";
	}
};

class Adatper : Target
{
private:
	Adaptee* pAdaptee;
public:
	Adatper(Adaptee* pAdaptee) { this->pAdaptee = pAdaptee; }
	void SayChinese() { pAdaptee->SayEnglish(); }
};

int main()
{
	Adaptee pAdaptee;
	Adatper objAdatper(&pAdaptee);
	objAdatper.SayChinese();
}