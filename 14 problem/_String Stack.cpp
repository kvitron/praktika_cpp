#include "_String Stack.h"

//добавл€ет новый элемент в стек
void Stack::push(_String n) {
	cout<<"2 " << n.getValue()<<" constructor " << endl;
	ListElement *current = &stackobj;
	while (current->next != NULL) {
		current = current->next;
	}
	ListElement *newElement = new ListElement;
	current->next = newElement;
	
	cout<<"2.1 " << newElement->value.getValue()<< endl;
	
	newElement->value = n;
	
	cout<<"2.1 " << newElement->value.getValue()<< endl;
	
	newElement->prev = current;
	_String a = newElement->value;
	cout<<"2 " << a.getValue()<<"dobavleno" << endl;
}

//удал€ет последний элемент стека и возвращает его
_String Stack::pop() {
	ListElement *current = &stackobj, *prev = NULL;
	while (current->next != NULL) {
		prev = current;
		current = current->next;
	}
	if (prev!=NULL) {//если стек не пуст
		prev->next = NULL; //обрубаем хвост у предпоследнего узла
		_String element = current->value; //дл€ очистки пам€ти от динамического объекта
		delete current;
		return element;
	}
	else cout << "EMPTY STACK";
}

//возвращает последний элемент стека
_String Stack::back() {
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
	cout << "Stack was cleared" << endl;
}

//выводит элементы через пробел. если пустой, то выводит EMPTY STACK
void Stack::showList() {
	ListElement *current = &stackobj;
	bool empty = true; //проверка на пустоту
	while (current->next != NULL) {
		current = current->next;
		cout << current->value.getValue() << ' ';
		empty = false;
	}
	if (empty) cout << "EMPTY STACK";
	cout << endl;
}
