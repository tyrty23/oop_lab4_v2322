#pragma once
#include "Common.h"

using namespace std;

class Personnel :public Common
{
	friend bool operator==(Personnel, Fio);

	friend istream& operator >> (std::istream&, Personnel&);
	friend ostream& operator << (std::ostream&, Personnel&);
private:
	string proffesion;
public:
	static int counter;
	 int GetCounter() override;

	Personnel();
	Personnel(Fio, string, Date,double);
	void load(ifstream&) override;
	void print() override;
	void SetProffesion(string);
	string GetProffesion();
	bool Find(string) override;
	void line() override;
	void Save(ofstream&) override;
};

