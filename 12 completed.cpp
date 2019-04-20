/*����������� ����� _String, ��������������� ���������� ������ �� ��������.*/
//#include "pch.h"
#include <iostream>
#include <cstdlib> //��� ������� �������� �� ������� �������� � �����: atoi(), atof()
#include <cmath> //��� ������� ��������� ������� ����� �� �����: trunc()
using namespace std;
class _String {
protected:
	char *value;
	int stringLength = -1;
public:
	_String() {//����������� �� ���������
		value = new char[1];
		value[0] = 0;
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
		value = new char[element.stringLength + 1];
		while (element.value[i] != 0) { //��������
			value[i] = element.value[i];
			i++;
		}
		value[i] = 0;
		stringLength = element.stringLength;
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
		delete[] value;
		int i = 0;
		while (val[i] != 0) { //������� �����
			i++;
		}
		value = new char[i + 1];
		i = 0;
		while (val[i] != 0) { //���������
			value[i] = val[i];
			i++;
		}
		value[i] = 0;
		stringLength = i;
	}
	void setValue(const char *val) { //���������� ����������� ��������
		delete[] value;
		int i = 0;
		while (val[i] != 0) { //������� �����
			i++;
		}
		value = new char[i + 1];
		i = 0;
		while (val[i] != 0) { //���������
			value[i] = val[i];
			i++;
		}
		value[i] = 0;
		stringLength = i;
	}
	void setValue(int val) { //���������� �������� �������������������� �� int
		delete[] value;
		if (val == 0) { //���� 0
			value = new char[2];
			value[0] = '0';
			value[1] = 0;
			stringLength = 1;
		}
		else { //���� �� 0
			int i = 0, j, length = 0, val1 = val;
			while (val1 != 0) { //������� ���������� ���� � �����
				val1 /= 10;	
				length++;
			}
			if (val < 0) { //���� ����� �������������
				value = new char[length + 2]; //��������� ����� ��� ����� �����
				value[0] = '-';
				i++;
			}
			else { //���� ����� �������������
				value = new char[length + 1];
			}
			val1 = val;
			while (val1 != 0) { //���������� ����� � ������ � ������������ ����
				value[i] = char(abs(val1 % 10) + 48);
				val1 /= 10;
				i++;
			}
			if (val < 0) { //��� ������������� ����� ������ ������ ��������� ���� �����
				j = 1;
				value[length + 1] = 0;
				stringLength = length + 1; //�������� ���� ������
			}
			else { //��� ������������� �����
				j = 0;
				value[length] = 0;
				stringLength = length;
			}
			for (j, i--; j < (length+1) / 2; j++, i--) { //������ ������ �������
				swap(value[j], value[i]);
			}
		}
	}
	void setValue(double val, int precision = 10) { //���������� �������� �������������������� �� double c ��������� 10 ������ ����� ������� �� ���������
		delete[] value; //������� ������ ������
		if (val == 0) { //��� ����
			value = new char[2];
			value[0] = '0';
			value[1] = 0;
			stringLength = 1;
		}
		else { //val != 0
			int lenintpart = 0, intpart = trunc(val), i = 0, j = 0, minus = 0;
			double floatpart = abs(val - intpart);
			char *tempstr = new char[100];
			if (val < 0) { //��������� ����� ��� ������������� �����
				tempstr[0] = '-';
				minus++;
				i++;
				j++;
			}
			if (intpart == 0) { //������� ����� �����
				lenintpart = 1;
				tempstr[i] = '0';
				i++;
			}
			else { //����� ����� �� �������
				while (intpart != 0) { //���������� ����� ����� � ������������ ���� � ������� ���������� ����
					tempstr[i] = char(abs(intpart % 10) + 48);
					intpart /= 10;
					lenintpart++;
					i++;
				}
				for (i--, j; j < (lenintpart + 1 + minus) / 2; j++, i--) { //������ ������ �������
					swap(tempstr[j], tempstr[i]);
				}
				i = lenintpart + minus; //������������� �� ������ ����� ���� ����� �����
			}
			if (floatpart != 0) { //���� ������� �����
				tempstr[i] = '.';
				i++;
				int step = 0;
				while (floatpart != 0 && step < precision) { //���������� ������� �����
					j = trunc(floatpart * 10); //������ ����� ����� �����
					tempstr[i] = char(j + 48);
					floatpart = abs((floatpart * 10) - j); //������ ������, ��� ��� ������� ���������� ����� ��������� ������������� �����
					i++;
					step++;
				}
			}
			tempstr[i] = 0;
			value = new char[i];
			for (j = 0; j < i; j++) { //�������� �������� �� ��������� ������
				value[j] = tempstr[j];
			}
			value[j] = 0;
			stringLength = j;
			delete[] tempstr;
		}
	}
	_String operator = (const _String &element) { //���������� ������������� ������ _String ��������� �������
		char *str = new char[element.stringLength + 1];
		int i = 0;
		while (element.value[i] != 0) { //�������� ������
			str[i] = element.value[i];
			i++;
		}
		str[i] = 0;
		_String newstring;
		newstring.value = str;
		newstring.stringLength = element.stringLength;
		return newstring;
	}
	_String operator + (const _String &right) { //���������� ����� ������ _String, ���������� � ���������� ������������ ��������
		char *str = new char[stringLength + right.stringLength + 1];
		int i = 0, j = 0;
		while (value[i] != 0) { //�������� ������ �����
			str[i] = value[i];
			i++;
		}
		while (right.value[j] != 0) { //�������� ������ �����
			str[i] = right.value[j];
			i++;
			j++;
		}
		str[i] = 0;
		_String newstring;
		newstring.value = str;
		newstring.stringLength = stringLength + right.stringLength;
		return newstring;
	}
	int pos(const char *str) { //������ ��������� ���������. ������ -1 ���� �� �������
		if (str[0] == 0) {
			cout << "Error in _String.pos(): empty input" << endl;
			return -1;
		}
		int i, j = 0, index = 0;
		for (i = 0; i < stringLength; i++) { //������ �� �������� ������
			if (str[j] == 0) { //������� ��������� �������
				return index;
			}
			if (value[i] == str[j]) { //������� ���������
				j++;
			}
			else { //������� �� ���������
				index = i + 1;
				j = 0;
			}
		}
		if (str[j] == 0) { //������� ��������� ������������� ��� ��, ��� �������� ������
			return index;
		}
		else { //�� ������ ������� ����������
			return -1;
		}
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
			for (int i = 0; i < position; i++) { //�������� �� ������
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
	int parseInt(int &error) { //����������� � int. error ������ ������ ������� �������, ������� �� ��������� � �����. ����� -1
		int i = 1;
		if (value[0] != '+' && value[0] != '-' && (value[i] < '0' || value[i] > '9')) { //������ ������ �� +, �� -, �� �����
			error = 0;
			return 0;
		}
		while (value[i] != 0) {
			if (value[i] < '0' || value[i] > '9') { //���� ������ �� �������� ������
				error = i;
				return 0;
			}
			i++;
		}
		error = -1;
		return atoi(value);
	}
	float parseFloat(int &error) { //����������� �� float. error ������ ������ ������� �������, ������� �� ��������� � �����. ����� -1
		if (value[0] == '+' || value[0] == '-') { //���� �� ������ ����� ���� �����
			if (value[1] == '.') {
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
	_String s("aadfadaf");
	double val = 0.123456;
	int p = 5;
	s.setValue(val,p);
	cout << s.value << ' ' << s.stringLength << endl;
	return 0;
}
