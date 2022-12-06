#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include "worker.h"
#include <fstream>
#include "Personnel.h"


int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_CTYPE, "Russian");

    string test;
    bool l;
    bool trap = true;
    Worker w;
    Personnel p;
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
    //    cout << "������� ���-�� ����� �������: ";
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
        cout << "\t |            ��������, ��� �� ������ �������              |\n";
        cout << "\t ----------------------------------------------------------\n";
        cout << "\t   1-�������� ���������\n\t   2-�������� ��������\n\t   3-����������� �������\n"
            << "\t   3-����� ���������� ������������\n"
            << "\t   4-����� �������� �� ���������\n\t   5-����� ��������� �� �������\n"
            << "\t   6-����������� �� ��������\n\t   7-��������� ������\n";
        cout << "==============================================================================\n";

        int t;
        t = Common::right_int();

        switch (t) {
        case(1):
            system("cls");

            cin >> w;
            ar[0][w.counter_worker] = new Worker[1]{ w };
            w.counter_worker++;
            break;
        case(2):
            system("cls");

            cin >> p;
            ar[1][Personnel::counter_personnel] = new Personnel[1]{ p };
            Personnel::counter_personnel++;
            break;
        case(3):
            system("cls");

            Worker::line();
            for (int i = 0; i < Worker::counter_worker; i++) {
                ar[0][i]->print();
            }
            Personnel::line();
            for (int i = 0; i < Personnel::counter_personnel; i++) {
                ar[1][i]->print();
            }
            break;
        case(4):
            system("cls");

            l = 0;
            cout << "������ ���������: ";
            cin >> test;
            for (i = 0; i < Personnel::counter_personnel; i++)
                if (ar[1][i]->Find(test)) { { l = 1;/* break;*/ }
            if (l == 0) cout << "��������� � ������ ���������� � ���� ���\n";
            else {
                cout << "�������� � ����� ����������: \n";
                Personnel::line();
                for (int i = 0; i < Personnel::counter_personnel; i++) {
                    if (ar[1][i]->Find(test)) {
                        ar[1][i]->print();
                    }
                }
            }
            break;
        case(5):
            system("cls");

            l = 0;
            cout << "������ ������� ���������: ";
            cin >> test;
            for (i = 0; i < Worker::counter_worker; i++)
                if (ar[0][i]->Find(test)) { l = 1;/* break;*/ }
            if (l == 0) cout << "���������� � ������ �������� � ���� ���\n";
            else {
                cout << "��������� � ������ ��������: \n";
                Worker::line();
                for (int i = 0; i < Worker::counter_worker; i++) {
                    if (ar[0][i]->Find(test)) {
                        ar[0][i]->print();
                    }
                }
            }
            break;
        case(6):
            system("cls");

            Common::Sort(ar, Worker::counter_worker, Personnel::counter_personnel);
            break;
        case(7):
            ofstream fout("lab4.txt");
            fout << Worker::counter_worker;
            for (int i = 0; i < Worker::counter_worker; i++) {
                ar[0][i]->Save(fout);
            }
            fout << Personnel::counter_personnel;
            for (int i = 0; i < Personnel::counter_personnel; i++) {
                ar[1][i]->Save(fout);
            }
            fout.close();
            trap = false;
            break;
            
                }
        }
        //break;
    }
    
}