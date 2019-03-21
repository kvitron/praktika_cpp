/*�������������� ��������� ����� ����������� � �������� �������� ������,
��� ����� �������� ������� �� ����������, � �� �������� ����� ����, ��� � ������� ������ ���������.
�������� �������� ������ �� ������� ������. ��������, ��������� 1+2 ������������� ������ 1 2 +,
� ��������� 1+2*3 ������������� ������ 1 2 3 * +, ������ (2+3)*(3-1) ������������ ��� 2 3 + 3 1 - *.
����e��� ������ � ��������� � �������� ������� ������ (����� � ����� +, -, * ��������� ���������).
��������� ����, ��������� �������� ���������.*/
#include "pch.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class ListElement {
public:
	int value;
	ListElement *next = NULL;
	ListElement *prev = NULL; //��� ������ clear
};

class Stack {
private:
	ListElement stackobj;
public:
	void push(int n) {
		//��������� ����� �������
		ListElement *current = &stackobj;
		while (current->next != NULL) {
			current = current->next;
		}
		ListElement *newElement = new ListElement;
		current->next = newElement;
		newElement->value = n;
		newElement->prev = current;
		//cout << "OK" << endl;
	}

	int pop() {
		//������� ��������� ������� ����� � ���������� ���
		ListElement *current = &stackobj, *prev = NULL;
		while (current->next != NULL) {
			prev = current;
			current = current->next;
		}
		if (prev != NULL) {//���� ���� �� ����
			prev->next = NULL; //�������� ����� � �������������� ����
			int element = current->value; //��� ������� ������ �� ������������� �������
			delete current;
			return element;
		}
		else cout << "EMPTY STACK";
	}

	int back() {
		//���������� ��������� ������� �����
		ListElement *current = &stackobj;
		while (current->next != NULL) {
			current = current->next;
		}
		return current->value;
	}

	int size() {
		//���������� ������ �����
		int size = 0;
		ListElement *current = &stackobj;
		while (current->next != NULL) {
			current = current->next;
			size++;
		}
		return size;
	}

	void clear() {
		//������� ����
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
		//cout << "OK" << endl;
	}

	void showList() {
		//������� �������� ����� ������. ���� ������, �� ������� EMPTY
		ListElement *current = &stackobj;
		bool empty = true; //�������� �� �������
		while (current->next != NULL) {
			current = current->next;
			cout << current->value << ' ';
			empty = false;
		}
		if (empty) cout << "EMPTY";
		cout << endl;
	}
};

int main() {
	Stack stack;
	char input[20];
	while (cin >> input) {
		if (input[0] >= '0' && input[0] <= '9') {//���� input ��� �����
			stack.push(atoi(input));
		}
		else {
			int last = stack.pop();
			int secondlast = stack.pop();
			if (input[0] == '+') {//���� ��������
				stack.push(last + secondlast);
			}
			if (input[0] == '-') {//���� ��������
				stack.push(secondlast - last);
			}
			if (input[0] == '*') {//���� ��������
				stack.push(last * secondlast);
			}
		}
		stack.showList(); //����� �����
	}
	return 0;
}
