#include<iostream>

#include "SetLab1_2_Zhigalov.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	Node* SetList_A = createSetList(random(6, 9), 10, 99, 'A');
	Node* SetList_B = createSetList(random(6, 9), 10, 99, 'B');
	cout << "Создание множества А: " << toString(SetList_A, ' ') << endl;
    cout << "Мощность множества А: " << Power_SetList(SetList_A) << endl;
	cout << "Вывод множества А: " << toString(SetList_A, ' ,') << endl;
	//SetList_A = deleteSetList(SetList_A);
	//cout << "Удаление множества А " << endl;
	//cout << "Мощность множества А: " << Power_SetList(SetList_A) << endl;
	//cout << "Вывод множества А: " << toString(SetList_A, ' ,') << endl;
	cout << "" << endl;
	cout << "Создание множества B: " << toString(SetList_B, ' ') << endl;
	cout << "Мощность множества B: " << Power_SetList(SetList_B) << endl;
	cout << "Вывод множества B: " << toString(SetList_B, ' ,') << endl;
	//SetList_B = deleteSetList(SetList_B);
	//cout << "Удаление множества B " << endl;
	//cout << "Мощность множества B: " << Power_SetList(SetList_B) << endl;
	cout << "Подмножество А-B: " <<boolalpha<< isSubset(SetList_A, SetList_B) << endl;
	cout << "Подмножество А-A: " << boolalpha << isSubset(SetList_A, SetList_A) << endl;
	cout << "Равенство двух множеств А-B: " << boolalpha << equalSet(SetList_A, SetList_B) << endl;
	cout << "Равенство двух множеств А-A: " << boolalpha << equalSet(SetList_A, SetList_A) << endl;
	cout << "Объединение двух множеств А-B: " << toString(unitySet(SetList_A, SetList_B), ' ') << endl;
	cout << "Пересечение двух множеств А-B: " << toString(intersectionSet(SetList_A, SetList_B), ' ') << endl;
	cout << "Разность двух множеств А-B: " << toString(differenceSet(SetList_A, SetList_B), ' ') << endl;
	cout << "Разность двух множеств B-A: " << toString(differenceSet(SetList_B, SetList_A), ' ') << endl;
	cout << "Cимметричная разность двух множеств А-В: " << toString(symmetrydifferentSet(SetList_A, SetList_B), ' ') << endl;
	cout << "" << endl;
	SetList_A = deleteSetList(SetList_A);
	SetList_B = deleteSetList(SetList_B);
	cout << "Удаление множества А " << endl;
	cout << "Удаление множества B " << endl;
	cout << "Вывод множества A: " << toString(SetList_A, ' ,') << endl;
	cout << "Вывод множества B: " << toString(SetList_B, ' ,') << endl;
}