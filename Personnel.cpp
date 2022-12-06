#include "Personnel.h"
int Personnel::counter_personnel = 0;

int Personnel::GetCounter()
{
	return counter_personnel;
}

Personnel::Personnel()
{
	Common();
	proffesion = "���������";
	Date();
}

Personnel::Personnel(Fio fio1, string prof1, Date date1,double sal)
{
	fio = { fio1.GetName(),fio1.GetSurname(),fio1.GetPatronomic() };
	proffesion = prof1;
	date = { date1.GetDay(),date1.GetMonth(),date1.GetYear() };
	salary = sal;
}

void Personnel::load(ifstream& fin)
{
	string n, s, p, m, prof;
	int d, y;
	double sal;
	fin >> n
		>> s
		>> p
		>> prof
		>> d
		>> m
		>> y
		>> sal;
	this->fio.SetName(n);
	this->fio.SetSurname(s);
	this->fio.SetPatronomic(p);
	this->SetProffesion(prof);
	this->date.SetDay(d);
	this->date.SetMonth(m);
	this->date.SetYear(y);
	this->Setsalary(sal);
	counter_personnel++;
}

void Personnel::Add(Common**)
{
	Personnel p;
	cout << "������ ������ ����� � ������� ���, ���������, ���� ������ ����� ������ ��� enter: \n";
	cin >> p;
	counter_personnel++;
}

void Personnel::print()
{
	cout << setw(25) << this->fio
		<< setw(35) << this->proffesion
		<< setw(35) << this->date << setw(20) << this->salary << endl;
}

void Personnel::SetProffesion(string p)
{
	this->proffesion = p;
}

string Personnel::GetProffesion()
{
	return this->proffesion;
}

bool Personnel::Find(string p)
{
	if (this->proffesion == p) {
		return true;
	}
	return false;
}

//void Personnel::Find(Personnel* ar)
//{
//	bool l = 0;
//	string test;
//	Fio test1;
//	cout << "������ ������� ����������: ";
//	cin >> test;
//	test1.SetSurname(test);
//	for (int i = 0; i < counter_personnel; i++)
//		if (ar[i] == test1) {
//			l = 1;
//		}
//	if (l == 0) cout << "���������� � ������ �������� � ���� ���\n";
//	else {
//		cout << "��������� � ��������� ��������: \n";
//		line();
//		for (int i = 0; i < counter_personnel; i++) {
//			if (ar[i] == test1) {
//				cout << ar[i] << endl;;
//
//			}
//		}
//	}
//}

void Personnel::line()
{
	cout <<"\n"<< setw(25) << "��� ���������"
		<< setw(40) << "���������"
		<< setw(30) << "���� �����" << setw(20)<<"��������"<< endl;
}

void Personnel::Save(ofstream& fout)
{
	fout << fio.GetName() << " "
		<< fio.GetSurname() << " "
		<< fio.GetPatronomic() << " "
		<< proffesion << " "
		<< date.GetDay() << " "
		<< date.GetMonth() << " "
		<< date.GetYear() << " "
		<< salary << " ";
}

bool operator==(Personnel p, Fio f)
{
	if (p.fio.GetSurname() == f.GetSurname()) {
		return true;
	}
	else {
		return false;
	}
}

istream& operator>>(std::istream& in, Personnel& per)
{
	string n, s, p, m, prof;
	int d,y;
	double sal;
	cout << "������� ���\n";
	in >> n;
	cout << "������� �������\n";
	in >> s;
	cout << "������� ��������\n";
	in >> p;
	cout << "������� ���������\n";
	in >> prof;
	cout << "������� ���� ����������\n";
	in >> d;
	cout << "������� ����� ����������\n";
	in >> m;
	cout << "������� ��� ����������\n";
	in >> y;
	cout << "������� �����\n";
	in >> sal;
	per.fio.SetName(n);
	per.fio.SetSurname(s);
	per.fio.SetPatronomic(p);
	per.SetProffesion(prof);
	per.date.SetDay(d);
	per.date.SetMonth(m);
	per.date.SetYear(y);
	per.Setsalary(sal);
	return in;
}

ostream& operator<<(std::ostream& out, Personnel& p)
{
	out <<setw(25)<< p.fio
		<< setw(15) << p.proffesion
		<< setw(15) << p.date <<setw(10)<<p.Getsalary()<< endl;
	return out;

}
