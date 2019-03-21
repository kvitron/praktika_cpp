/*реализация динамически расширяемого стека с помощью ООП*/
//#include "pch.h"
#include <iostream>
using namespace std;
class ListElement {
public:
	int value;
	ListElement *next = NULL;
	ListElement *prev = NULL; //для метода clear
};

class Stack{
private:
	ListElement stackobj;
public:
	void push(int n) {
		//добавляет новый элемент
		ListElement *current = &stackobj;
		while (current->next != NULL) {
			current = current->next;
		}
		ListElement *newElement = new ListElement;
		current->next = newElement;
		newElement->value = n;
		newElement->prev = current;
		cout << "OK" << endl;
	}

	int pop() {
		//удаляет последний элемент стека и возвращает его
		ListElement *current = &stackobj, *prev = NULL;
		while (current->next != NULL) {
			prev = current;
			current = current->next;
		}
		if (prev!=NULL) {//если стек не пуст
			prev->next = NULL; //обрубаем хвост у предпоследнего узла
			int element = current->value; //для очистки памяти от динамического объекта
			delete current;
			return element;
		}
		else cout << "EMPTY STACK";
	}

	int back() {
		//возвращает последний элемент стека
		ListElement *current = &stackobj;
		while (current->next != NULL) {
		current = current->next;
		}
		return current->value;
	}
	
	int size() {
		//возвращает размер стека
		int size = 0;
		ListElement *current = &stackobj;
		while (current->next != NULL) {
			current = current->next;
			size++;
		}
		return size;
	}

	void clear() {
		//очищает стек
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
		cout << "OK" << endl;
	}

	void showList() {
		//выводит элементы через пробел. если пустой, то выводит EMPTY
		ListElement *current = &stackobj;
		bool empty = true; //проверка на пустоту
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
	Stack a;
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.showList();
	cout << a.pop() << endl;
	cout << a.back() << endl;
	a.showList();
	cout << a.size() << endl;
	a.clear();
	cout << a.pop() << endl;
	a.showList();
	return 0;
}
