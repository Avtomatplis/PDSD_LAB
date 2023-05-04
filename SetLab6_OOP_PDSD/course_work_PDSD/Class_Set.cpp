#include "Class_Set.h"
#include <iostream>
#include <random>
#include <string>

using namespace std;
using namespace std;

//создание множества
Class_Set::Class_Set()
{
	firstElement = nullptr;
}
//Class_Set::Class_Set(const Class_Set& anotherSet)
//{
//	firstElement = nullptr;
//	Node* current = anotherSet.firstElement;
//	while (current != nullptr)
//	{
//		firstElement = addelem(current->value);
//		current = current->next;
//	}
//}

//проверка на пустое множество
bool Class_Set::emptySetList()
{
	return firstElement == nullptr;
}

//принадлежность элементу множества
bool Class_Set::elemInSetList(int values)
{
	if (!emptySetList())
	{
		for (Node* elem = firstElement; elem != nullptr; elem = elem->next)
		{
			if (elem->value == values)
			{
				return true;
			}
		}
	}
	return false;
}

//добавление элемента в множество
void Class_Set::addelem(int values)
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


int Class_Set::random(int min, int max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(min, max);
	return dist(gen);
}

//генераци€ двух множеств
Class_Set::Class_Set(int len, int min, int max)
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
			addelem(elem);
			if (firstElement != pred_node)
			{
				len--;
			}
			pred_node = firstElement;
	}
}

//мощность множества
int Class_Set::Power_SetList()
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

//вывод множества
string Class_Set::toString(char sym)
{
	if (!emptySetList())
	{
		string result = "";
		for (Node* elem = firstElement; elem != nullptr; elem = elem->next)
		{
			result += to_string(elem->value);
			result += sym;
		}
		int len = result.length();
		return result.erase(len - 1, len);
	}
	return "";
}

//удал€ем множество
Class_Set::~Class_Set()
{
	while (firstElement != nullptr)
	{
		Node* next = firstElement->next;
		delete firstElement;
		firstElement = next;
	}
}

//явл€етс€ ј подмножеством ¬
bool Class_Set::isSubset(Class_Set* subset)
{
	if (emptySetList())
	{
		return true;
	}
	for (Node* sub_elem = subset->firstElement; sub_elem != nullptr; sub_elem = sub_elem->next)
		if (!elemInSetList(sub_elem->value))
		{
			return false;
		}
	return true;
}

//F10 равенство двух множеств
bool Class_Set::equalSet(Class_Set* set_B )
{
	return isSubset(set_B) && set_B->isSubset(this);
}

//F11 обьединение множеств
Class_Set* Class_Set::unitySet(Class_Set* set_B)
{
	Class_Set* set_C = new Class_Set();
	for (Node* elem_A = firstElement; elem_A != nullptr; elem_A = elem_A->next)
	{
		set_C->addelem(elem_A->value);
	}
	for (Node* elem_B = set_B->firstElement; elem_B != nullptr; elem_B = elem_B->next)
	{
		set_C->addelem(elem_B->value);
	}
	return set_C;
}

//F12 пересечение двух множеств
Class_Set* Class_Set::intersectionSet(Class_Set* set_B)
{
	Class_Set* set_C = new Class_Set();
	for (Node* elem_B = set_B->firstElement; elem_B != nullptr; elem_B = elem_B->next)
		if (elemInSetList(elem_B->value))
		{
			set_C->addelem(elem_B->value);
		}
	return set_C;
}

//F13 разность двух множеств
Class_Set* Class_Set::differenceSet(Class_Set* set_B)
{
	Class_Set* set_C = new Class_Set();
	for (Node* elem_B = firstElement; elem_B != nullptr; elem_B = elem_B->next)
		if (!set_B->elemInSetList(elem_B->value))
		{
			set_C->addelem(elem_B->value);
		}
	return set_C;
}

//F14 симметрична€ разность двух множеств
Class_Set* Class_Set::symmetrydifferentSet(Class_Set* set_B)
{
	Class_Set* unitySets = unitySet(set_B);
	Class_Set* intersectionSets = intersectionSet(set_B);
	return unitySets->differenceSet(intersectionSets);
}