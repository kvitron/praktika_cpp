#ifndef int_STACK_H
#include <iostream> //� ������ ����� ����� ��� ������ NULL
using namespace std;

class ListElement {
public:
	int value;
	ListElement *next = NULL;
	ListElement *prev = NULL; //��� ������ clear
};

class Stack{
private:
	ListElement stackobj;
public:
	//��������� ����� ������� � ����
	void push(int n);

	//������� ��������� ������� ����� � ���������� ���
	int pop();

	//���������� ��������� ������� �����
	int back();
	
	//���������� ������ �����
	int size();
	
	//������� ����
	void clear();

	//������� �������� ����� ������. ���� ������, �� ������� EMPTY
	void showList();
};

#endif
