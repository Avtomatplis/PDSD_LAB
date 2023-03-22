#include "SetLab1_2_3_Zhigalov.h"
#include <iostream>
#include <random>
#include <string>
using namespace std;

random_device rd;
mt19937 gen(rd());

using namespace std;

Set::Set() //создание пустого множества
{
	firstElement = nullptr;
}


bool Set::emptySetList() //Пустое ли множество? (F2)
{
	return firstElement == nullptr;
}

bool Set::elemInSetList( int values) //принадлежность элемента множеству (F3)
{
	if (!emptySetList())
	{
		for (Node* elem = firstElement; elem != nullptr; elem = elem->next)
		{
			if (elem->value == values) //если элемент есть в множестве, то истина
			{
				return true;
			}
		}
	}
	return false;
}

void Set::addelem( int values) //добавление нового элемента в множество (F4)
{
	if (elemInSetList(values))
	{
		return;
	}
	else
	{
		Node* node = new Node();
		node->value = values;
		node->next = firstElement;
		firstElement = node;
		
	}
}

int Set:: random(int min, int max)//генерация рандомных значений
{
	uniform_int_distribution<> dist(min, max);
	return dist(gen);
}
/*
   Вариант 7: Множество А - множество чисел, кратных 7. Множество B - множество нечетных чисел.
*/
Set::Set(int len, int min, int max, char setType) //создаём множество (F5)
{
	firstElement = nullptr;

	if (min > max || len <= 0 || max - min < len)
	{
		return;
	}
	Node* pred_node = firstElement;
	while (len > 0)
	{
		int elem = random(min, max);
		if (setType == 'A' && elem%7==0)//множество А из чисел кратных 7
		{
		
				addelem(elem);
				if (firstElement != pred_node)
				{
					len--;
				}
				pred_node = firstElement;
			
		}
		if (setType == 'B' && elem % 2 == 1)//Множество B из нечетных чисел
		{
		
				addelem(elem);
				if (firstElement != pred_node)
				{
					len--;
				}
				pred_node = firstElement;

		}
	
	}		
}



int Set::Power_SetList() //вычисление мощности множества (F6)
{
	if (emptySetList())
	{
		return 0;
	}
	else
	{
		int len = 0;
		for (Node* elem = firstElement; elem != nullptr; elem = elem->next)
		{
			len++;
		}
		return len;
	}
}

string Set::toString( char sym)//вывод значений в виде строки (F7)
{
	if (!emptySetList())
	{
		string result = "";

		for (Node* elem = firstElement; elem != nullptr; elem = elem->next)
		{
			result += to_string(elem->value);//преобразуем значение в строку
			result += sym;//разделители
		}
		int len = result.length();
		return result.erase(len - 1, len); //убираем последний разделитель
	}
	return "";
}

Set::~Set()//удаление множества (F8)
{
	while (firstElement != nullptr)
	{
		Node* next = firstElement->next;
		delete firstElement;
		firstElement = next;
	}

}

//F9
bool Set::isSubset(Set* sub_set)//является ли А подмножеством B
{
	if (emptySetList())
	{
		return true;
	}
	for (Node* sub_elem = sub_set->firstElement; sub_elem != nullptr; sub_elem = sub_elem->next)
		if (!elemInSetList(sub_elem->value))
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
	for (Node* elem_A = firstElement; elem_A != nullptr; elem_A = elem_A->next)
	{
		set_C ->addelem(elem_A->value);

	}
	for (Node* elem_B = set_B->firstElement; elem_B != nullptr; elem_B = elem_B->next)
	{
		set_C->addelem(elem_B->value);
	}
	return set_C;

}

//F12
Set* Set::intersectionSet(Set* set_B)//Пересечение двух множеств
{
	Set* set_C = new Set();
	for (Node* elem_B = set_B->firstElement; elem_B != nullptr; elem_B = elem_B->next)
		if (elemInSetList(elem_B->value))
		{
			set_C->addelem(elem_B->value);
		}
	return set_C;
}

//F13
Set* Set::differenceSet(Set* set_B)//разность двух множеств(есть в А но нет в В)
{
	Set* set_C = new Set();
	for (Node* elem_B = firstElement; elem_B != nullptr; elem_B = elem_B->next)
		if (!set_B->elemInSetList(elem_B->value))
		{
			set_C->addelem(elem_B->value);
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

