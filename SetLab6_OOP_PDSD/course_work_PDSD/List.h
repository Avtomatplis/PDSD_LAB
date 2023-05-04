#pragma once
#include <string>
#include<list>

using namespace std;

class List
{
private:
	list<int> ContainerListSet;  //������ ������ list
public:
	List();//c������� ������� ���������

	bool emptySetList();//�������� �� ������ ���������?

	bool elemInSetList(int valaues);//�������� �������������� �������� ���������

	void addelem(int values);//���������� �������� � ���������

	List(int len, int min, int max);//�������� ���������

	int Power_SetList();//�������� ���������

	string toString(char sym);//����� ��������� ���������

	~List();//���������� - �������� ���������

	bool isSubset(List* sub_set);//������������ � - �.

	bool equalSet(List* set_B);//��������� �������� � - �.

	List* unitySet(List* set_B);//����������� ���� ��������.

	List* intersectionSet(List* set_B);//����������� ���� ��������.

	List* differenceSet(List* set_B);//�������� ���� ��������.

	List* symmetrydifferentSet(List* set_B);//������������ �������� ���� ��������.

	int static random(int min, int max);//��������� �������� ��������� �� 6 �� 9 ���������

};