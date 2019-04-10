/*����������� ����� _String, ��������������� ���������� ������ �� ��������.*/
//#include "pch.h"
#include <iostream>
#include <cstdlib>
using namespace std;
class _String {
public: ///////////////////////////////// ���������� � private
	char *value;
	int stringLength = -1;
public:
	_String() {//����������� �� ���������
		value = new char[1];
		stringLength = 0;
	}
	_String(char *val) { //�� ������� char
		int i = 0;
		while (val[i]!=0){ //������� �����
			i++;
		}
		char *str = new char[i + 1];
		i = 0;
		while (val[i] != 0) {
			str[i] = val[i];
			i++;
		}
		str[i] = 0;
		value = str;
		stringLength = i;
	}
	_String(const char *val) { //�� ����������� ������
		int i = 0;
		while (val[i]!=0){ //������� �����
			i++;
		}
		char *str = new char[i + 1];
		i = 0;
		while (val[i] != 0) {
			str[i] = val[i];
			i++;
		}
		str[i] = 0;
		value = str;
		stringLength = i;
	}
	~_String() { //����������
		delete[] value;
	}
	_String(const _String &element) { //�� ������� ������� _Srting
		int i = 0;
		while (element.value[i] != 0) { //������� �����
			i++;
		}
		char *str = new char[i + 1];
		i = 0;
		while (element.value[i] != 0) {
			str[i] = element.value[i];
			i++;
		}
		str[i] = 0;
		value = str;
		stringLength = i;
	}
	int length() { //���������� ����� ������
		return stringLength;
	}
	void append(_String str) { //��������� ������ _String
		int i = 0;
		while (str.value[i] != 0){ //������� �����
			i++;
		}
		char *tempstr = new char[stringLength + i + 1];
		i = 0;
		while (value[i] != 0) { //�������� ������ ������
			tempstr[i] = value[i];
			i++;
		}
		delete[] value;
		i = 0;
		while (str.value[i] != 0) { //�������� ����� ������
			tempstr[stringLength + i] = str.value[i];
			i++;
		}
		value[stringLength + i] = 0;
		stringLength += i;
		value = tempstr;
	}
	void append(char *str) { //��������� ������ char
		int i = 0;
		while (str[i] != 0){ //������� �����
			i++;
		}
		char *tempstr = new char[stringLength + i + 1];
		i = 0;
		while (value[i] != 0) { //�������� ������ ������
			tempstr[i] = value[i];
			i++;
		}
		delete[] value;
		i = 0;
		while (str[i] != 0) { //�������� ����� ������
			tempstr[stringLength + i] = str[i];
			i++;
		}
		tempstr[stringLength + i] = 0;
		stringLength += i;
		value = tempstr;
	}
	void append(const char *str) { //��������� ����������� ������
		int i = 0;
		while (str[i] != 0){ //������� �����
			i++;
		}
		char *tempstr = new char[stringLength + i + 1];
		i = 0;
		while (value[i] != 0) { //�������� ������ ������
			tempstr[i] = value[i];
			i++;
		}
		delete[] value;
		i = 0;
		while (str[i] != 0) { //�������� ����� ������
			tempstr[stringLength + i] = str[i];
			i++;
		}
		tempstr[stringLength + i] = 0;
		stringLength += i;
		value = tempstr;
	}
	void setValue(char *val) { //���������� �������� ������� char
		int i = 0;
		while (val[i]!=0){ //������� �����
			i++;
		}
		char *tempstr = new char[i + 1];
		i = 0;
		while (val[i] != 0) { //���������
			tempstr[i] = val[i];
			i++;
		}
		tempstr[i] = 0;
		delete[] value;
		value = tempstr;
		stringLength = i;
	}
	void setValue(const char *val) { //���������� ����������� ��������
		int i = 0;
		while (val[i]!=0){ //������� �����
			i++;
		}
		char *tempstr = new char[i + 1];
		i = 0;
		while (val[i] != 0) { //���������
			tempstr[i] = val[i];
			i++;
		}
		tempstr[i] = 0;
		delete[] value;
		value = tempstr;
		stringLength = i;
	}
	void setValue(int val) { //���������� �������� �������������������� �� int
		if (val == 0) { //���� 0
			delete[] value;
			value = new char[2];
			value[0] = '0';
			value[1] = 0;
			stringLength = 1;
		}
		else { //���� �� 0
			int len = 0;
			char* tempstr = new char[100];
			while (val != 0) { //���������� ����� � ������ � ������������ ����
				tempstr[len] = char(val % 10 + 48); //���������� ������ �����
				val = val / 10;
				len++;
			}
			for (int i = 0, j = len - 1; i < len / 2; i++, j--) { //������
				swap(tempstr[i], tempstr[j]);
			}
			tempstr[len] = 0;
			delete[] value;
			value = new char[len + 1]; //����� ������ value
			int i = 0;
			while (tempstr[i] != 0) { //�������� � value ������� �� ��������� ������
				value[i] = tempstr[i];
				i++;
			}
			value[i] = 0;
			stringLength = i;
			delete[] tempstr;
		}
	}
	void setValue(double val, int precision = 10) { //���������� �������� �������������������� �� double c ��������� 10 ������ ����� ������� �� ���������///////////////
	}
	_String operator = (const _String &element) {
	}
	_String operator + (const _String &right) {
	}
	int pos(const char *str) { //������ ��������� ���������///////////////////////////////////////
	}
	void remove(int position, int length) { //�������� ��������� �� ������////////////////////////////////////
	}
	void insert(int position, int length, const char *source) {
	}
	void insert(int position, int length, char *source) {
	}
	void insert(int position, int length, _String source) {
	}
	_String copy(int position, int length) { //���������� ����������� ���������
		char *str = new char[length + 1];
		int i, j; //������� � �������� � ����� ������
		for (i = position, j = 0; j < length; i++, j++){ //��������
			str[j] = value[i];
		}
		str[j] = 0;
		_String newstring; // ������� ������������ ���������
		newstring.stringLength = j;
		newstring.value = str;
		return newstring;
	}
	char operator [] (int index) {
	}
	int parseInt(int &error) { //����������� � int ////////////////////////////////////////�� ������� �������� �-���
		return atoi(value);
	}
	float parseFloat(int &error) { //����������� �� float//////////////////////////////////�� ������� �������� �-���
		return atof(value);
	}
	bool isEqual(char *str) { //��������� �� ������� �� ������������
		int i = 0;
		bool f = true;
		while (value[i] != 0) {
			if (value[i] != str[i]){
				return false;
			}
			i++;
		}
		if (str[i] != 0){ // ���� � str ������ ���������, ��� � value
			return false;
		}
		return true;
	}
	bool isEqual(const char *str) { //��������� � ���������� ������� �� ������������
		int i = 0;
		bool f = true;
		while (value[i] != 0) {
			if (value[i] != str[i]){
				return false;
			}
			i++;
		}
		if (str[i] != 0){ // ���� � str ������ ���������, ��� � value
			return false;
		}
		return true;
	}
};
int main() {
	_String s6("1663");
	_String s7 = s6.copy(0,3);
	cout << s7.value <<endl;
	return 0;
}
