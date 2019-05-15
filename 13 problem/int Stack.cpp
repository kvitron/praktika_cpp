#include "int Stack.h"

//��������� ����� ������� � ����
void Stack::push(int n) {
	ListElement *current = &stackobj;
	while (current->next != NULL) {
		current = current->next;
	}
	ListElement *newElement = new ListElement;
	current->next = newElement;
	newElement->value = n;
	newElement->prev = current;
}

//������� ��������� ������� ����� � ���������� ���
int Stack::pop() {
	ListElement *current = &stackobj, *prev = NULL;
	while (current->next != NULL) {
		prev = current;
		current = current->next;
	}
	if (prev!=NULL) {//���� ���� �� ����
		prev->next = NULL; //�������� ����� � �������������� ����
		int element = current->value; //��� ������� ������ �� ������������� �������
		delete current;
		return element;
	}
	else cout << "EMPTY STACK";
}

//���������� ��������� ������� �����
int Stack::back() {
	ListElement *current = &stackobj;
	while (current->next != NULL) {
	current = current->next;
	}
	return current->value;
}
	
//���������� ������ �����
int Stack::size() {
	int size = 0;
	ListElement *current = &stackobj;
	while (current->next != NULL) {
		current = current->next;
		size++;
	}
	return size;
}

//������� ����
void Stack::clear() {
	ListElement *current = &stackobj, *prev = NULL;
	while (current->next != NULL) {
		prev = current;
		current = current->next;
	}
	while (prev != NULL) {
		delete current;
		current = prev;
		current->next = NULL;
		prev = current->prev;
	}
	cout << "Stack was clear" << endl;
}

//������� �������� ����� ������. ���� ������, �� ������� EMPTY STACK
void Stack::showList() {
	ListElement *current = &stackobj;
	bool empty = true; //�������� �� �������
	while (current->next != NULL) {
		current = current->next;
		cout << current->value << ' ';
		empty = false;
	}
	if (empty) cout << "EMPTY STACK";
	cout << endl;
}
