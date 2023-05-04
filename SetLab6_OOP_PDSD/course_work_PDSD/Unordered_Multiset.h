#pragma once
#include <string>
#include <unordered_set>

using namespace std;

class UnorderedMultiset 
{
private:
	unordered_multiset<int> ContainerMultiset;  //объект класса unordered_multiset
public:
	UnorderedMultiset(); // конструктор по умолчанию

	UnorderedMultiset(const UnorderedMultiset& anotherSet);//конструктор копирования

	bool emptySetList(); // проверка на пустоту

	bool elemInSetList(int valaues); // проверка на наличие элемента в множестве

	bool addelem(int values); // добавление элемента в множество

	UnorderedMultiset(int len, int min, int max); // конструктор с параметрами

	int Power_SetList(); // мощность множества

	string toString(char sym); // вывод множества в виде строки

	~UnorderedMultiset(); // деструктор

	bool isSubset(UnorderedMultiset* sub_set); // проверка на подмножество

	bool equalSet(UnorderedMultiset* set_B); // проверка на равенство множеств

	UnorderedMultiset* unitySet(UnorderedMultiset* set_B); // объединение множеств

	UnorderedMultiset* intersectionSet(UnorderedMultiset* set_B); // пересечение множеств

	UnorderedMultiset* differenceSet(UnorderedMultiset anotherSet); // разность множеств

	UnorderedMultiset* symmetrydifferentSet(UnorderedMultiset* set_B); // симметрическая разность множеств

	static int random(int min, int max); // генерация случайного числа в диапазоне от min до max
};