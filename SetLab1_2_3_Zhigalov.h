#pragma once
#include <string>
using namespace std;

struct Node {
	int value;
	Node* next;

};
 class Set
 {
 private:
		 Node* firstElement;
 public:
	Set();//�����������-c������� ������� ���������

	bool emptySetList();//�������� �� ������ ���������?

	bool elemInSetList( int valaues);//�������� �������������� �������� ���������

	void addelem( int values);//���������� ������ �������� � ���������

	Set(int len, int min, int max, char setType);//�������� ���������

	int Power_SetList();//�������� ���������

	string toString( char sym);//����� ��������� ��������� � ������� ������������

	~Set();//���������� - �������� ���������

	bool isSubset(Set* sub_set);//������������ � - �.

	bool equalSet(Set* set_B);//��������� �������� � - �.

	Set* unitySet(Set* set_B);//����������� ���� ��������.

	Set* intersectionSet(Set* set_B);//����������� ���� ��������.

	Set* differenceSet(Set* set_B);//�������� ���� ��������.

	Set* symmetrydifferentSet(Set* set_B);//������������ �������� ���� ��������.

	int static random(int min, int max);//��������� �������� ��������� �� 6 �� 9 ���������

};
