/*������� ������ �������� char. ������ ������ ��� ������ ���������� �
������������� ������� ����� � ���������, � ��������� � �������. ���������
������� �������� ��� ���������.*/
//#include<iostream>
#include<fstream>
using namespace std;
int main(){
	char* s = new char[6]; //���������� ������ �� 6 ���������
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	fin.get(s, 5); //��������� 4 �������, �.�. ����� - ����
	while (*s!=0){
		if(*s>='A'&&*s<='Z') *s=*s-32;
		else if(*s>=97&&*s<=122) *s-=32;
		fout<<*s<<endl;
		s++;
	}
return 0;}
