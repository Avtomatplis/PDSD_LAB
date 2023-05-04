#include "List.h"
#include <iostream>
#include <random>
#include <string>

using namespace std;

List::List() //�������� ������� ���������
{
	this->ContainerListSet = list<int>();
}


bool List::emptySetList() //�������� �� ������ ��������� (F2)
{
	return this->ContainerListSet.empty();
}

bool List::elemInSetList(int values) //�������� �������������� �������� ��������� (F3)
{
	list<int>::const_iterator it = find(this->ContainerListSet.begin(),
		this->ContainerListSet.end(),	values);
	if (it != this->ContainerListSet.end())
	{
		return true;
	}
	return false;
}

void List::addelem(int values) //���������� �������� � ��������� (F4)
{
	if (elemInSetList(values))
	{
		return;
	}
	else
	{
		this->ContainerListSet.push_front(values);
	}
}

int List::random(int min, int max)//��������� ���������� ��������
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(min, max);
	return dist(gen);
}

List::List(int len, int min, int max) //�������� ��������� (F5)
{
	this->ContainerListSet = list<int>();

	if (min > max || len <= 0 || max - min < len)
	{
		return;
	}
	list<int>::const_iterator pred_node = this->ContainerListSet.begin();
	while (len > 0)
	{
		
			addelem(random(min, max));
			if (this->ContainerListSet.begin() != pred_node)
			{
				len--;
			}
			pred_node = this->ContainerListSet.begin();
	}
}

int List::Power_SetList() //�������� ��������� (F6)
{
	return this->ContainerListSet.size();
}

string List::toString(char sym)//����� ��������� ��������� (F7)
{
	if (!emptySetList())
	{
		string result = "";

		for (int elem : this->ContainerListSet)
		{
			result += to_string(elem);
			result += sym;
		}
		int len = result.length();
		return result.erase(len - 1, len);
	}
	return "";
}

List::~List()//�������� ��������� (F8)
{
	this->ContainerListSet.clear();

}

//F9
bool List::isSubset(List* sub_set)//������������ �-B
{
	if (emptySetList())
	{
		return true;
	}
	for (int sub_elem : sub_set->ContainerListSet)
		if (!elemInSetList(sub_elem))
		{
			return false;
		}
	return true;
}

bool List::equalSet(List* set_B)//��������� �������� �-� F10
{
	return isSubset(set_B) && set_B->isSubset(this);
}

List* List::unitySet(List* set_B)//����������� �������� 
{
	List* set_C = new List();
	for (int elem_A : this->ContainerListSet)
	{
		set_C->addelem(elem_A);

	}
	for (int elem_B : set_B->ContainerListSet)
	{
		set_C->addelem(elem_B);
	}
	return set_C;

}

List* List::intersectionSet(List* set_B)//����������� �������� F12
{
	List* set_C = new List();
	for (int elem_B : set_B->ContainerListSet)
		if (elemInSetList(elem_B))
		{
			set_C->addelem(elem_B);
		}
	return set_C;
}

List* List::differenceSet(List* set_B) //�������� ���� �������� F13
{
	List* set_C = new List();
	for (int elem_B : this->ContainerListSet)
		if (!set_B->elemInSetList(elem_B))
		{
			set_C->addelem(elem_B);
		}
	return set_C;
}

List* List::symmetrydifferentSet(List* set_B) //����������� �������� ���� �������� F14
{
	List* unitySets = unitySet(set_B);
	List* intersectionSets = intersectionSet(set_B);
	return unitySets->differenceSet(intersectionSets);
}