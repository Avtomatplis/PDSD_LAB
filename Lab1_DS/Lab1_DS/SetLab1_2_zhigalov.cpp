#include "SetLab1_2_Zhigalov.h"
#include <iostream>
#include <random>
#include <string>
using namespace std;

random_device rd;
mt19937 gen(rd());

using namespace std;


Node* createSetList() //������ ������ ��������� (F1)
{
	return nullptr;
}


bool emptySetList(Node* firstElement) //������ �� ���������? (F2)
{
	return firstElement == nullptr;
}

bool elemInSetList(Node* firstElement, int values) //�������������� �������� ��������� (F3)
{
	if (!emptySetList(firstElement)) 
	{
		for (Node* elem= firstElement; elem != nullptr; elem = elem->next) 
		{
			if (elem->value == values) //���� ������� ���� � ���������, �� ������
			{
				return true;
			}
		}
	}
	return false;
}

Node* addelem(Node* firstElement, int values) //���������� ������ �������� � ��������� (F4)
{
	if (elemInSetList(firstElement, values))
	{
		return firstElement;
	} 
	else 
	{
		Node* node = new Node();
		node->next = firstElement;
		node->value = values;
		return node;
	}
}

int random(int min, int max)//��������� ��������� ��������
{
	uniform_int_distribution<> dist(min, max);
	return dist(gen);
}
/*
   ������� 7: ��������� � - ��������� �����, ������� 7. ��������� B - ��������� �������� �����.
*/
Node* createSetList(int len, int min, int max,char setType) //������ ��������� (F5)
{
	Node* set = createSetList();

	if (min > max || len <= 0 || max - min < len)
	{
		return set;
	}
    Node* set1 = set;
	while (len > 0)
	{
		int elem = random(min, max);
		if (setType == 'A')
		{
			if (elem % 7 == 0) // ��������� ������ �������� ������� 7
			{
				set = addelem(set, elem);
				if (set != set1)
				{
					len--;
					set1 = set;
				}
			}
		}
		else if (setType == 'B') 
		{
			if (elem % 2 == 1) // ��������� ������ �������� ��������
			{
				set = addelem(set, elem);
				if (set != set1)
				{
					len--;
					set1 = set;
				}
			}
		}
		
	}

		return set;
}

int Power_SetList(Node* firstElement) //���������� �������� ��������� (F6)
{
	if (emptySetList(firstElement)) 
	{
		return 0;
	} 
	else 
	{
		int len = 0;
		for (Node* elem = firstElement; elem != nullptr; elem = elem->next) 
		{
			len++;
		}
		return len;
	}
}

string toString(Node* firstElement, char sym)//����� �������� � ���� ������ (F7)
{
	if (!emptySetList(firstElement)) 
	{
		string result = "";

		for (Node* elem = firstElement; elem != nullptr; elem = elem->next)
		{
			result += to_string(elem->value);//����������� �������� � ������
			result += sym;//�����������
		}
		int len = result.length();
		return result.erase(len-1, len); //������� ��������� �����������
	}
	return "";
}

Node* deleteSetList(Node* firstElement)//�������� ��������� (F8)
{
	while (firstElement!= nullptr) 
	{
		Node* next = firstElement->next;
		delete firstElement; 
		firstElement = next;
	}
	return firstElement;
}

//F9
bool isSubset(Node* A, Node* B)//�������� �� � ������������� B
{
	if (emptySetList(A))
	{
		return true;
	}
	for (Node* elem_A = A; elem_A != nullptr; elem_A=elem_A->next)
			if (!elemInSetList(B,elem_A->value ))
			{
				return false;
			}
	return true;
}

//F10
bool equalSet(Node* firstElement_A, Node* firstElement_B)//��������� ���� �������� �-�
{
	return isSubset(firstElement_B, firstElement_A)&& isSubset(firstElement_A, firstElement_B);

}

//F11
Node* unitySet(Node* firstElement_A, Node* firstElement_B)//����������� ���� ��������
{
	Node* set_C = createSetList();
	for (Node* elem_A = firstElement_A; elem_A != nullptr; elem_A = elem_A->next)
	{
		set_C = addelem(set_C, firstElement_A->value);
		firstElement_A = firstElement_A->next;
	}
	for (Node* elem_B = firstElement_B; elem_B != nullptr; elem_B = elem_B->next)
	{
		set_C = addelem(set_C, firstElement_B->value);
		firstElement_B = firstElement_B->next;
	}
	return set_C;
	
}

//F12
Node* intersectionSet(Node* firstElement_A, Node* firstElement_B)//����������� ���� ��������
{
	Node* set_C = createSetList();
	for (Node* elem_A = firstElement_A; elem_A != nullptr; elem_A = elem_A->next)
		if (elemInSetList(firstElement_B, elem_A->value))
		{
			set_C = addelem(set_C, elem_A->value);
		}
	return set_C;
}

//F13
Node* differenceSet(Node* firstElement_A, Node* firstElement_B)//�������� ���� ��������(���� � � �� ��� � �)
{
	Node* set_C = createSetList();
	for(Node* elem_A=firstElement_A;elem_A!=nullptr;elem_A=elem_A->next)
		if (!elemInSetList(firstElement_B, elem_A->value))
		{
			set_C = addelem(set_C, elem_A->value);
		}
	return set_C;
}

//F14
Node* symmetrydifferentSet(Node* firstElement_A, Node* firstElement_B)//������������ �������� ���� ��������
                                                                      //�������� ������ �� 1 � ������ �� 2 ���������
	                                                                  // �.�.2 ��������� ��� ����������
{
	Node* unitySets = unitySet(firstElement_A, firstElement_B);//���������
	Node* intersectionSets = intersectionSet(firstElement_A, firstElement_B);//���� ����������(�����������)
	return differenceSet(unitySets, intersectionSets);//�������� ��������
}