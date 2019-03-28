/*���� ������������������ ������ ���� (, ), [, ], {, }. ����������� ���������� �������������������� ���������� ������ ������������������, � �����
(P), [P], {P}, ��� P � ��� ��������� ���������� ������������������. ��������, {}()[] � {[][()()]}() � ���������� ��������� ������������������, �
(], [{{}, ({}} � ������������. ���������� �������� �� �������� ������ ���������� ��������� ����������.*/

//#include "pch.h"
#include <iostream>
#include <cstdlib>
using namespace std;
class ListElement {
public:
	char value;
	ListElement *next = NULL;
	ListElement *prev = NULL; //��� ������ clear
};

class Stack {
private:
	ListElement stackobj;
public:
	void push(char n) {
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

	char pop() {
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
		else cout << "POP ERROR: EMPTY STACK";
	}

	char back() {
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
		//������� �������� ����� ������. ���� ������, �� ������� ������
		ListElement *current = &stackobj;
		bool empty = true; //�������� �� �������
		while (current->next != NULL) {
			current = current->next;
			cout << current->value << ' ';
			empty = false;
		}
		if (empty) cout << "SHOWLIST ERROR: EMPTY STACK";
		cout << endl;
	}
	
	bool empty(){
		/*��������� ���� �� �������*/
		if (stackobj.next == NULL){
			return true;
		}
		else {
			return false;
		}
	}
};
int main() {
	Stack stack;
	char *input = new char[1000];
	cin.get(input, 999);
	int i = 0; //����� �������� ������
	bool result = true;
	while (*(input+i) != 0){ //�������� �� ���� ��������� �������� ������
		if (*(input+i) == '('){ //����������� (
			stack.push(*(input+i));
		}
		else if (*(input+i) == '['){ //����������� [
			stack.push(*(input+i));
		}
		else if (*(input+i) == '{'){ //����������� {
			stack.push(*(input+i));
		}
		else if (*(input+i) == ')'){ //����������� )
			if (stack.back() == '('){
				stack.pop();
			}
			else {
				result = false;
				break;
			}
		}
		else if (*(input+i) == ']'){ //����������� ]
			if (stack.back() == '['){
				stack.pop();
			}
			else {
				result = false;
				break;
			}
		}
		else if (*(input+i) == '}'){ //����������� }
			if (stack.back() == '{'){
				stack.pop();
			}
			else {
				result = false;
				break;
			}
		}
		i++; //������� �� ����� ���
	}
	if (result && stack.empty()){
		cout << "TRUE";
	}
	else {
		cout << "FALSE";
	}
	return 0;
}
