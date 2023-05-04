#include <iostream>
#include <iomanip>
#include<chrono>
#include <regex>

#include "Class_Set.h"
#include "List.h"
#include "Set.h"
#include "Structure_List.h"

using namespace std;

void timeStructureClassList(__int64* timet, int N);
void timeStructureClassSet(__int64* timet, int N);
void timeStructureList(__int64* timet, int N);
void timeStructureSet(__int64* timet, int N);


void printTable(__int64 t1[], __int64 t2[], __int64 t3[], __int64 t4[]);

int main()
{
    setlocale(LC_ALL, "rus");
    string str;
    regex rgx("^[0-9]+$");
    bool flag = false;
    do
    {
        if (flag)
            cout << "Неверный ввод! Необходимо ввести целое неотрицательное число.\n";
        cout << "Введите количество элементов: ";
        cin >> str;
        flag = true;
    } while (!regex_match(str, rgx));

    int N = stoi(str);
    cout << endl;
    __int64 t1[11];
    timeStructureClassList(t1, N);
    __int64 t2[11];
    timeStructureClassSet(t2, N);
     __int64 t3[11];
    timeStructureList(t3, N);
     __int64 t4[11];
    timeStructureSet(t4, N);
    printTable(t1, t2, t3,t4);
    return 0;
}

void printTable(__int64 t1[], __int64 t2[], __int64 t3[], __int64 t4[])
{
    const int col_width = 22;
    const char delimiter = '-';
    const char row_delimiter = '|';

    string headers[] = { "","Односвязный список", "Класс список", "List", "Set" };
    string rows[] = { "Создание множества", "Мощность", "Подмножество A-A", "Подмножество B-A",
        "Равенство A-A", "Равенство B-A", "Объединение", "Пересечение", 
        "Разность A-B", "Разность B-A", "Симмметричная разность" };

    cout << left << setw(col_width) << setfill(' ') << headers[0] << " | ";
    for (int i = 1; i < 5; i++)
    {
        cout << left << setw(col_width) << setfill(' ') << headers[i] << " | ";
    }
    cout << endl;

    cout << setfill(delimiter) << setw((col_width + 3) * 5) << "" << endl;

    for (int i = 0; i < 11; i++)
    {
        cout << left << setw(col_width) << setfill(' ') << rows[i] << " | ";
        cout << left << setw(col_width) << setfill(' ') << t1[i] << " | ";
        cout << left << setw(col_width) << setfill(' ') << t2[i] << " | ";
        cout << left << setw(col_width) << setfill(' ') << t3[i] << " | ";
        cout << left << setw(col_width) << setfill(' ') << t4[i] << " | ";
        cout << endl;
        cout << setfill(delimiter) << setw((col_width + 3) * 5) << "" << endl;
    }
}

