#include <iostream>
#include "_String.h"
#include "_String Stack.h" //���� �����
using namespace  std;

int main() {
	//Stack a;
	_String *s = new _String("qwerty");
	a.push(s);
	cout << "1 " << s.getValue() << endl;
	s = a.back();
	delete s;
	cout<<"3 " << s.getValue()<<'!'<<endl;
	//cout<<a.pop().getValue()<<'!'<<endl;
	
	_String a("123"), b;
	b = a;
	cout << "b value " << b.getValue() << endl;
	
	return 0;
}
/*
4*5+7*5-(75-5)*3+4
������ �������� �� ������������ ����������� ������ � ������� �����
���� ���� ������, �� ���� ������ ������������� � ������ ��������� ������. ��������� ����� �� ����� ������
*/
