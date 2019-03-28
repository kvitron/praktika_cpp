/*Дана последовательность скобок вида (, ), [, ], {, }. Правильными скобочными последовательностями называются пустая последовательность, а также
(P), [P], {P}, где P – это некоторая правильная последовательность. Например, {}()[] и {[][()()]}() – правильные скобочные последовательности, а
(], [{{}, ({}} – неправильные. Определите является ли заданная строка правильным скобочным выражением.*/

//#include "pch.h"
#include <iostream>
#include <cstdlib>
using namespace std;
class ListElement {
public:
	char value;
	ListElement *next = NULL;
	ListElement *prev = NULL; //для метода clear
};

class Stack {
private:
	ListElement stackobj;
public:
	void push(char n) {
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

	char pop() {
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
		else cout << "POP ERROR: EMPTY STACK";
	}

	char back() {
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
		//выводит элементы через пробел. если пустой, то выводит ошибку
		ListElement *current = &stackobj;
		bool empty = true; //проверка на пустоту
		while (current->next != NULL) {
			current = current->next;
			cout << current->value << ' ';
			empty = false;
		}
		if (empty) cout << "SHOWLIST ERROR: EMPTY STACK";
		cout << endl;
	}
	
	bool empty(){
		/*проверяет стек на пустоту*/
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
	int i = 0; //номер элемента строки
	bool result = true;
	while (*(input+i) != 0){ //проходим по всем элементам введеной строки
		if (*(input+i) == '('){ //встретилась (
			stack.push(*(input+i));
		}
		else if (*(input+i) == '['){ //встретилась [
			stack.push(*(input+i));
		}
		else if (*(input+i) == '{'){ //встретилась {
			stack.push(*(input+i));
		}
		else if (*(input+i) == ')'){ //встретилась )
			if (stack.back() == '('){
				stack.pop();
			}
			else {
				result = false;
				break;
			}
		}
		else if (*(input+i) == ']'){ //встретилась ]
			if (stack.back() == '['){
				stack.pop();
			}
			else {
				result = false;
				break;
			}
		}
		else if (*(input+i) == '}'){ //встретилась }
			if (stack.back() == '{'){
				stack.pop();
			}
			else {
				result = false;
				break;
			}
		}
		i++; //переход на новый шаг
	}
	if (result && stack.empty()){
		cout << "TRUE";
	}
	else {
		cout << "FALSE";
	}
	return 0;
}
