#include "SetLab1_2_3_Zhigalov.h"
#include <iostream>
#include <random>
#include <string>
using namespace std;

random_device rd;
mt19937 gen(rd());

using namespace std;

Set::Set() //�������� ������� ���������
{
	firstElement = nullptr;
}


bool Set::emptySetList() //������ �� ���������? (F2)
{
	return firstElement == nullptr;
}

bool Set::elemInSetList( int values) //�������������� �������� ��������� (F3)
{
	if (!emptySetList())
	{
		for (Node* elem = firstElement; elem != nullptr; elem = elem->next)
		{
			if (elem->value == values) //���� ������� ���� � ���������, �� ������
			{
				return true;
			}
		}
	}
	return false;
}

void Set::addelem( int values) //���������� ������ �������� � ��������� (F4)
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

int Set:: random(int min, int max)//��������� ��������� ��������
{
	uniform_int_distribution<> dist(min, max);
	return dist(gen);
}
/*
   ������� 7: ��������� � - ��������� �����, ������� 7. ��������� B - ��������� �������� �����.
*/
Set::Set(int len, int min, int max, char setType) //������ ��������� (F5)
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
		if (setType == 'A' && elem%7==0)//��������� � �� ����� ������� 7
		{
		
				addelem(elem);
				if (firstElement != pred_node)
				{
					len--;
				}
				pred_node = firstElement;
			
		}
		if (setType == 'B' && elem % 2 == 1)//��������� B �� �������� �����
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



int Set::Power_SetList() //���������� �������� ��������� (F6)
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

string Set::toString( char sym)//����� �������� � ���� ������ (F7)
{
	if (!emptySetList())
	{
		string result = "";

		for (Node* elem = firstElement; elem != nullptr; elem = elem->next)
		{
			result += to_string(elem->value);//����������� �������� � ������
			result += sym;//�����������
		}
		int len = result.length();
		return result.erase(len - 1, len); //������� ��������� �����������
	}
	return "";
}

Set::~Set()//�������� ��������� (F8)
{
	while (firstElement != nullptr)
	{
		Node* next = firstElement->next;
		delete firstElement;
		firstElement = next;
	}

}

//F9
bool Set::isSubset(Set* sub_set)//�������� �� � ������������� B
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
bool Set::equalSet(Set* set_B)//��������� ���� �������� �-�
{
	return isSubset(set_B) && set_B->isSubset(this);

}

//F11
Set* Set::unitySet(Set* set_B)//����������� ���� ��������
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
Set* Set::intersectionSet(Set* set_B)//����������� ���� ��������
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
Set* Set::differenceSet(Set* set_B)//�������� ���� ��������(���� � � �� ��� � �)
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
Set* Set::symmetrydifferentSet(Set* set_B)//������������ �������� ���� ��������
//�������� ������ �� 1 � ������ �� 2 ���������
// �.�.2 ��������� ��� ����������
{
	Set* unitySets = unitySet(set_B);//���������
	Set* intersectionSets = intersectionSet(set_B);//���� ����������(�����������)
	return unitySets->differenceSet(intersectionSets);//�������� ��������
}