void timeStructureClassList(__int64* timet, int N)
{
    Node* setA = createSetList(N, 0, N * 10);
    Node* setB = createSetList(N, 0, N * 10);

    auto start1 = chrono::high_resolution_clock::now();
    createSetList(N, 0, N * 10);
    auto finish1 = chrono::high_resolution_clock::now();
    auto time1 = chrono::duration_cast<chrono::microseconds>(finish1 - start1);
    timet[0] = time1.count();

    auto start2 = chrono::high_resolution_clock::now();
    Power_SetList(setA);
    auto finish2 = chrono::high_resolution_clock::now();
    auto time2 = chrono::duration_cast<chrono::microseconds>(finish2 - start2);
    timet[1] = time2.count();

    auto start3 = chrono::high_resolution_clock::now();
    isSubset(setA, setA);
    auto finish3 = chrono::high_resolution_clock::now();
    auto time3 = chrono::duration_cast<chrono::microseconds>(finish3 - start3);
    timet[2] = time3.count();

    auto start4 = chrono::high_resolution_clock::now();
    isSubset(setB, setA);
    auto finish4 = chrono::high_resolution_clock::now();
    auto time4 = chrono::duration_cast<chrono::microseconds>(finish4 - start4);
    timet[3] = time4.count();

    auto start5 = chrono::high_resolution_clock::now();
    equalSet(setA, setA);
    auto finish5 = chrono::high_resolution_clock::now();
    auto time5 = chrono::duration_cast<chrono::microseconds>(finish5 - start5);
    timet[4] = time5.count();

    auto start6 = chrono::high_resolution_clock::now();
    equalSet(setB, setA);
    auto finish6 = chrono::high_resolution_clock::now();
    auto time6 = chrono::duration_cast<chrono::microseconds>(finish6 - start6);
    timet[5] = time6.count();

    auto start7 = chrono::high_resolution_clock::now();
    unitySet(setA, setB);
    auto finish7 = chrono::high_resolution_clock::now();
    auto time7 = chrono::duration_cast<chrono::microseconds>(finish7 - start7);
    timet[6] = time7.count();

    auto start8 = chrono::high_resolution_clock::now();
    intersectionSet(setA, setB);
    auto finish8 = chrono::high_resolution_clock::now();
    auto time8 = chrono::duration_cast<chrono::microseconds>(finish8 - start8);
    timet[7] = time8.count();

    auto start9 = chrono::high_resolution_clock::now();
    differenceSet(setA, setB);
    auto finish9 = chrono::high_resolution_clock::now();
    auto time9 = chrono::duration_cast<chrono::microseconds>(finish9 - start9);
    timet[8] = time9.count();

    auto start10 = chrono::high_resolution_clock::now();
    differenceSet(setB, setA);
    auto finish10 = chrono::high_resolution_clock::now();
    auto time10 = chrono::duration_cast<chrono::microseconds>(finish10 - start10);
    timet[9] = time8.count();

    auto start11 = chrono::high_resolution_clock::now();
    symmetrydifferentSet(setA, setB);
    auto finish11 = chrono::high_resolution_clock::now();
    auto time11 = chrono::duration_cast<chrono::microseconds>(finish11 - start11);
    timet[10] = time11.count();
}

void timeStructureClassSet(__int64* timet, int N)
{
    Class_Set* setA = new Class_Set(Class_Set::Class_Set(N, 0, N * 10));
    Class_Set* setB = new Class_Set(Class_Set::Class_Set(N, 0, N * 10));

    auto start1 = chrono::high_resolution_clock::now();
    Class_Set(N, 0, N * 10);
    auto finish1 = chrono::high_resolution_clock::now();
    auto time1 = chrono::duration_cast<chrono::microseconds>(finish1 - start1);
    timet[0] = time1.count();

    auto start2 = chrono::high_resolution_clock::now();
    setA->Power_SetList();
    auto finish2 = chrono::high_resolution_clock::now();
    auto time2 = chrono::duration_cast<chrono::microseconds>(finish2 - start2);
    timet[1] = time2.count();

    auto start3 = chrono::high_resolution_clock::now();
    setA->isSubset(setA);
    auto finish3 = chrono::high_resolution_clock::now();
    auto time3 = chrono::duration_cast<chrono::microseconds>(finish3 - start3);
    timet[2] = time3.count();

    auto start4 = chrono::high_resolution_clock::now();
    setA->isSubset(setB);
    auto finish4 = chrono::high_resolution_clock::now();
    auto time4 = chrono::duration_cast<chrono::microseconds>(finish4 - start4);
    timet[3] = time4.count();

    auto start5 = chrono::high_resolution_clock::now();
    setA->equalSet(setA);
    auto finish5 = chrono::high_resolution_clock::now();
    auto time5 = chrono::duration_cast<chrono::microseconds>(finish5 - start5);
    timet[4] = time5.count();

    auto start6 = chrono::high_resolution_clock::now();
    setA->equalSet(setB);
    auto finish6 = chrono::high_resolution_clock::now();
    auto time6 = chrono::duration_cast<chrono::microseconds>(finish6 - start6);
    timet[5] = time6.count();

    auto start7 = chrono::high_resolution_clock::now();
    setA->unitySet(setB);
    auto finish7 = chrono::high_resolution_clock::now();
    auto time7 = chrono::duration_cast<chrono::microseconds>(finish7 - start7);
    timet[6] = time7.count();

    auto start8 = chrono::high_resolution_clock::now();
    setA->intersectionSet(setB);
    auto finish8 = chrono::high_resolution_clock::now();
    auto time8 = chrono::duration_cast<chrono::microseconds>(finish8 - start8);
    timet[7] = time8.count();

    auto start9 = chrono::high_resolution_clock::now();
    setA->differenceSet(setB);
    auto finish9 = chrono::high_resolution_clock::now();
    auto time9 = chrono::duration_cast<chrono::microseconds>(finish9 - start9);
    timet[8] = time9.count();

    auto start10 = chrono::high_resolution_clock::now();
    setB->differenceSet(setA);
    auto finish10 = chrono::high_resolution_clock::now();
    auto time10 = chrono::duration_cast<chrono::microseconds>(finish10 - start10);
    timet[9] = time8.count();

    auto start11 = chrono::high_resolution_clock::now();
    setA->symmetrydifferentSet(setB);
    auto finish11 = chrono::high_resolution_clock::now();
    auto time11 = chrono::duration_cast<chrono::microseconds>(finish11 - start11);
    timet[10] = time11.count();
}

