#include "Common.h"

Common::Common()
{
	Fio();
	salary = 1200.8;
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
	int n;
	string buff;
	/*cout << "Введите целое число: ";*/
	cin >> buff;
	try {
		for (int i = 0; i < buff.length(); i++)
		{
			if (!isdigit(buff[i]))
			{
				throw "Непонятные символы";
			}
		}
		return atoi(buff.c_str());
	}
	catch (const char* msg) {
		cout << msg << endl;
		cout << "Введите целое число: ";
		n = right_int();
		return n;
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

double Common::right_double()
{
	string buff;
	//cout << "Введите число типа double: ";
	cin >> buff;
	while (true) {
		if (atof(buff.c_str()) != false) { return atof(buff.c_str()); }
		else {
			cout << "Введите число типа double: ";
			cin >> buff;
		}
	}


	//int n;
	//string buff;
	///*cout << "Введите целое число: ";*/
	//cin >> buff;
	//try {
	//	for (int i = 0; i < buff.length(); i++)
	//	{
	//		if ((!isdigit(buff[i])) || (buff[i] != '.'))
	//		{
	//			throw "Непонятные символы";
	//		}
	//	}
	//	return atof(buff.c_str());
	//}
	//catch (const char* msg) {
	//	cout << msg << endl;
	//	cout << "Введите число типа double: ";
	//	n = right_double();
	//	return n;
	//}
}

string Common::right_fio(string fio)
{
	try {
		for (int i = 0; i < fio.length(); i++)
		{
			if (isdigit(fio[i]))
			{
				throw "Непонятные символы";
			}
			
		}
		return fio;
	}
	catch (const char* msg) {
		cout << msg<<endl;
		cout << "Введите нормальное слово: ";
		string buff;
		cin >> buff;
		buff = right_fio(buff);
		return buff;
	}
}

int Common::GetCounter()
{
	return 0;
}

void Common::line()
{
}

void Common::GetByDate(Common*** ar,Date dat)
{
	int base_dat = dat.GetDays();
	for (int a = 0; a < 2; a++) {
		ar[a][0]->line();
		for (int i = 0; i < ar[a][0]->GetCounter(); i++)
			if((-ar[a][i]->date.GetDays() + base_dat)>3650)
				ar[a][i]->print();
	}
}

