/*–еализовать класс _String, предоставл€ющий функционал работы со строками.*/
#include "pch.h"
#include <iostream>
using namespace std;
class _String {
	char *value;
	int stringLength = -1;
public:
	_String() {//конструктор по умолчанию
		value = new char[1000];
		stringLength = 0;
	}
	_String(char *val) { //из массива char
		int i = 0;
		char *str = new char[1000];
		while (*(val + i) != 0) {
			*(str + i) = *(val + i);
			i++;
		}
		*(str + i) = 0;
		value = str;
		stringLength = i;
	}
	_String(const char *val) { //из константной строки
		int i = 0;
		char *str = new char[1000];
		while (*(val + i) != 0) {
			*(str + i) = *(val + i);
			i++;
		}
		*(str + i) = 0;
		value = str;
		stringLength = i;
	}
	~_String() { //деструктор
		delete[] value;
	}
	_String(const _String &element) { //из другого объекта _Srting
		int i = 0;
		char *str = new char[1000];
		char *val = element.value;/////////////////////////////////
		while (*(val + i) != 0) {
			str[i] = element.value[i];
			i++;
		}
		*(str + i) = 0;
		value = str;
		stringLength = i;
	}
	int length() { //возвращает длину строки
		return stringLength;
	}
	void append(_String str) {
	}
	void append(char *str) { //добавл€ем массив char к строке
	}
	void append(const char *str) {
	}
	void setValue(char *val) {
	}
	void setValue(const char *val) { //установить константное значение

	}
	void setValue(int val) {
	}
	void setValue(double val, int precision = 10) {
	}
	_String operator = (const _String &element) {
	}
	_String operator + (const _String &right) {
	}
	int pos(const char *str) {
	}
	void remove(int position, int length) {
	}
	void insert(int position, int length, const char *source) {
	}
	void insert(int position, int length, char *source) {
	}
	void insert(int position, int length, _String source) {
	}
	_String copy(int position, int length) {
	}
	char operator [] (int index) {
	}
	int parseInt(int &error) {
	}
	float parseFloat(int &error) {
	}
	bool isEqual(char *str) {
	}
	bool isEqual(const char *str) {
	}
	char *getValue() {
		return value;
	}
};
int main() {
	//_String s0;
	//cout << s0.length() << endl;

	_String s1("AbC");
	cout << s1.length() << endl;

	//char s[10];
	//cin >> s;
	//_String s2(s);
	//cout << s2.length() << endl;

	/*_String s3(s1);//////////////////////////////////
	cout << s3.length() << endl;*/



		return 0;
}