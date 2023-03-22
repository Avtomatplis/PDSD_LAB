#include<iostream>

#include "SetLab1_2_3_Zhigalov.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	Set* SetList_A = new Set(Set::random(6, 9), 10, 99, 'A');
	Set* SetList_B = new Set(Set::random(6, 9), 10, 99, 'B');
	cout << "Создание множества А: " <<SetList_A-> toString(' ') << endl;
	cout << "Создание множества B: " << SetList_B->toString(' ') << endl;
	cout << "Мощность множества А: " <<SetList_A-> Power_SetList() << endl;
	cout << "Мощность множества B: " << SetList_B->Power_SetList() << endl;
	cout << "Вывод множества А: " << SetList_A->toString(' ,') << endl;
	cout << "Вывод множества А: " << SetList_B->toString(' ,') << endl;
	cout << "" << endl;
	cout << "Подмножество А-B: " << boolalpha << SetList_A->isSubset(SetList_B) << endl;
	cout << "Подмножество А-A: " << boolalpha << SetList_A->isSubset(SetList_A) << endl;
	cout << "Равенство двух множеств А-B: " << boolalpha << SetList_A->equalSet(SetList_B) << endl;
	cout << "Равенство двух множеств А-A: " << boolalpha << SetList_A->equalSet(SetList_A) << endl;
	cout << "Объединение двух множеств А-B: " <<SetList_A->unitySet(SetList_B)->toString(' ') << endl;
	cout << "Пересечение двух множеств А-B: " <<SetList_A->intersectionSet(SetList_B)-> toString(' ') << endl;
	cout << "Разность двух множеств А-B: " <<SetList_A->differenceSet(SetList_B)-> toString( ' ') << endl;
	cout << "Разность двух множеств B-A: " <<SetList_B->differenceSet(SetList_A)-> toString(' ') << endl;
	cout << "Cимметричная разность двух множеств А-В: " <<SetList_A->symmetrydifferentSet(SetList_B)-> toString(' ') << endl;
	cout << "" << endl;
	cout << "Удаление множества А " << endl;
	delete SetList_A;
	SetList_A = nullptr;
	cout << "Удаление множества B " << endl;
	delete SetList_B;
	SetList_B = nullptr;
}