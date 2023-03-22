#include<iostream>

#include "SetLab1_2_Zhigalov.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	Node* SetList_A = createSetList(random(6, 9), 10, 99, 'A');
	Node* SetList_B = createSetList(random(6, 9), 10, 99, 'B');
	cout << "�������� ��������� �: " << toString(SetList_A, ' ') << endl;
    cout << "�������� ��������� �: " << Power_SetList(SetList_A) << endl;
	cout << "����� ��������� �: " << toString(SetList_A, ' ,') << endl;
	//SetList_A = deleteSetList(SetList_A);
	//cout << "�������� ��������� � " << endl;
	//cout << "�������� ��������� �: " << Power_SetList(SetList_A) << endl;
	//cout << "����� ��������� �: " << toString(SetList_A, ' ,') << endl;
	cout << "" << endl;
	cout << "�������� ��������� B: " << toString(SetList_B, ' ') << endl;
	cout << "�������� ��������� B: " << Power_SetList(SetList_B) << endl;
	cout << "����� ��������� B: " << toString(SetList_B, ' ,') << endl;
	//SetList_B = deleteSetList(SetList_B);
	//cout << "�������� ��������� B " << endl;
	//cout << "�������� ��������� B: " << Power_SetList(SetList_B) << endl;
	cout << "������������ �-B: " <<boolalpha<< isSubset(SetList_A, SetList_B) << endl;
	cout << "������������ �-A: " << boolalpha << isSubset(SetList_A, SetList_A) << endl;
	cout << "��������� ���� �������� �-B: " << boolalpha << equalSet(SetList_A, SetList_B) << endl;
	cout << "��������� ���� �������� �-A: " << boolalpha << equalSet(SetList_A, SetList_A) << endl;
	cout << "����������� ���� �������� �-B: " << toString(unitySet(SetList_A, SetList_B), ' ') << endl;
	cout << "����������� ���� �������� �-B: " << toString(intersectionSet(SetList_A, SetList_B), ' ') << endl;
	cout << "�������� ���� �������� �-B: " << toString(differenceSet(SetList_A, SetList_B), ' ') << endl;
	cout << "�������� ���� �������� B-A: " << toString(differenceSet(SetList_B, SetList_A), ' ') << endl;
	cout << "C����������� �������� ���� �������� �-�: " << toString(symmetrydifferentSet(SetList_A, SetList_B), ' ') << endl;
	cout << "" << endl;
	SetList_A = deleteSetList(SetList_A);
	SetList_B = deleteSetList(SetList_B);
	cout << "�������� ��������� � " << endl;
	cout << "�������� ��������� B " << endl;
	cout << "����� ��������� A: " << toString(SetList_A, ' ,') << endl;
	cout << "����� ��������� B: " << toString(SetList_B, ' ,') << endl;
}