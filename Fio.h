#pragma once
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Fio
{
	friend ostream& operator <<(ostream&,  Fio);
	friend istream& operator >> (istream& , Fio);
private:
	string name;
	string surname;
	string patronomic;
	
public :
	Fio();
	Fio(string, string, string);
	string GetName();
	void SetName(string);
	string GetSurname();
	void SetSurname(string);
	string GetPatronomic();
	void SetPatronomic(string);

};

