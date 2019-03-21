/*Арифметическое выражение можно представить в обратной польской записи,
где знаки операции следуют за операндами, а не ставятся между ними, как в обычной записи выражений.
Обратная польская запись не требует скобок. Например, выражению 1+2 соответствует запись 1 2 +,
а выражению 1+2*3 соответствует запись 1 2 3 * +, запись (2+3)*(3-1) записывается как 2 3 + 3 1 - *.
Задаeтся строка – выражение в обратной полькой записи (числа и знаки +, -, * разделены пробелами).
Используя стек, вычислите значение выражения.*/
#include "pch.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class ListElement {
public:
	int value;
	ListElement *next = NULL;
	ListElement *prev = NULL; //для метода clear
};

class Stack {
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
		//cout << "OK" << endl;
	}

	int pop() {
		//удаляет последний элемент стека и возвращает его
		ListElement *current = &stackobj, *prev = NULL;
		while (current->next != NULL) {
			prev = current;
			current = current->next;
		}
		if (prev != NULL) {//если стек не пуст
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
		//cout << "OK" << endl;
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
	Stack stack;
	char input[20];
	while (cin >> input) {
		if (input[0] >= '0' && input[0] <= '9') {//если input это число
			stack.push(atoi(input));
		}
		else {
			int last = stack.pop();
			int secondlast = stack.pop();
			if (input[0] == '+') {//если сложение
				stack.push(last + secondlast);
			}
			if (input[0] == '-') {//если сложение
				stack.push(secondlast - last);
			}
			if (input[0] == '*') {//если сложение
				stack.push(last * secondlast);
			}
		}
		stack.showList(); //вывод стека
	}
	return 0;
}
