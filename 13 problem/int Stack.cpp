#include "int Stack.h"

//добавл€ет новый элемент в стек
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

//удал€ет последний элемент стека и возвращает его
int Stack::pop() {
	ListElement *current = &stackobj, *prev = NULL;
	while (current->next != NULL) {
		prev = current;
		current = current->next;
	}
	if (prev!=NULL) {//если стек не пуст
		prev->next = NULL; //обрубаем хвост у предпоследнего узла
		int element = current->value; //дл€ очистки пам€ти от динамического объекта
		delete current;
		return element;
	}
	else cout << "EMPTY STACK";
}

//возвращает последний элемент стека
int Stack::back() {
	ListElement *current = &stackobj;
	while (current->next != NULL) {
	current = current->next;
	}
	return current->value;
}
	
//возвращает размер стека
int Stack::size() {
	int size = 0;
	ListElement *current = &stackobj;
	while (current->next != NULL) {
		current = current->next;
		size++;
	}
	return size;
}

//очищает стек
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

//выводит элементы через пробел. если пустой, то выводит EMPTY STACK
void Stack::showList() {
	ListElement *current = &stackobj;
	bool empty = true; //проверка на пустоту
	while (current->next != NULL) {
		current = current->next;
		cout << current->value << ' ';
		empty = false;
	}
	if (empty) cout << "EMPTY STACK";
	cout << endl;
}
