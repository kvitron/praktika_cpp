#ifndef int_STACK_H
#include <iostream> //в данном файле нужен для работы NULL
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
	//добавляет новый элемент в стек
	void push(int n);

	//удаляет последний элемент стека и возвращает его
	int pop();

	//возвращает последний элемент стека
	int back();
	
	//возвращает размер стека
	int size();
	
	//очищает стек
	void clear();

	//выводит элементы через пробел. если пустой, то выводит EMPTY
	void showList();
};

#endif
