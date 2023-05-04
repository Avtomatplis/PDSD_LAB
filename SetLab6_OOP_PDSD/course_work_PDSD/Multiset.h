#pragma once
#include <string>
#include<set>

using namespace std;

class MultiSet {
private:
	multiset<int> ContainerMultiSet; // объект класса multiset

public:
	MultiSet(); // конструктор по умолчанию

	MultiSet(const MultiSet& anotherSet); //конструктор копирования

	bool emptySetList(); // проверка на пустоту

	bool elemInSetList(int valaues); // проверка на наличие элемента в множестве

	bool addelem(int values); // добавление элемента в множество

	MultiSet(int len, int min, int max, char setType); // конструктор с параметрами

	int Power_SetList(); // мощность множества

	string toString(char sym); // вывод множества в виде строки

	MultiSet(); // деструктор

	bool isSubset(MultiSet* sub_set); // проверка на подмножество

	bool equalSet(MultiSet* set_B); // проверка на равенство множеств

	MultiSet* unitySet(MultiSet& anotherSet); // объединение множеств

	MultiSet* intersectionSet(MultiSet& anotherSet); // пересечение множеств

	MultiSet* differenceSet(MultiSet anotherSet); // разность множеств

	MultiSet* symmetrydifferentSet(MultiSet& anotherSet); // симметрическая разность множеств

	static int random(int min, int max); // генерация случайного числа в диапазоне от min до max
};