#include "SetLab5_Zhigalov.h"
#include <iostream>
#include <random>
#include <string>
using namespace std;

random_device rd;
mt19937 gen(rd());

using namespace std;

Set::Set() //�������� ������� ���������
{
	ContainerSet = set<int>();
}


bool Set::emptySetList() //������ �� ���������? (F2)
{
	return ContainerSet.empty();
}

bool Set::elemInSetList(int values) //�������������� �������� ��������� (F3)
{
	return ContainerSet.contains(values);
}

bool Set::addelem(int values) //���������� ������ �������� � ��������� (F4)
{
	
	return	ContainerSet.insert(values).second;

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
		// ���� �������� ��� �� �������� A ��� B, ������� �������� -1, ����� ������� �� ������
		return -1;
	}
	return value;
}



int Set::Power_SetList() //���������� �������� ��������� (F6)
{
	return ContainerSet.size();
}

string Set::toString(char sym)//����� �������� � ���� ������ (F7)
{
	if (!emptySetList())
	{
		string result = "";

		for (int elem : ContainerSet)
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
	ContainerSet.clear();

}

//F9
bool Set::isSubset(Set* sub_set)//�������� �� � ������������� B
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
bool Set::equalSet(Set* set_B)//��������� ���� �������� �-�
{
	return isSubset(set_B) && set_B->isSubset(this);

}

//F11
Set* Set::unitySet(Set* set_B)//����������� ���� ��������
{
	Set* set_C = new Set();
	set_C->ContainerSet.insert(ContainerSet.begin(), ContainerSet.end());
	set_C->ContainerSet.insert(set_B->ContainerSet.begin(), set_B->ContainerSet.end());
	return set_C;

}

//F12
Set* Set::intersectionSet(Set* set_B)//����������� ���� ��������
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
Set* Set::differenceSet(Set* set_B)//�������� ���� ��������(���� � � �� ��� � �)
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
Set* Set::symmetrydifferentSet(Set* set_B)//������������ �������� ���� ��������
//�������� ������ �� 1 � ������ �� 2 ���������
// �.�.2 ��������� ��� ����������
{
	Set* unitySets = unitySet(set_B);//���������
	Set* intersectionSets = intersectionSet(set_B);//���� ����������(�����������)
	return unitySets->differenceSet(intersectionSets);//�������� ��������
}