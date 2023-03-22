#pragma once
#include <string>
using namespace std;

struct Node {
	int value;
	Node* next;

};
 class Set
 {
 private:
		 Node* firstElement;
 public:
	Set();//конструктор-cоздание пустого множества

	bool emptySetList();//проверка на пустое множество?

	bool elemInSetList( int valaues);//проверка принадлежности элемента множеству

	void addelem( int values);//добавление нового элемента в множество

	Set(int len, int min, int max, char setType);//создание множества

	int Power_SetList();//мощность множества

	string toString( char sym);//вывод элементов множества с помощью разделителей

	~Set();//деструктор - удаление множества

	bool isSubset(Set* sub_set);//Подмножество А - В.

	bool equalSet(Set* set_B);//равенство множеств А - В.

	Set* unitySet(Set* set_B);//Объединение двух множеств.

	Set* intersectionSet(Set* set_B);//Пересечение двух множеств.

	Set* differenceSet(Set* set_B);//Разность двух множеств.

	Set* symmetrydifferentSet(Set* set_B);//Симметричная разность двух множеств.

	int static random(int min, int max);//рандомный диапазон множества от 6 до 9 элементов

};
