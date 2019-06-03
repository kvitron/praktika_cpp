#include "_String Stack.h"

//добавляет новый элемент в стек
void Stack::push(_String n) {
	cout<<"FILE: _String Stack. push(_String n)" << endl;/////////////////////////
	ListElement *current = &stackobj;
	while (current->next != NULL) {
		current = current->next;
	}
	ListElement *newElement = new ListElement;
	current->next = newElement;
	newElement->value = n;
	newElement->prev = current;
	_String a = newElement->value;
}

//удаляет последний элемент стека и возвращает его. Пустой стек напечатает EMPTY STACK
_String Stack::pop() {
	cout << "FILE: _String Stack. pop()" << endl;/////////////////////////////
	ListElement *current = &stackobj, *prev = NULL;
	while (current->next != NULL) {
		prev = current;
		current = current->next;
	}
	if (prev!=NULL) {//если стек не пуст
		prev->next = NULL; //обрубаем хвост у предпоследнего узла
		_String element = current->value; //для очистки памяти от динамического объекта
		delete current;
		return element;
	}
	else cout << "EMPTY STACK";
}

//возвращает последний элемент стека
_String Stack::back() {
	cout << "FILE: _String Stack. back()" << endl;////////////////////////
	ListElement *current = &stackobj;
	while (current->next != NULL) {
	current = current->next;
	}
	return current->value;
}
	
//возвращает размер стека
int Stack::size() {
	cout << "FILE: _String Stack. size()" << endl;////////////////////////
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
	cout << "FILE: _String Stack. clear()" << endl;////////////////////////
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
	cout << "Stack was cleared" << endl;/////////////////////
}

//выводит элементы через пробел. если пустой, то выводит EMPTY STACK
void Stack::showList() {
	cout << "FILE: _String Stack. showlist()" << endl;////////////////////////
	ListElement *current = &stackobj;
	bool empty = true; //проверка на пустоту
	while (current->next != NULL) {
		current = current->next;
		cout << current->value.getValue() << ' ';
		empty = false;
	}
	if (empty) cout << "EMPTY STACK" << endl;
}
