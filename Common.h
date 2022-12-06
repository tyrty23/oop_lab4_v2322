#pragma once
#include "Date.h"
#include "Fio.h"

#include <iostream>
#include <fstream>



class Common
{
	friend ostream& operator <<(ostream&, Common);
	friend istream& operator >> (istream&, Common);

protected:
	Fio fio;
	double salary;

public:
	Common();
	Common(Fio, double);
	double Getsalary();
	void Setsalary(double);
	virtual void load(ifstream&);
	virtual void Save(ofstream&);
	static int right_int();
	virtual void Add(Common**);
	virtual void print();
	virtual bool Find(string);
	static void Sort(Common***,int ,int);
};

