#pragma once
#include <string>
#include<set>
using namespace std;


class Set
{
private:
	set<int> ContainerListSet;  //Объект класса Set

public:
	Set();
	bool emptySetList();
	bool elemInSetList(int valaues);
	bool addelem(int values);
	Set(int len, int min, int max);
	int Power_SetList();
	string toString(char sym);
	~Set();
	bool isSubset(Set* sub_set);
	bool equalSet(Set* set_B);
	Set* unitySet(Set* set_B);
	Set* intersectionSet(Set* set_B);
	Set* differenceSet(Set* set_B);
	Set* symmetrydifferentSet(Set* set_B);
	int static random(int min, int max);
};