#pragma once
#include <string>
#include <unordered_set>

using namespace std;

class UnorderedMultiset 
{
private:
	unordered_multiset<int> ContainerMultiset;  //������ ������ unordered_multiset
public:
	UnorderedMultiset(); // ����������� �� ���������

	UnorderedMultiset(const UnorderedMultiset& anotherSet);//����������� �����������

	bool emptySetList(); // �������� �� �������

	bool elemInSetList(int valaues); // �������� �� ������� �������� � ���������

	bool addelem(int values); // ���������� �������� � ���������

	UnorderedMultiset(int len, int min, int max); // ����������� � �����������

	int Power_SetList(); // �������� ���������

	string toString(char sym); // ����� ��������� � ���� ������

	~UnorderedMultiset(); // ����������

	bool isSubset(UnorderedMultiset* sub_set); // �������� �� ������������

	bool equalSet(UnorderedMultiset* set_B); // �������� �� ��������� ��������

	UnorderedMultiset* unitySet(UnorderedMultiset* set_B); // ����������� ��������

	UnorderedMultiset* intersectionSet(UnorderedMultiset* set_B); // ����������� ��������

	UnorderedMultiset* differenceSet(UnorderedMultiset anotherSet); // �������� ��������

	UnorderedMultiset* symmetrydifferentSet(UnorderedMultiset* set_B); // �������������� �������� ��������

	static int random(int min, int max); // ��������� ���������� ����� � ��������� �� min �� max
};