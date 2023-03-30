#include "SetLab5_Zhigalov.h"
#include <iostream>
#include <random>
#include <string>
using namespace std;

random_device rd;
mt19937 gen(rd());

using namespace std;

Set::Set() //создание пустого множества
{
	ContainerSet = set<int>();
}


bool Set::emptySetList() //Пустое ли множество? (F2)
{
	return ContainerSet.empty();
}

bool Set::elemInSetList(int values) //принадлежность элемента множеству (F3)
{
	return ContainerSet.contains(values);
}

bool Set::addelem(int values) //добавление нового элемента в множество (F4)
{
	
	return	ContainerSet.insert(values).second;

}

int Set::random(int min, int max)//генерация рандомных значений
{
	uniform_int_distribution<> dist(min, max);
	return dist(gen);
}
/*
   Вариант 7: Множество А - множество чисел, кратных 7. Множество B - множество нечетных чисел.
*/
Set::Set(int len, int min, int max, char setType) //создаём множество (F5)
{
	ContainerSet = set<int>();

	if (min > max || len <= 0 || max - min < len)
	{
		return;
	}

	while (len > 0)
	{
		bool check = addelem(GenerateValueAorB(min, max, setType));
		if (check)
		{
			len--;
		}
	}
}

int Set::GenerateValueAorB(int min, int max, char setType) {
	int value = random(min, max);
	if (setType == 'A') {
		while (value % 7 != 0) {
			value = random(min, max);
		}
	}
	else if (setType == 'B') {
		while (value % 2 == 0) {
			value = random(min, max);
		}
	}
	else {
		// если заданный тип не является A или B, вернуть значение -1, чтобы указать на ошибку
		return -1;
	}
	return value;
}



int Set::Power_SetList() //вычисление мощности множества (F6)
{
	return ContainerSet.size();
}

string Set::toString(char sym)//вывод значений в виде строки (F7)
{
	if (!emptySetList())
	{
		string result = "";

		for (int elem : ContainerSet)
		{
			result += to_string(elem);//преобразуем значение в строку
			result += sym;//разделители
		}
		int len = result.length();
		return result.erase(len - 1, len); //убираем последний разделитель
	}
	return "";
}

Set::~Set()//удаление множества (F8)
{
	ContainerSet.clear();

}

//F9
bool Set::isSubset(Set* sub_set)//является ли А подмножеством B
{
	if (emptySetList())
	{
		return true;
	}
	for (int sub_elem : sub_set->ContainerSet)
		if (!elemInSetList(sub_elem))
		{
			return false;
		}
	return true;
}

//F10
bool Set::equalSet(Set* set_B)//равенство двух множеств А-В
{
	return isSubset(set_B) && set_B->isSubset(this);

}

//F11
Set* Set::unitySet(Set* set_B)//объединение двух множеств
{
	Set* set_C = new Set();
	set_C->ContainerSet.insert(ContainerSet.begin(), ContainerSet.end());
	set_C->ContainerSet.insert(set_B->ContainerSet.begin(), set_B->ContainerSet.end());
	return set_C;

}

//F12
Set* Set::intersectionSet(Set* set_B)//Пересечение двух множеств
{
	Set* set_C = new Set();
	for (int elem_B : set_B->ContainerSet)
		if (elemInSetList(elem_B))
		{
			set_C->ContainerSet.insert(elem_B);
		}
	return set_C;
}

//F13
Set* Set::differenceSet(Set* set_B)//разность двух множеств(есть в А но нет в В)
{
	Set* set_C = new Set();
	for (int elem_B : ContainerSet)
		if (!set_B->elemInSetList(elem_B))
		{
			set_C->addelem(elem_B);
		}
	return set_C;
}

//F14
Set* Set::symmetrydifferentSet(Set* set_B)//Симметричная разность двух множеств
//элементы только из 1 и только из 2 множества
// т.е.2 множества без одинаковых
{
	Set* unitySets = unitySet(set_B);//объдиняем
	Set* intersectionSets = intersectionSet(set_B);//ищем одинаковые(пересечение)
	return unitySets->differenceSet(intersectionSets);//разность множеств
}