//#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
class ListElement {
public:
	int value = 0;
	ListElement *next = NULL;
};

void set100 (ListElement &a) {
	//��������� ����� ������ �������.
	//������������� ��� �������� =100
	a.value = 100;
}

void push(ListElement &parent, ListElement &newElement) {
	/*��������� ������ ��������
	current - ��������� �� ������� ������
	���������� current �� next ������ ���, ���� next!=NULL
	������������� next ���������� ������� �� ����� ������*/
	ListElement *current = &parent;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = &newElement;
}

void pop(ListElement &root) {
	/*root - ������, �� �������� ������� ��������� ����
	����������� ���� �� ����������, � �������������� 
	�������� �����, ������� �������� ����������*/
	ListElement *current = &root, *prev = NULL;
	while (current->next != NULL) {
		prev = current;
		current = current->next;
	}
	prev->next = NULL; //�������� ����� � �������������� ����
	cout << current->value << endl;
}

void showList(ListElement &parent) {
	ListElement *current = &parent;
	while (current->next != NULL) {
		cout << current->value << ' ';
		current = current->next;
	}
	cout << current->value << endl;
}

int main() {
	ListElement a, b, c, d;
	a.value = 1;
	b.value = 2;
	c.value = 3;
	d.value = 4;
	showList(a);
	push(a, b);
	showList(a);
	push(a, c);
	showList(a);
	push(a, d);
	showList(a);
	pop(a);
	showList(a);
}
