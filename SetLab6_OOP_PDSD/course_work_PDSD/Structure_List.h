#pragma once

#include <string>
#include<random>
#include "Node.h"
using namespace std;


Node* createSetList(); //Создание пустого множества F1

bool emptySetList(Node* firstElement); //Пустое множество? F2

bool elemInSetList(Node* firstElement, int valaues); //Проверка принадлежности элемента множеству F3

Node* addelem(Node* firstElement, int values); //Добавление нового элемента в множество F4

Node* createSetList(int len, int min, int max); //Создание множества F5

int Power_SetList(Node* firstElement); //Мощность множества F6

string toString(Node* firstElement, char sym); //Вывод элементов множества F7

Node* deleteSetList(Node* firstElement); //Удаление множества F8

bool isSubset(Node* A, Node* B); //Подмножество А - В F9

bool equalSet(Node* firstElement_A, Node* firstElement_B); //Равенство двух множеств А - В F10

Node* unitySet(Node* firstElement_A, Node* firstElement_B); //Объединение двух множеств F11

Node* intersectionSet(Node* firstElement_A, Node* firstElement_B); // Пересечение двух множеств F12

Node* differenceSet(Node* firstElement_A, Node* firstElement_B); //Разность множеств 13

Node* symmetrydifferentSet(Node* firstElement_A, Node* firstElement_B); //Симметричная разность F14

int random(int min, int max);//рандомный диапазон множества от 6 до 9 элементов