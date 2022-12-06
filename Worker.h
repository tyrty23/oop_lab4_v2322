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
	static int counter_worker;
	static int GetCounter();
	int GetNum_dep();
	void SetNum_dep(int);

	Worker();
	Worker(Fio, int, double);
	void load(ifstream&) override;
	static void line();
	void Add(Common**)override;
	void print() override;
	bool Find(string) override;
	void Save(ofstream&) override;
};	  