void timeStructureSet(__int64* timet, int N)
{
    Set* setA = new Set(Set::Set(N, 0, N * 10));
    Set* setB = new Set(Set::Set(N, 0, N * 10));

    auto start1 = chrono::high_resolution_clock::now();
    Set(N, 0, N * 10);
    auto finish1 = chrono::high_resolution_clock::now();
    auto time1 = chrono::duration_cast<chrono::microseconds>(finish1 - start1);
    timet[0] = time1.count();

    auto start2 = chrono::high_resolution_clock::now();
    setA->Power_SetList();
    auto finish2 = chrono::high_resolution_clock::now();
    auto time2 = chrono::duration_cast<chrono::microseconds>(finish2 - start2);
    timet[1] = time2.count();

    auto start3 = chrono::high_resolution_clock::now();
    setA->isSubset(setA);
    auto finish3 = chrono::high_resolution_clock::now();
    auto time3 = chrono::duration_cast<chrono::microseconds>(finish3 - start3);
    timet[2] = time3.count();

    auto start4 = chrono::high_resolution_clock::now();
    setA->isSubset(setB);
    auto finish4 = chrono::high_resolution_clock::now();
    auto time4 = chrono::duration_cast<chrono::microseconds>(finish4 - start4);
    timet[3] = time4.count();

    auto start5 = chrono::high_resolution_clock::now();
    setA->equalSet(setA);
    auto finish5 = chrono::high_resolution_clock::now();
    auto time5 = chrono::duration_cast<chrono::microseconds>(finish5 - start5);
    timet[4] = time5.count();

    auto start6 = chrono::high_resolution_clock::now();
    setA->equalSet(setB);
    auto finish6 = chrono::high_resolution_clock::now();
    auto time6 = chrono::duration_cast<chrono::microseconds>(finish6 - start6);
    timet[5] = time6.count();

    auto start7 = chrono::high_resolution_clock::now();
    setA->unitySet(setB);
    auto finish7 = chrono::high_resolution_clock::now();
    auto time7 = chrono::duration_cast<chrono::microseconds>(finish7 - start7);
    timet[6] = time7.count();

    auto start8 = chrono::high_resolution_clock::now();
    setA->intersectionSet(setB);
    auto finish8 = chrono::high_resolution_clock::now();
    auto time8 = chrono::duration_cast<chrono::microseconds>(finish8 - start8);
    timet[7] = time8.count();

    auto start9 = chrono::high_resolution_clock::now();
    setA->differenceSet(setB);
    auto finish9 = chrono::high_resolution_clock::now();
    auto time9 = chrono::duration_cast<chrono::microseconds>(finish9 - start9);
    timet[8] = time9.count();

    auto start10 = chrono::high_resolution_clock::now();
    setB->differenceSet(setA);
    auto finish10 = chrono::high_resolution_clock::now();
    auto time10 = chrono::duration_cast<chrono::microseconds>(finish10 - start10);
    timet[9] = time8.count();

    auto start11 = chrono::high_resolution_clock::now();
    setA->symmetrydifferentSet(setB);
    auto finish11 = chrono::high_resolution_clock::now();
    auto time11 = chrono::duration_cast<chrono::microseconds>(finish11 - start11);
    timet[10] = time11.count();
}

