#include "SetLab4_Zhigalov.h"
#include <iostream>
#include <random>
#include <string>
using namespace std;

random_device rd;
mt19937 gen(rd());

using namespace std;

Set::Set() //�������� ������� ���������
{
	this->ContainerListSet = list<int>();
}


bool Set::emptySetList() //������ �� ���������? (F2)
{
	return this->ContainerListSet.empty();
}

bool Set::elemInSetList(int values) //�������������� �������� ��������� (F3)
{
	list<int>::const_iterator it = find(this->ContainerListSet.begin(), this->ContainerListSet.end(), values);
	if (it != this->ContainerListSet.end()) {
		return true;
	}
	return false;
}

void Set::addelem(int values) //���������� ������ �������� � ��������� (F4)
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

int Set::random(int min, int max)//��������� ��������� ��������
{
	uniform_int_distribution<> dist(min, max);
	return dist(gen);
}
/*
   ������� 7: ��������� � - ��������� �����, ������� 7. ��������� B - ��������� �������� �����.
*/
Set::Set(int len, int min, int max, char setType) //������ ��������� (F5)
{
	this->ContainerListSet = list<int>();

	if (min > max || len <= 0 || max - min < len)
	{
		return;
	}
	list<int>::const_iterator pred_node = this->ContainerListSet.begin();
	while (len > 0)
	{
		int elem = random(min, max);
		if (setType == 'A' && elem % 7 == 0)//��������� � �� ����� ������� 7
		{

			addelem(elem);
			if (this->ContainerListSet.begin() != pred_node)
			{
				len--;
			}
			pred_node = this->ContainerListSet.begin();

		}
		if (setType == 'B' && elem % 2 == 1)//��������� B �� �������� �����
		{

			addelem(elem);
			if (this->ContainerListSet.begin() != pred_node)
			{
				len--;
			}
			pred_node = this->ContainerListSet.begin();

		}

	}
}



int Set::Power_SetList() //���������� �������� ��������� (F6)
{
	return this->ContainerListSet.size();
}

string Set::toString(char sym)//����� �������� � ���� ������ (F7)
{
	if (!emptySetList())
	{
		string result = "";

		for (int elem : this->ContainerListSet)
		{
			result += to_string(elem);//����������� �������� � ������
			result += sym;//�����������
		}
		int len = result.length();
		return result.erase(len - 1, len); //������� ��������� �����������
	}
	return "";
}

Set::~Set()//�������� ��������� (F8)
{
	this->ContainerListSet.clear();

}

//F9
bool Set::isSubset(Set* sub_set)//�������� �� � ������������� B
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

//F10
bool Set::equalSet(Set* set_B)//��������� ���� �������� �-�
{
	return isSubset(set_B) && set_B->isSubset(this);

}

//F11
Set* Set::unitySet(Set* set_B)//����������� ���� ��������
{
	Set* set_C = new Set();
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

//F12
Set* Set::intersectionSet(Set* set_B)//����������� ���� ��������
{
	Set* set_C = new Set();
	for (int elem_B : set_B->ContainerListSet)
		if (elemInSetList(elem_B))
		{
			set_C->addelem(elem_B);
		}
	return set_C;
}

//F13
Set* Set::differenceSet(Set* set_B)//�������� ���� ��������(���� � � �� ��� � �)
{
	Set* set_C = new Set();
	for (int elem_B : this->ContainerListSet)
		if (!set_B->elemInSetList(elem_B))
		{
			set_C->addelem(elem_B);
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