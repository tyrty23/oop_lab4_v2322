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
    month = "январь";
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
    if (m == "€нварь") return 0;
    if (m == "февраль") return 31;
    if (m == "март") return 59;
    if (m == "апрель")return 90;
    if (m == "май") return 120;
    if (m == "июнь") return 151;
    if (m == "июль") return 181;
    if (m == "август") return 212;
    if (m == "сент€брь") return 243;
    if (m == "окт€брь") return 273;
    if (m == "но€брь") return 304;
    if (m == "декабрь") return 334;
}

int Date::right_day()
{
    string buff;
    cout << "¬ведите день вступлени€ в должность: ";
    cin >> buff;
    while (true) {
        if (atoi(buff.c_str()) <= 31 && atoi(buff.c_str()) >= 1) { return atoi(buff.c_str()); }
        else {
            cout << "¬ведите целое число, принадлежащее отрезку [1;31]: ";
            cin >> buff;
        }
    }
}

string Date::right_month()
{
    string buff;
    string test[] = { "€нварь","февраль","март","апрель","май","июнь","июль","август","сент€брь","окт€брь","но€брь","декабрь" };
    cout << "¬ведите мес€ц вступлени€ в должность: ";
    cin >> buff;

    //try {
    //    for (int i = 0; i < fio.length(); i++)
    //    {
    //        if (isdigit(fio[i]))
    //        {
    //            throw "Ќепон€тные символы";
    //        }

    //    }
    //    return fio;
    //}
    //catch (const char* msg) {
    //    cout << msg << endl;
    //    cout << "¬ведите нормальное им€: ";
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
            cout << "¬ведите название мес€ца на русском с строчной буквы: ";
            cin >> buff;
        }
    }
    return nullptr;
}