#include "Fio.h"

Fio::Fio()
{
	name = "Иван";
	surname = "Иванов";
	patronomic = "Иванович";
}

Fio::Fio(string n, string s, string p)
{
	name = n;
	surname = s;
	patronomic = p;
}


string Fio::GetName()
{
	return name;
}

void Fio::SetName(string value)
{
	name = value;
}

string Fio::GetSurname()
{
	return surname;
}

void Fio::SetSurname(string value)
{
	surname = value;
}

string Fio::GetPatronomic()
{
	return patronomic;
}

void Fio::SetPatronomic(string value)
{
	patronomic = value;
}

ostream& operator<<(ostream& out, Fio f)
{
	out << setw(10) << f.surname
		<< setw(10) << f.name
		<< setw(15) << f.patronomic;
	return out;
}

istream& operator>>(istream& in, Fio f)
{
	in >> f.name >> f.surname >> f.patronomic;
	return in;
}
