#include "_String Stack.h"

//��������� ����� ������� � ����
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

//������� ��������� ������� ����� � ���������� ���
_String Stack::pop() {
	ListElement *current = &stackobj, *prev = NULL;
	while (current->next != NULL) {
		prev = current;
		current = current->next;
	}
	if (prev!=NULL) {//���� ���� �� ����
		prev->next = NULL; //�������� ����� � �������������� ����
		_String element = current->value; //��� ������� ������ �� ������������� �������
		delete current;
		return element;
	}
	else cout << "EMPTY STACK";
}

//���������� ��������� ������� �����
_String Stack::back() {
	ListElement *current = &stackobj;
	while (current->next != NULL) {
	current = current->next;
	}
	return current->value;
}
	
//���������� ������ �����
int Stack::size() {
	int size = 0;
	ListElement *current = &stackobj;
	while (current->next != NULL) {
		current = current->next;
		size++;
	}
	return size;
}

//������� ����
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

//������� �������� ����� ������. ���� ������, �� ������� EMPTY STACK
void Stack::showList() {
	ListElement *current = &stackobj;
	bool empty = true; //�������� �� �������
	while (current->next != NULL) {
		current = current->next;
		cout << current->value.getValue() << ' ';
		empty = false;
	}
	if (empty) cout << "EMPTY STACK";
	cout << endl;
}
