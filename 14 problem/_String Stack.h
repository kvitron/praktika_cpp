#ifndef _STRING_STACK_H
#include "_String.h"
#include <iostream> //� ������ ����� ����� ��� ������ NULL
using namespace std;

class ListElement {
public:
	_String value;
	ListElement *next = NULL;
	ListElement *prev = NULL; //��� ������ clear
};

class Stack{
private:
	ListElement stackobj;
public:
	//��������� ����� ������� � ����
	void push(_String n);

	//������� ��������� ������� ����� � ���������� ���
	_String pop();

	//���������� ��������� ������� �����
	_String back();
	
	//���������� ������ �����
	int size();
	
	//������� ����
	void clear();

	//������� �������� ����� ������. ���� ������, �� ������� EMPTY
	void showList();
};

#endif
