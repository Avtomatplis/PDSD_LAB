#pragma once
#include <string>
#include "Node.h"
using namespace std;

class Class_Set
{
private:
	Node* firstElement; //указатель на голову списка
public:
	Class_Set();
	bool emptySetList();
	bool elemInSetList(int valaues);
	void addelem(int values);
	Class_Set(int len, int min, int max);
	int Power_SetList();
	string toString(char sym);
	~Class_Set();
	bool isSubset(Class_Set* sub_set);
	bool equalSet(Class_Set* set_B);
	Class_Set* unitySet(Class_Set* set_B);
	Class_Set* intersectionSet(Class_Set* set_B);
	Class_Set* differenceSet(Class_Set* set_B);
	Class_Set* symmetrydifferentSet(Class_Set* set_B);
	int static random(int min, int max);
};