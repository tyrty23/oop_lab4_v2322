#include "Date.h"

ostream& operator<<(ostream& out, Date d)
{
    out << d.day<<"."
        << d.month<<"."
        << d.year;
    return out;
}

istream& operator>>(istream& in, Date d)
{
    in >> d.day >> d.month >> d.year;
    return in;
}


Date::Date()
{
    day = 1;
    month = "������";
    year = 1970;
}

Date::Date(int d, string m, int y)
{
    day = d;
    month = m;
    year = y;
}

int Date::GetDay()
{
    return day;
}

void Date::SetDay(int val)
{
    day = val;
}

string Date::GetMonth()
{
    return month;
}

void Date::SetMonth(string val)
{
    month = val;
}

int Date::GetYear()
{
    return year;
}

void Date::SetYear(int val)
{
    year = val;
}

int Date::GetDays()
{
    return this->GetDay() + Days_in_month(this->GetMonth()) + this->GetYear() * 365;
}

int Date::Days_in_month(string m)
{
    if (m == "������") return 0;
    if (m == "�������") return 31;
    if (m == "����") return 59;
    if (m == "������")return 90;
    if (m == "���") return 120;
    if (m == "����") return 151;
    if (m == "����") return 181;
    if (m == "������") return 212;
    if (m == "��������") return 243;
    if (m == "�������") return 273;
    if (m == "������") return 304;
    if (m == "�������") return 334;
}

int Date::right_day()
{
    string buff;
    cout << "������� ���� ���������� � ���������: ";
    cin >> buff;
    while (true) {
        if (atoi(buff.c_str()) <= 31 && atoi(buff.c_str()) >= 1) { return atoi(buff.c_str()); }
        else {
            cout << "������� ����� �����, ������������� ������� [1;31]: ";
            cin >> buff;
        }
    }
}

string Date::right_month()
{
    string buff;
    string test[] = { "������","�������","����","������","���","����","����","������","��������","�������","������","�������" };
    cout << "������� ����� ���������� � ���������: ";
    cin >> buff;

    //try {
    //    for (int i = 0; i < fio.length(); i++)
    //    {
    //        if (isdigit(fio[i]))
    //        {
    //            throw "���������� �������";
    //        }

    //    }
    //    return fio;
    //}
    //catch (const char* msg) {
    //    cout << msg << endl;
    //    cout << "������� ���������� ���: ";
    //    string buff;
    //    cin >> buff;
    //    buff = right_fio(buff);
    //    return buff;
    //}

    while (true) {
        bool a = false;
        for (int i = 0; i < 12; i++)
            if (buff == test[i]) {
                a = true;
                return buff;
            }
        if (a == false) {
            cout << "������� �������� ������ �� ������� � �������� �����: ";
            cin >> buff;
        }
    }
    return nullptr;
}