#ifndef _STRING_STACK_H
#include "_String.h"
#include <iostream> //в данном файле нужен для работы NULL
using namespace std;

class ListElement {
public:
	_String value;
	ListElement *next = NULL;
	ListElement *prev = NULL; //для метода clear
};

class Stack{
private:
	ListElement stackobj;
public:
	//добавляет новый элемент в стек
	void push(_String n);

	//удаляет последний элемент стека и возвращает его
	_String pop();

	//возвращает последний элемент стека
	_String back();
	
	//возвращает размер стека
	int size();
	
	//очищает стек
	void clear();

	//выводит элементы через пробел. если пустой, то выводит EMPTY
	void showList();
};

#endif
