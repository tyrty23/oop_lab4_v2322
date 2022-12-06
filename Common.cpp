#include "Common.h"

Common::Common()
{
	Fio();
} 

double Common::Getsalary()
{
	return this->salary;
}

void Common::Setsalary(double s)
{
	this->salary = s;
}
Common::Common(Fio fio1,double s )
{
	fio = { fio1.GetName(),fio1.GetSurname(),fio1.GetPatronomic() };
	salary = s;
}

void Common::load(ifstream&)
{
}

void Common::Save(ofstream&)
{
}

ostream& operator<<(ostream& out, Common c) 
{
	out << c.fio;
	return out;
}

istream& operator>>(istream& in, Common c)
{
	in >> c.fio;
	return in;
}

int Common::right_int()
{
	string buff;
	/*cout << "¬ведите целое число: ";*/
	cin >> buff;
	while (true) {
		if (atoi(buff.c_str()) != false) { return atoi(buff.c_str()); }
		else {
			cout << "¬ведите целое число: ";
			cin >> buff;
		}
	}
}

void Common::Add(Common**)
{
}

void Common::print()
{
}

bool Common::Find(string)
{
	return false;
}

void Common::Sort(Common*** ar,int counter_worker,int counter_personnel)
{
	Common* test;
	for (int i = 0; i < counter_worker; i++)
		for (int a = 0; a < counter_worker; a++)
			if (ar[0][a]->salary < ar[0][i]->salary) {
				test = ar[0][a];
				ar[0][a] = ar[0][i];
				ar[0][i] = test;
			}
	for (int i = 0; i < counter_personnel; i++)
		for (int a = 0; a < counter_personnel; a++)
			if (ar[1][a]->salary < ar[1][i]->salary) {
				test = ar[1][a];
				ar[1][a] = ar[1][i];
				ar[1][i] = test;
			}
}


