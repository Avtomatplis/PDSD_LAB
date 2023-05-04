#pragma once
#include <string>
#include<set>

using namespace std;

class MultiSet {
private:
	multiset<int> ContainerMultiSet; // ������ ������ multiset

public:
	MultiSet(); // ����������� �� ���������

	MultiSet(const MultiSet& anotherSet); //����������� �����������

	bool emptySetList(); // �������� �� �������

	bool elemInSetList(int valaues); // �������� �� ������� �������� � ���������

	bool addelem(int values); // ���������� �������� � ���������

	MultiSet(int len, int min, int max, char setType); // ����������� � �����������

	int Power_SetList(); // �������� ���������

	string toString(char sym); // ����� ��������� � ���� ������

	MultiSet(); // ����������

	bool isSubset(MultiSet* sub_set); // �������� �� ������������

	bool equalSet(MultiSet* set_B); // �������� �� ��������� ��������

	MultiSet* unitySet(MultiSet& anotherSet); // ����������� ��������

	MultiSet* intersectionSet(MultiSet& anotherSet); // ����������� ��������

	MultiSet* differenceSet(MultiSet anotherSet); // �������� ��������

	MultiSet* symmetrydifferentSet(MultiSet& anotherSet); // �������������� �������� ��������

	static int random(int min, int max); // ��������� ���������� ����� � ��������� �� min �� max
};