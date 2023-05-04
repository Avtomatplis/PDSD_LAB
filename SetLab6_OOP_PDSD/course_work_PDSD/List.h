#pragma once
#include <string>
#include<list>

using namespace std;

class List
{
private:
	list<int> ContainerListSet;  //Объект класса list
public:
	List();//cоздание пустого множества

	bool emptySetList();//проверка на пустое множество?

	bool elemInSetList(int valaues);//проверка принадлежности элемента множеству

	void addelem(int values);//добавление элемента в множество

	List(int len, int min, int max);//создание множества

	int Power_SetList();//мощность множества

	string toString(char sym);//вывод элементов множества

	~List();//деструктор - удаление множества

	bool isSubset(List* sub_set);//Подмножество А - В.

	bool equalSet(List* set_B);//равенство множеств А - В.

	List* unitySet(List* set_B);//Объединение двух множеств.

	List* intersectionSet(List* set_B);//Пересечение двух множеств.

	List* differenceSet(List* set_B);//Разность двух множеств.

	List* symmetrydifferentSet(List* set_B);//Симметричная разность двух множеств.

	int static random(int min, int max);//рандомный диапазон множества от 6 до 9 элементов

};