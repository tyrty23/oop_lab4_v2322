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
	Date date;
public:
	static int counter_personnel;
	static int GetCounter();

	Personnel();
	Personnel(Fio, string, Date,double);
	static void PrintAll(Personnel*);
	void load(ifstream&) override;
	void Add(Common**)override;
	void print() override;
	void SetProffesion(string);
	string GetProffesion();
	bool Find(string) override;
	static void line();
	void Save(ofstream&) override;
};

