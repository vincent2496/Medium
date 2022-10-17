#include <iostream>
#include <tchar.h>
#include <atlstr.h>

class Target
{
public:
	virtual void SayChinese() = 0;
};

//the one which be adapter
class Adaptee
{
public:
	void SayEnglish()
	{
		std::cout << "say English\n";
	}
};

// translator/interpreter
class Adatper : Target
{
private:
	Adaptee* pAdaptee;
public:
	Adatper(Adaptee* pAdaptee) { this->pAdaptee = pAdaptee; }
	void SayChinese() { pAdaptee->SayEnglish(); }
};

//Client
int main()
{
	Adaptee pAdaptee;
	Adatper objAdatper(&pAdaptee);
	objAdatper.SayChinese();
}