//#include "Set.h"
//#include <iostream>
//#include <random>
//#include <string>
//#include "Unordered_Multiset.h"
//
//using namespace std;
//
//UnorderedMultiset::UnorderedMultiset() //ñîçäàíèå ïóñòîãî ìíîæåñòâà
//{
//	ContainerMultiset = unordered_multiset<int>();
//}
//
//
//bool UnorderedMultiset::emptySetList() //Ïóñòîå ëè ìíîæåñòâî? (F2)
//{
//	return ContainerMultiset.empty();
//}
//
//bool UnorderedMultiset::elemInSetList(int values) //ïðèíàäëåæíîñòü ýëåìåíòà ìíîæåñòâó (F3)
//{
//	return ContainerMultiset.contains(values);
//}
//
//bool UnorderedMultiset::addelem(int values) //äîáàâëåíèå íîâîãî ýëåìåíòà â ìíîæåñòâî (F4)
//{
//	if (elemInSetList(values))
//	{
//		return false;
//	}
//	else
//	{
//		this->ContainerMultiset.insert(values);
//		return true;
//	}
//
//	//return	ContainerMultiset.insert(values).second;
//}
//
//int UnorderedMultiset::random(int min, int max)//ãåíåðàöèÿ ðàíäîìíûõ çíà÷åíèé
//{
//	random_device rd;
//	mt19937 gen(rd());
//	uniform_int_distribution<> dist(min, max);
//	return dist(gen);
//}
///*
//   Âàðèàíò 7: Ìíîæåñòâî À - ìíîæåñòâî ÷èñåë, êðàòíûõ 7. Ìíîæåñòâî B - ìíîæåñòâî íå÷åòíûõ ÷èñåë.
//*/
//UnorderedMultiset::UnorderedMultiset(int len, int min, int max){
//	ContainerMultiset = unordered_multiset<int>();
//
//	if (min > max || len <= 0 || max - min < len)
//	{
//		return;
//	}
//
//	while (len > 0)
//	{
//		bool check = addelem(random(min, max));
//		if (check)
//		{
//			len--;
//		}
//	}
//}
//
//int UnorderedMultiset::Power_SetList() //âû÷èñëåíèå ìîùíîñòè ìíîæåñòâà (F6)
//{
//	return ContainerMultiset.size();
//}
//
//string UnorderedMultiset::toString(char sym)//âûâîä çíà÷åíèé â âèäå ñòðîêè (F7)
//{
//	if (!emptySetList())
//	{
//		string result = "";
//
//		for (int elem : ContainerMultiset)
//		{
//			result += to_string(elem);//ïðåîáðàçóåì çíà÷åíèå â ñòðîêó
//			result += sym;//ðàçäåëèòåëè
//		}
//		int len = result.length();
//		return result.erase(len - 1, len); //óáèðàåì ïîñëåäíèé ðàçäåëèòåëü
//	}
//	return "";
//}
//
//UnorderedMultiset ::~UnorderedMultiset()//óäàëåíèå ìíîæåñòâà (F8)
//{
//	ContainerMultiset.clear();
//
//}
//
////F9
//bool UnorderedMultiset::isSubset(UnorderedMultiset* sub_set)//ÿâëÿåòñÿ ëè À ïîäìíîæåñòâîì B
//{
//	if (emptySetList())
//	{
//		return true;
//	}
//	for (int sub_elem : sub_set->ContainerMultiset)
//		if (!elemInSetList(sub_elem))
//		{
//			return false;
//		}
//	return true;
//}
//
////F10
//bool UnorderedMultiset::equalSet(UnorderedMultiset* set_B)//ðàâåíñòâî äâóõ ìíîæåñòâ À-Â
//{
//	return isSubset(set_B) && set_B->isSubset(this);
//
//}
//
////F11
//UnorderedMultiset* UnorderedMultiset::unitySet(UnorderedMultiset* set_B)//îáúåäèíåíèå äâóõ ìíîæåñòâ
//{
//	UnorderedMultiset* set_C = new UnorderedMultiset();
//	set_C->ContainerMultiset.insert(ContainerMultiset.begin(), ContainerMultiset.end());
//	set_C->ContainerMultiset.insert(set_B->ContainerMultiset.begin(), set_B->ContainerMultiset.end());
//	return set_C;
//
//}
//
////F12
//UnorderedMultiset* UnorderedMultiset::intersectionSet(UnorderedMultiset* set_B)//Ïåðåñå÷åíèå äâóõ ìíîæåñòâ
//{
//	UnorderedMultiset* set_C = new UnorderedMultiset();
//	for (int elem_B : set_B->ContainerMultiset)
//		if (elemInSetList(elem_B))
//		{
//			set_C->ContainerMultiset.insert(elem_B);
//		}
//	return set_C;
//}
//
////F13
//UnorderedMultiset* UnorderedMultiset::differenceSet(UnorderedMultiset anotherSet)//Разность множеств
//{
//	UnorderedMultiset* set_C = new UnorderedMultiset();
//	for (int elem_B : ContainerMultiset)
//		if (!anotherSet.elemInSetList(elem_B))
//		{
//			set_C->addelem(elem_B);
//		}
//	return set_C;
//}
//
////F14
//UnorderedMultiset* UnorderedMultiset::symmetrydifferentSet(UnorderedMultiset* set_B)//Ñèììåòðè÷íàÿ ðàçíîñòü äâóõ ìíîæåñòâ
////ýëåìåíòû òîëüêî èç 1 è òîëüêî èç 2 ìíîæåñòâà
//// ò.å.2 ìíîæåñòâà áåç îäèíàêîâûõ
//{
//	UnorderedMultiset* unitySets = unitySet(set_B);//îáúäèíÿåì
//	UnorderedMultiset* intersectionSets = intersectionSet(set_B);//èùåì îäèíàêîâûå(ïåðåñå÷åíèå)
//	return unitySets->differenceSet(intersectionSets);//ðàçíîñòü ìíîæåñòâ
//}