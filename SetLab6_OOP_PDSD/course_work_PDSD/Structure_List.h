#pragma once

#include <string>
#include<random>
#include "Node.h"
using namespace std;


Node* createSetList(); //�������� ������� ��������� F1

bool emptySetList(Node* firstElement); //������ ���������? F2

bool elemInSetList(Node* firstElement, int valaues); //�������� �������������� �������� ��������� F3

Node* addelem(Node* firstElement, int values); //���������� ������ �������� � ��������� F4

Node* createSetList(int len, int min, int max); //�������� ��������� F5

int Power_SetList(Node* firstElement); //�������� ��������� F6

string toString(Node* firstElement, char sym); //����� ��������� ��������� F7

Node* deleteSetList(Node* firstElement); //�������� ��������� F8

bool isSubset(Node* A, Node* B); //������������ � - � F9

bool equalSet(Node* firstElement_A, Node* firstElement_B); //��������� ���� �������� � - � F10

Node* unitySet(Node* firstElement_A, Node* firstElement_B); //����������� ���� �������� F11

Node* intersectionSet(Node* firstElement_A, Node* firstElement_B); // ����������� ���� �������� F12

Node* differenceSet(Node* firstElement_A, Node* firstElement_B); //�������� �������� 13

Node* symmetrydifferentSet(Node* firstElement_A, Node* firstElement_B); //������������ �������� F14

int random(int min, int max);//��������� �������� ��������� �� 6 �� 9 ���������