#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include "worker.h"
#include <fstream>
#include "Personnel.h"


int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_CTYPE, "Russian");

    string test,test2;
    bool l;
    bool trap = true;
    Worker w;
    Personnel p;
    Date dat;
    int i;

    Common*** ar = new Common * *[2];
    ar[0] = new Common * [10];
    ar[1] = new Common * [10];
    for (int i = 0; i < 10; i++) {
        ar[0][i] = new Worker[1];
        ar[1][i] = new Personnel[1];
    }

    ifstream fin("lab4.txt");
    if (fin.is_open() && fin.peek() != EOF) {
        int n;
        fin >> n;
        for (int i = 0; i < n; i++) {
            ar[0][i]->load(fin);
        }
        fin >> n;
        for (int i = 0; i < n; i++) {
            ar[1][i]->load(fin);
        }
    }
    //else {
    //    ofstream fout("lab4.txt");
    //    cout << "Введите кол-во новых записей: ";
    //    int n = Common::right_int();
    //    for (int i = 0; i < n; i++) {
    //      /*  AddWorker2(ar);*/
    //    }
    //    fout.close();
    //}
    fin.close();


    while (trap==true) {
        cout << "\n==============================================================================\n";
        cout << "\t ----------------------------------------------------------\n";
        cout << "\t |            Выберите, что Вы хотите сделать              |\n";
        cout << "\t ----------------------------------------------------------\n";
        cout << "\t   1-добавить работника\n\t   2-добавить персонал\n\t   3-распечатать таблицу\n"
            /*<< "\t   3-найти работников департамента\n"*/
            << "\t   4-найти персонал по профессии\n\t   5-найти работника по фамилии\n"
            << "\t   6-сортировать по зарплате\n\t   7-все работники, проработавшие больше 10 лет\n\t   8-завершить работу\n";
        cout << "==============================================================================\n";

        int t;
        t = Common::right_int();

        switch (t) {
        case(1):
            system("cls");
            cin >> w;
            ar[0][Worker::counter] = new Worker[1]{ w };
            Worker::counter++;
            break;
        case(2):
            system("cls");
            cin >> p;
            ar[1][Personnel::counter] = new Personnel[1]{ p };
            Personnel::counter++;
            break;
        case(3):
            system("cls");
            for (int a = 0; a < 2; a++) {
                ar[a][0]->line();
                for (int i = 0; i < ar[a][0]->GetCounter(); i++)
                    ar[a][i]->print();
            }
            break;
        case(4):
            system("cls");
            l = 0;
            cout << "Ведите проффесию: ";
            cin >> test2;
            test=Common::right_fio(test2);
            for (i = 0; i < Personnel::counter; i++)
                if (ar[1][i]->Find(test)) { { l = 1;/* break;*/ }
            if (l == 0) cout << "Персонала с данной проффесией в базе нет\n";
            else {
                cout << "Персонал с даннй проффесией: \n";
                ar[1][0]->line();
                for (int i = 0; i < Personnel::counter; i++) {
                    if (ar[1][i]->Find(test)) {
                        ar[1][i]->print();
                    }
                }
            }
            break;
        case(5):
            system("cls");
            l = 0;
            cout << "Ведите фамилию работника: ";
            cin >> test2;
            test = Common::right_fio(test2);
            for (i = 0; i < Worker::counter; i++)
                if (ar[0][i]->Find(test)) { l = 1; }
            if (l == 0) cout << "Работников с данной фамилией в базе нет\n";
            else {
                cout << "Работники с данной фамилией: \n";
                ar[0][0]->line();
                for (int i = 0; i < Worker::counter; i++) {
                    if (ar[0][i]->Find(test)) {
                        ar[0][i]->print();
                    }
                }
            }
            break;
        case(6):
            system("cls");
            Common::Sort(ar, Worker::counter, Personnel::counter);
            break;
        case(7):
            system("cls");
            cout << "Ведите дату: ";
            dat.SetDay(Date::right_day());
            dat.SetMonth(Date::right_month());
            cout << "Введите год вступления в должность: ";
            dat.SetYear(Common::right_int());

            Common::GetByDate(ar,dat);
            break;
        case(8):
            system("cls");
            ofstream fout("lab4.txt");
            //fout << Worker::counter;
            for (int a = 0; a < 2; a++) {
                fout << ar[a][0]->GetCounter();
                for (int i = 0; i < ar[a][0]->GetCounter(); i++)
                    ar[a][i]->Save(fout);
            }
            fout.close();
            trap = false;
            break;
            }
        }
    }
}