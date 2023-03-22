#include "SetLab1_2_Zhigalov.h"
#include <iostream>
#include <random>
#include <string>
using namespace std;

random_device rd;
mt19937 gen(rd());

using namespace std;


Node* createSetList() //создаём пустое множество (F1)
{
	return nullptr;
}


bool emptySetList(Node* firstElement) //Пустое ли множество? (F2)
{
	return firstElement == nullptr;
}

bool elemInSetList(Node* firstElement, int values) //принадлежность элемента множеству (F3)
{
	if (!emptySetList(firstElement)) 
	{
		for (Node* elem= firstElement; elem != nullptr; elem = elem->next) 
		{
			if (elem->value == values) //если элемент есть в множестве, то истина
			{
				return true;
			}
		}
	}
	return false;
}

Node* addelem(Node* firstElement, int values) //добавление нового элемента в множество (F4)
{
	if (elemInSetList(firstElement, values))
	{
		return firstElement;
	} 
	else 
	{
		Node* node = new Node();
		node->next = firstElement;
		node->value = values;
		return node;
	}
}

int random(int min, int max)//генерация рандомных значений
{
	uniform_int_distribution<> dist(min, max);
	return dist(gen);
}
/*
   Вариант 7: Множество А - множество чисел, кратных 7. Множество B - множество нечетных чисел.
*/
Node* createSetList(int len, int min, int max,char setType) //создаём множество (F5)
{
	Node* set = createSetList();

	if (min > max || len <= 0 || max - min < len)
	{
		return set;
	}
    Node* set1 = set;
	while (len > 0)
	{
		int elem = random(min, max);
		if (setType == 'A')
		{
			if (elem % 7 == 0) // добавляем только элементы кратные 7
			{
				set = addelem(set, elem);
				if (set != set1)
				{
					len--;
					set1 = set;
				}
			}
		}
		else if (setType == 'B') 
		{
			if (elem % 2 == 1) // добавляем только нечетные элементы
			{
				set = addelem(set, elem);
				if (set != set1)
				{
					len--;
					set1 = set;
				}
			}
		}
		
	}

		return set;
}

int Power_SetList(Node* firstElement) //вычисление мощности множества (F6)
{
	if (emptySetList(firstElement)) 
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

string toString(Node* firstElement, char sym)//вывод значений в виде строки (F7)
{
	if (!emptySetList(firstElement)) 
	{
		string result = "";

		for (Node* elem = firstElement; elem != nullptr; elem = elem->next)
		{
			result += to_string(elem->value);//преобразуем значение в строку
			result += sym;//разделители
		}
		int len = result.length();
		return result.erase(len-1, len); //убираем последний разделитель
	}
	return "";
}

Node* deleteSetList(Node* firstElement)//удаление множества (F8)
{
	while (firstElement!= nullptr) 
	{
		Node* next = firstElement->next;
		delete firstElement; 
		firstElement = next;
	}
	return firstElement;
}

//F9
bool isSubset(Node* A, Node* B)//является ли А подмножеством B
{
	if (emptySetList(A))
	{
		return true;
	}
	for (Node* elem_A = A; elem_A != nullptr; elem_A=elem_A->next)
			if (!elemInSetList(B,elem_A->value ))
			{
				return false;
			}
	return true;
}

//F10
bool equalSet(Node* firstElement_A, Node* firstElement_B)//равенство двух множеств А-В
{
	return isSubset(firstElement_B, firstElement_A)&& isSubset(firstElement_A, firstElement_B);

}

//F11
Node* unitySet(Node* firstElement_A, Node* firstElement_B)//объединение двух множеств
{
	Node* set_C = createSetList();
	for (Node* elem_A = firstElement_A; elem_A != nullptr; elem_A = elem_A->next)
	{
		set_C = addelem(set_C, firstElement_A->value);
		firstElement_A = firstElement_A->next;
	}
	for (Node* elem_B = firstElement_B; elem_B != nullptr; elem_B = elem_B->next)
	{
		set_C = addelem(set_C, firstElement_B->value);
		firstElement_B = firstElement_B->next;
	}
	return set_C;
	
}

//F12
Node* intersectionSet(Node* firstElement_A, Node* firstElement_B)//Пересечение двух множеств
{
	Node* set_C = createSetList();
	for (Node* elem_A = firstElement_A; elem_A != nullptr; elem_A = elem_A->next)
		if (elemInSetList(firstElement_B, elem_A->value))
		{
			set_C = addelem(set_C, elem_A->value);
		}
	return set_C;
}

//F13
Node* differenceSet(Node* firstElement_A, Node* firstElement_B)//разность двух множеств(есть в А но нет в В)
{
	Node* set_C = createSetList();
	for(Node* elem_A=firstElement_A;elem_A!=nullptr;elem_A=elem_A->next)
		if (!elemInSetList(firstElement_B, elem_A->value))
		{
			set_C = addelem(set_C, elem_A->value);
		}
	return set_C;
}

//F14
Node* symmetrydifferentSet(Node* firstElement_A, Node* firstElement_B)//Симметричная разность двух множеств
                                                                      //элементы только из 1 и только из 2 множества
	                                                                  // т.е.2 множества без одинаковых
{
	Node* unitySets = unitySet(firstElement_A, firstElement_B);//объдиняем
	Node* intersectionSets = intersectionSet(firstElement_A, firstElement_B);//ищем одинаковые(пересечение)
	return differenceSet(unitySets, intersectionSets);//разность множеств
}