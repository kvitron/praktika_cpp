/*�������������� ��������� ����� ����������� � �������� �������� ������,
��� ����� �������� ������� �� ����������, � �� �������� ����� ����, ��� � ������� ������ ���������.
�������� �������� ������ �� ������� ������. ��������, ��������� 1+2 ������������� ������ 1 2 +,
� ��������� 1+2*3 ������������� ������ 1 2 3 * +, ������ (2+3)*(3-1) ������������ ��� 2 3 + 3 1 - *.
����?��� ������ � ��������� � �������� ������� ������ (����� � ����� +, -, * ��������� ���������).
��������� ����, ��������� �������� ���������.*/
//#include "pch.h"
#include <iostream>
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

int find(char *source, const char *search) {
	//������� ������ ��������� ������� � ������
	int count = 0; //�� ������� �������� ��������
	while (*source != 0) {
		if (*source == *search) {
			source -= count;
			return count;
		}
		else {
			count++;
			source++;
		}
	}
	source -= count;
	return -1;
}
char *copy(char *source, int index, int count) {
	//���������� ��������� �� ���������. ���������� ������� ����� ������������ ������ � �������� ���������
	char* s1 = new char[count + 1];
	source += index;
	for (int i = 0; i < count; ++i) {
		*s1 = *source;
		s1++;
		source++;
	}
	*s1 = 0;
	s1 -= count;
	source -= (count + index);
	return s1;
}
char *del(char *source, int index, int count) {
	//���������� ������ � ���������� count ����������
	int length = 0;
	for (length = 0; *(source + length) != 0; length++) continue; //������� ����� �������� ������
	char* s1 = new char[length - count + 1]; //������� ����� ������
	for (int i = 0; i < index; ++i) { //�������� �������� �� index
		*(s1 + i) = *(source + i);
	}
	int p = index + count;
	for (int i = 0; i < length - index - count; i++) {//�������� �������� ����� index
		*(s1 + index + i) = *(source + p + i);
	}
	*(s1 + length - count) = 0;
	delete[] source;
	return s1;
}
void reversepolish(Stack &stack, char *input){
	/*��������� �������� �������� �������� ��� ������*/
	int last = stack.pop();
	int secondlast = stack.pop();
	if (input[0] == '+') {//���� ��������
		stack.push(last + secondlast);
	}
	if (input[0] == '-') {//���� ���������
		stack.push(secondlast - last);
	}
	if (input[0] == '*') {//���� ���������
		stack.push(last * secondlast);
	}
}
int main() {
	Stack stack;
	char *input = new char[1000];
	cin.get(input, 999);
	int numgap = find(input, " "); //����� ������� �������
	while (numgap != -1) { // ���� � ������ ���� �������
		if (input[0] >= '0' && input[0] <= '9') {//���� �� ������ ����� �����
			char *s1 = copy(input, 0, numgap);
			stack.push(atoi(s1));
			delete[] s1;
		}
		else { //���� �� ������ ����� ���� ��������
			reversepolish(stack, input);
		}
		input = del(input, 0, numgap + 1); //������� ����� ��� ������ ������ � ��������
		numgap = find(input, " "); //����� ������ ������� �������
		stack.showList(); //����� ������� ��������. ���������������� ��� ������������
	}
	//�� �� ����� ��� ��������� ��������
	reversepolish(stack, input);
	stack.showList(); //���������
	return 0;
}
