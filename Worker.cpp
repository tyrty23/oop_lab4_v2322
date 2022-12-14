#include "Worker.h"

int Worker::counter = 0;

int Worker::GetCounter()
{
    return counter;
}

int Worker::GetNum_dep()
{
    return this->num_dep;
}

void Worker::SetNum_dep(int num)
{
    this->num_dep = num;
}

Worker::Worker()
{
    Common();
    num_dep = 1;
    salary = 1000.2;
}

Worker::Worker(Fio fio1, int num,Date dat, double s)
{
    fio = { fio1.GetName(),fio1.GetSurname(),fio1.GetPatronomic() };
    num_dep = num;
    dat = {dat.GetDay(),dat.GetMonth(),dat.GetYear()};
    salary = s;
}

void Worker::load(ifstream&  fin)
{
    string n, s, p, m;
    int num, d, y;
    double sal;
    fin >> n
        >> s
        >> p
        >> num
        >> d
        >> m
        >> y
        >> sal;
    this->fio.SetName(n);
    this->fio.SetSurname(s);
    this->fio.SetPatronomic(p);
    this->SetNum_dep(num);
    this->date.SetDay(d);
    this->date.SetMonth(m);
    this->date.SetYear(y);
    this->Setsalary(sal);

    counter++;
}

void Worker::line()
{
    cout << setw(25) << "ФИО работника"
         << setw(25) << "Номер отдела"
         << setw(15) << "Дата приёма"
         << setw(25) << "Оклад (&)" << endl;
}

void Worker::print()
{
    cout << setw(25) << this->fio
         << setw(10)  << this->num_dep
         << setw(15) << this->date
         << setw(20) << this->salary << endl;
}

bool Worker::Find(string sur)
{
    if (this->fio.GetSurname() == sur) {
        return true;
    }
    return false;
}

void Worker::Save(ofstream& fout)
{
    fout << fio.GetName() << " "
        << fio.GetSurname() << " "
        << fio.GetPatronomic() << " "
        << num_dep << " "
        << date.GetDay() << " "
        << date.GetMonth() << " "
        << date.GetYear() << " "
        << salary << " ";
}

istream& operator>>(std::istream& in, Worker& w)
{
    string n, s, p;
    cout << "Введите имя\n";
    in >> n;
    w.fio.SetName(Common::right_fio(n));

    cout << "Введите фамилию\n";
    in >> s;
    w.fio.SetSurname(Common::right_fio(s));

    cout << "Введите отчество\n";
    in >> p;
    w.fio.SetPatronomic(Common::right_fio(p));

    cout << "Введите номер отдела\n";
    w.SetNum_dep(Common::right_int());

    cout << "Введите день зачисления\n";
    w.date.SetDay(Date::right_day());

    cout << "Введите месяц зачисления\n";
    w.date.SetMonth(Date::right_month());

    cout << "Введите год зачисления\n";
    w.date.SetYear(Common::right_int());

    cout << "Введите оклад\n";
    w.Setsalary(Common::right_double());

    //Worker::counter++;
    return in;
}

ostream& operator<<(std::ostream& out, Worker& w)
{
    out << w.fio
        << setw(15) << w.num_dep
        << setw(20) << w.salary << endl;
    return out;

}
