#pragma once
#include "Common.h"

using namespace std;

class Worker: public Common
{
	friend istream& operator >> (std::istream&, Worker&);
	friend ostream& operator << (std::ostream&, Worker&);
private:
	int num_dep;
public:
	static int counter;
	int GetNum_dep();
	void SetNum_dep(int);

	Worker();
	Worker(Fio, int,Date, double);
	void load(ifstream&) override;
	void line() override;
	void print() override;
	bool Find(string) override;
	void Save(ofstream&) override;
	int GetCounter()override;
};	  

