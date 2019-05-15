//Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include "_String.h"
#include "int Stack.h"
#include <iostream>
using namespace std;

int main()
{
	_String s;
	s.setValue("456.78");
	cout << s.getValue() << endl;
	
	Stack a;
	a.push(4);
	a.push(6);
	cout<<a.pop()+a.pop();
	//system("pause");
	return 0;
}
