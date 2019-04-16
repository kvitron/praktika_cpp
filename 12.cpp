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
		while (val[i] != 0) { //������� �����
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
		while (val[i] != 0) { //������� �����
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
		while (str.value[i] != 0) { //������� �����
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
		while (str[i] != 0) { //������� �����
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
	void append(char symbol) { //��������� ������ char
		int i = 0;
		char *tempstr = new char[stringLength + 1];
		while (value[i] != 0) { //�������� ������ ������
			tempstr[i] = value[i];
			i++;
		}
		delete[] value;
		tempstr[i] = symbol;
		tempstr[i + 1] = 0;
		stringLength += i + 1;
		value = tempstr;
	}
	void append(const char *str) { //��������� ����������� ������
		int i = 0;
		while (str[i] != 0) { //������� �����
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
		while (val[i] != 0) { //������� �����
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
		while (val[i] != 0) { //������� �����
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
		_String *newstring = new _String;
		
	}
	int pos(const char *str) { //������ ��������� ���������///////////////////////////////////////
		/*int i = 0; j = 0;
		for (i = 0; i < stringLength; i++) { //������ �� �������� ������
			
		}*/
	}
	void remove(int position, int length) { //������� ��������� �� ������
		if (position < 0 || position >= stringLength) {
			cout << "Error in _String.remove(): position error" << endl;
		}
		else if (length > stringLength) {
			cout << "Error in _String.remove(): length error" << endl;
		}
		else if (position + length > stringLength) {
			cout << "Error in _String.remove(): position + length > old length" << endl;
		}
		else {
			char *str = new char[stringLength - length];
			for (int i = 0; i < position; i++){ //�������� �� ������
				str[i] = value[i];
			}
			for (int i = position + length; i < stringLength; i++) { //�������� ���������
				str[i - length] = value[i];
			}
			str[stringLength - length] = 0;
			delete[] value;
			value = str;
			stringLength -= length;
		}
	}
	void insert(int position, const char *source) { //������� ����������� ��������� � �������� ������
		int length = 0, i = 0, j = 0;
		while (source[length] != 0) { //������� ����� ����������� ������
			length++;
		}
		char *str = new char[stringLength + length];
		while (i < position) { //�������� �� �������
			str[i] = value[i];
			i++;
		}
		while (source[j] != 0) { //�������� �����������
			str[i] = source[j];
			i++;
			j++;
		}
		j = position;
		while (value[j] != 0) {//�������� ���������� ��������
			str[i] = value[j];
			i++;
			j++;
		}
		str[i] = 0;
		delete[] value;
		value = str;
		stringLength += length;
	}
	void insert(int position, char *source) { //������� ��������� � �������� ������
		int length = 0, i = 0, j = 0;
		while (source[length] != 0) { //������� ����� ����������� ������
			length++;
		}
		char *str = new char[stringLength + length];
		while (i < position) { //�������� �� �������
			str[i] = value[i];
			i++;
		}
		while (source[j] != 0) { //�������� �����������
			str[i] = source[j];
			i++;
			j++;
		}
		j = position;
		while (value[j] != 0) {//�������� ���������� ��������
			str[i] = value[j];
			i++;
			j++;
		}
		str[i] = 0;
		delete[] value;
		value = str;
		stringLength += length;
	}
	void insert(int position, _String source) { //������� ��������� �� ������� ������� _String � ������
		int i = 0, j = 0;
		char *str = new char[stringLength + source.stringLength];
		while (i < position) { //�������� �� �������
			str[i] = value[i];
			i++;
		}
		while (source.value[j] != 0) { //�������� �����������
			str[i] = source.value[j];
			i++;
			j++;
		}
		j = position;
		while (value[j] != 0) {//�������� ���������� ��������
			str[i] = value[j];
			i++;
			j++;
		}
		str[i] = 0;
		delete[] value;
		value = str;
		stringLength += source.stringLength;
	}
	_String copy(int position, int length) { //���������� ����������� ���������
		char *str = new char[length + 1];
		int i, j; //������� � �������� � ����� ������
		for (i = position, j = 0; j < length; i++, j++) { //��������
			str[j] = value[i];
		}
		str[j] = 0;
		_String newstring; // ������� ������������ ���������
		newstring.stringLength = j;
		newstring.value = str;
		return newstring;
	}
	char operator [] (int index) { //���������� ������ � �������� index
		return value[index];
	}
	int parseInt(int &error) { //����������� � int. error ������ ������ ������� ������� �� �����. ����� -1
		int i = 1;
		if (value[0] != '+' && value[0] != '-' && (value[i] < '0' || value[i] > '9')) { //�� +, �� -, �� �����
			error = 0;
			return 0;
		}
		while (value[i] != 0) {
			if (value[i] < '0' || value[i] > '9') { //���� ������ �� �������� ������
				error = i;
				return 0;
			}
			char c = value[i];
			i++;
		}
		error = -1;
		return atoi(value);
	}
	float parseFloat(int &error) { //����������� �� float. error ������ ������ ������� ������� �� �����. ����� -1
		if (value[0] == '+' || value[0] == '-') { //���� �� ������ ����� ���� �����
			if(value[1] == '.') {
				error = 1;
				return 0;
			}
		}
		if (value[0] != '+' && value[0] != '-' && (value[0] < '0' || value[0] > '9')) { //�� +, �� -, �� �����
			error = 0;
			return 0;
		}
		int i = 1;
		bool dot = false; //����������� �� �������������� �����
		while (value[i] != 0) {
			if (value[i] == '.' && dot == false) { //���� ��� ������ ��� ������������� �����
				dot = true;
			}
			else if (value[i] < '0' || value[i] > '9') { //���� ������ �� �������� ������
				error = i;
				return 0;
			}
			i++;
		}
		error = -1;
		return atof(value);
	}
	bool isEqual(char *str) { //��������� �� ������� �� ������������
		int i = 0;
		bool f = true;
		while (value[i] != 0) {
			if (value[i] != str[i]) {
				return false;
			}
			i++;
		}
		if (str[i] != 0) { // ���� � str ������ ���������, ��� � value
			return false;
		}
		return true;
	}
	bool isEqual(const char *str) { //��������� � ���������� ������� �� ������������
		int i = 0;
		bool f = true;
		while (value[i] != 0) {
			if (value[i] != str[i]) {
				return false;
			}
			i++;
		}
		if (str[i] != 0) { // ���� � str ������ ���������, ��� � value
			return false;
		}
		return true;
	}
};
int main() {
	_String s("qwerty");
	//_String s1("asd");
	//char *str = new char[10];
	//cin.get(str, 9);
	//s.insert(3, s1);
	s.append(s[1]);
	cout << s.value << endl;
	return 0;
}
