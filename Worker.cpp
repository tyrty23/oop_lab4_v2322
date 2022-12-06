#include "Worker.h"

int Worker::counter_worker = 0;

int Worker::GetCounter()
{
    return counter_worker;
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

Worker::Worker(Fio fio1, int num, double s)
{
    fio = { fio1.GetName(),fio1.GetSurname(),fio1.GetPatronomic() };
    num_dep = num;
    salary = s;
}

void Worker::load(ifstream&  fin)
{
    string n, s, p;
    int num;
    double sal;
    fin >> n
        >> s
        >> p
        >> num
        >> sal;
    this->fio.SetName(n);
    this->fio.SetSurname(s);
    this->fio.SetPatronomic(p);
    this->SetNum_dep(num);
    this->Setsalary(sal);

    /*fin >> fio
        >> num_dep
        >> salary;*/
    counter_worker++;
}

void Worker::line()
{
    cout << setw(25) << "ФИО работника"
        << setw(30) << "Департамент"
        << setw(15) << "Оклад (&)" << endl;
}

void Worker::Add(Common** ar)
{
    Worker k;
    cout << "Ввдите нового работника в формате ФИО, отдел, оклад через пробел или enter: \n";
    cin >> k;
    ar[counter_worker] = new Worker[1]{ k };

    counter_worker++;
}

void Worker::print()
{
    cout << this->fio
        << setw(15) << this->num_dep
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
        << salary << " ";
}

istream& operator>>(std::istream& in, Worker& w)
{
    string n, s, p;
    int num;
    double sal;
    cout << "Введите имя\n";
    in >> n;
    cout << "Введите фамилию\n";
    in >> s;
    cout << "Введите отчество\n";
    in >> p;
    cout << "Введите номер отдела\n";
    in >> num;
    cout << "Введите оклад\n";
    in >> sal;
    w.fio.SetName(n);
    w.fio.SetSurname(s);
    w.fio.SetPatronomic(p);
    w.SetNum_dep(num);
    w.Setsalary(sal);
    return in;
}

ostream& operator<<(std::ostream& out, Worker& w)
{
    out << w.fio
        << setw(15) << w.num_dep
        << setw(20) << w.salary << endl;
    return out;

}
