//#include "pch.h"
#include <iostream>
using namespace std;
class ListElement {
public:
	int value = 0;
	ListElement *next = NULL;
	ListElement *prev = NULL; //для метода clear
};

class Stack{
public:
	void push(ListElement &parent, int n) {
		ListElement *current = &parent;
		while (current->next != NULL) {
			current = current->next;
		}
		ListElement *newElement = new ListElement;
		current->next = newElement;
		newElement->value = n;
		newElement->prev = current;
		cout << "OK" << endl;
	}

	int pop(ListElement &parent) {
		/*root - объект, из которого удаляем последний узел
		пролистываем узлы до последнего, у предпоследнего
		обрубаем хвост, выводим значение последнего*/
		ListElement *current = &parent, *prev = NULL;
		while (current->next != NULL) {
			prev = current;
			current = current->next;
		}
		prev->next = NULL; //обрубаем хвост у предпоследнего узла
		int element = current->value; //для очистки памяти от динамического объекта
		delete current;
		return element;
	}

	int back(ListElement &parent) {
		ListElement *current = &parent;
		while (current->next != NULL) {
		current = current->next;
		}
		return current->value;
	}
	
	int size(ListElement &parent) {
		int size = 0;
		ListElement *current = &parent;
		while (current->next != NULL) {
			current = current->next;
			size++;
		}
		return size;
	}

	void clear(ListElement &parent) {
		ListElement *current = &parent, *prev = NULL;
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
		cout << "OK" << endl;
	}

	void showList(ListElement &parent) {
		ListElement *current = &parent;
		while (current->next != NULL) {
			cout << current->value << ' ';
			current = current->next;
		}
		cout << current->value << endl;
	}
};	

int main() {
	ListElement stek;
	push(stek, 5);
	push(stek, 4);
	push(stek, 3);
	push(stek, 2);
	clear(stek);
	showList(stek);

	cout << size(stek) << endl;
	return 0;
}