void timeStructureList(__int64* timet, int N)
{
    List* setA = new List(List::List(N, 0, N * 10));
    List* setB = new List(List::List(N, 0, N * 10));

    auto start1 = chrono::high_resolution_clock::now();
    List(N, 0, N * 10);
    auto finish1 = chrono::high_resolution_clock::now();
    auto time1 = chrono::duration_cast<chrono::microseconds>(finish1 - start1);
    timet[0] = time1.count();

    auto start2 = chrono::high_resolution_clock::now();
    setA->Power_SetList();
    auto finish2 = chrono::high_resolution_clock::now();
    auto time2 = chrono::duration_cast<chrono::microseconds>(finish2 - start2);
    timet[1] = time2.count();

    auto start3 = chrono::high_resolution_clock::now();
    setA->isSubset(setA);
    auto finish3 = chrono::high_resolution_clock::now();
    auto time3 = chrono::duration_cast<chrono::microseconds>(finish3 - start3);
    timet[2] = time3.count();

    auto start4 = chrono::high_resolution_clock::now();
    setA->isSubset(setB);
    auto finish4 = chrono::high_resolution_clock::now();
    auto time4 = chrono::duration_cast<chrono::microseconds>(finish4 - start4);
    timet[3] = time4.count();

    auto start5 = chrono::high_resolution_clock::now();
    setA->equalSet(setA);
    auto finish5 = chrono::high_resolution_clock::now();
    auto time5 = chrono::duration_cast<chrono::microseconds>(finish5 - start5);
    timet[4] = time5.count();

    auto start6 = chrono::high_resolution_clock::now();
    setA->equalSet(setB);
    auto finish6 = chrono::high_resolution_clock::now();
    auto time6 = chrono::duration_cast<chrono::microseconds>(finish6 - start6);
    timet[5] = time6.count();

    auto start7 = chrono::high_resolution_clock::now();
    setA->unitySet(setB);
    auto finish7 = chrono::high_resolution_clock::now();
    auto time7 = chrono::duration_cast<chrono::microseconds>(finish7 - start7);
    timet[6] = time7.count();

    auto start8 = chrono::high_resolution_clock::now();
    setA->intersectionSet(setB);
    auto finish8 = chrono::high_resolution_clock::now();
    auto time8 = chrono::duration_cast<chrono::microseconds>(finish8 - start8);
    timet[7] = time8.count();

    auto start9 = chrono::high_resolution_clock::now();
    setA->differenceSet(setB);
    auto finish9 = chrono::high_resolution_clock::now();
    auto time9 = chrono::duration_cast<chrono::microseconds>(finish9 - start9);
    timet[8] = time9.count();

    auto start10 = chrono::high_resolution_clock::now();
    setB->differenceSet(setA);
    auto finish10 = chrono::high_resolution_clock::now();
    auto time10 = chrono::duration_cast<chrono::microseconds>(finish10 - start10);
    timet[9] = time8.count();

    auto start11 = chrono::high_resolution_clock::now();
    setA->symmetrydifferentSet(setB);
    auto finish11 = chrono::high_resolution_clock::now();
    auto time11 = chrono::duration_cast<chrono::microseconds>(finish11 - start11);
    timet[10] = time11.count();
}

