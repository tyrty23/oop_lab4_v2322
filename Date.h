#pragma once
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Date
{
	friend ostream& operator <<(ostream&, Date);
	friend istream& operator >> (istream&, Date);

private:
	int day;
	string month;
	int year;
public:
	Date();
	Date(int, string, int);
	int GetDay();
	void SetDay(int);
	string GetMonth();
	void SetMonth(string);
	int GetYear();
	void SetYear(int);
};

