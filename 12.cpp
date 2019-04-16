/*Реализовать класс _String, предоставляющий функционал работы со строками.*/
//#include "pch.h"
#include <iostream>
#include <cstdlib>
using namespace std;
class _String {
public: ///////////////////////////////// переделать в private
	char *value;
	int stringLength = -1;
public:
	_String() {//конструктор по умолчанию
		value = new char[1];
		stringLength = 0;
	}
	_String(char *val) { //из массива char
		int i = 0;
		while (val[i] != 0) { //считаем длину
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
	_String(const char *val) { //из константной строки
		int i = 0;
		while (val[i] != 0) { //считаем длину
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
	~_String() { //деструктор
		delete[] value;
	}
	_String(const _String &element) { //из другого объекта _Srting
		int i = 0;
		while (element.value[i] != 0) { //считаем длину
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
	int length() { //возвращает длину строки
		return stringLength;
	}
	void append(_String str) { //добавляем объект _String
		int i = 0;
		while (str.value[i] != 0) { //считаем длину
			i++;
		}
		char *tempstr = new char[stringLength + i + 1];
		i = 0;
		while (value[i] != 0) { //копируем старую строку
			tempstr[i] = value[i];
			i++;
		}
		delete[] value;
		i = 0;
		while (str.value[i] != 0) { //копируем новую строку
			tempstr[stringLength + i] = str.value[i];
			i++;
		}
		value[stringLength + i] = 0;
		stringLength += i;
		value = tempstr;
	}
	void append(char *str) { //добавляем массив char
		int i = 0;
		while (str[i] != 0) { //считаем длину
			i++;
		}
		char *tempstr = new char[stringLength + i + 1];
		i = 0;
		while (value[i] != 0) { //копируем старую строку
			tempstr[i] = value[i];
			i++;
		}
		delete[] value;
		i = 0;
		while (str[i] != 0) { //копируем новую строку
			tempstr[stringLength + i] = str[i];
			i++;
		}
		tempstr[stringLength + i] = 0;
		stringLength += i;
		value = tempstr;
	}
	void append(char symbol) { //добавляем символ char
		int i = 0;
		char *tempstr = new char[stringLength + 1];
		while (value[i] != 0) { //копируем старую строку
			tempstr[i] = value[i];
			i++;
		}
		delete[] value;
		tempstr[i] = symbol;
		tempstr[i + 1] = 0;
		stringLength += i + 1;
		value = tempstr;
	}
	void append(const char *str) { //добавляем константную строку
		int i = 0;
		while (str[i] != 0) { //считаем длину
			i++;
		}
		char *tempstr = new char[stringLength + i + 1];
		i = 0;
		while (value[i] != 0) { //копируем старую строку
			tempstr[i] = value[i];
			i++;
		}
		delete[] value;
		i = 0;
		while (str[i] != 0) { //копируем новую строку
			tempstr[stringLength + i] = str[i];
			i++;
		}
		tempstr[stringLength + i] = 0;
		stringLength += i;
		value = tempstr;
	}
	void setValue(char *val) { //установить значение массива char
		int i = 0;
		while (val[i] != 0) { //считаем длину
			i++;
		}
		char *tempstr = new char[i + 1];
		i = 0;
		while (val[i] != 0) { //заполняем
			tempstr[i] = val[i];
			i++;
		}
		tempstr[i] = 0;
		delete[] value;
		value = tempstr;
		stringLength = i;
	}
	void setValue(const char *val) { //установить константное значение
		int i = 0;
		while (val[i] != 0) { //считаем длину
			i++;
		}
		char *tempstr = new char[i + 1];
		i = 0;
		while (val[i] != 0) { //заполняем
			tempstr[i] = val[i];
			i++;
		}
		tempstr[i] = 0;
		delete[] value;
		value = tempstr;
		stringLength = i;
	}
	void setValue(int val) { //установить значение переконвертированное из int
		if (val == 0) { //если 0
			delete[] value;
			value = new char[2];
			value[0] = '0';
			value[1] = 0;
			stringLength = 1;
		}
		else { //если не 0
			int len = 0;
			char* tempstr = new char[100];
			while (val != 0) { //записываем число в массив в перевернутом виде
				tempstr[len] = char(val % 10 + 48); //записываем символ цифры
				val = val / 10;
				len++;
			}
			for (int i = 0, j = len - 1; i < len / 2; i++, j--) { //реверс
				swap(tempstr[i], tempstr[j]);
			}
			tempstr[len] = 0;
			delete[] value;
			value = new char[len + 1]; //новый размер value
			int i = 0;
			while (tempstr[i] != 0) { //копируем в value символы из временной строки
				value[i] = tempstr[i];
				i++;
			}
			value[i] = 0;
			stringLength = i;
			delete[] tempstr;
		}
	}
	void setValue(double val, int precision = 10) { //установить значение переконвертированное из double c точностью 10 знаков после запятой по умолчанию///////////////
	}
	_String operator = (const _String &element) {
	}
	_String operator + (const _String &right) {
		_String *newstring = new _String;
		
	}
	int pos(const char *str) { //первое вхождение подстроки///////////////////////////////////////
		/*int i = 0; j = 0;
		for (i = 0; i < stringLength; i++) { //проход по исходной строке
			
		}*/
	}
	void remove(int position, int length) { //удалить подстроку из строки
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
			for (int i = 0; i < position; i++){ //копируем до выреза
				str[i] = value[i];
			}
			for (int i = position + length; i < stringLength; i++) { //копируем остальное
				str[i - length] = value[i];
			}
			str[stringLength - length] = 0;
			delete[] value;
			value = str;
			stringLength -= length;
		}
	}
	void insert(int position, const char *source) { //вставка константной подстроки в исходную строку
		int length = 0, i = 0, j = 0;
		while (source[length] != 0) { //подсчет длины вставляемой строки
			length++;
		}
		char *str = new char[stringLength + length];
		while (i < position) { //копируем до вставки
			str[i] = value[i];
			i++;
		}
		while (source[j] != 0) { //копируем вставляемые
			str[i] = source[j];
			i++;
			j++;
		}
		j = position;
		while (value[j] != 0) {//копируем оставшиеся элементы
			str[i] = value[j];
			i++;
			j++;
		}
		str[i] = 0;
		delete[] value;
		value = str;
		stringLength += length;
	}
	void insert(int position, char *source) { //вставка подстроки в исходную строку
		int length = 0, i = 0, j = 0;
		while (source[length] != 0) { //подсчет длины вставляемой строки
			length++;
		}
		char *str = new char[stringLength + length];
		while (i < position) { //копируем до вставки
			str[i] = value[i];
			i++;
		}
		while (source[j] != 0) { //копируем вставляемые
			str[i] = source[j];
			i++;
			j++;
		}
		j = position;
		while (value[j] != 0) {//копируем оставшиеся элементы
			str[i] = value[j];
			i++;
			j++;
		}
		str[i] = 0;
		delete[] value;
		value = str;
		stringLength += length;
	}
	void insert(int position, _String source) { //вставка подстроки из другого объекта _String в строку
		int i = 0, j = 0;
		char *str = new char[stringLength + source.stringLength];
		while (i < position) { //копируем до вставки
			str[i] = value[i];
			i++;
		}
		while (source.value[j] != 0) { //копируем вставляемые
			str[i] = source.value[j];
			i++;
			j++;
		}
		j = position;
		while (value[j] != 0) {//копируем оставшиеся элементы
			str[i] = value[j];
			i++;
			j++;
		}
		str[i] = 0;
		delete[] value;
		value = str;
		stringLength += source.stringLength;
	}
	_String copy(int position, int length) { //возвращает динмическую подстроку
		char *str = new char[length + 1];
		int i, j; //позиции в исходной и новой строке
		for (i = position, j = 0; j < length; i++, j++) { //копируем
			str[j] = value[i];
		}
		str[j] = 0;
		_String newstring; // создаем возвращаемую подстроку
		newstring.stringLength = j;
		newstring.value = str;
		return newstring;
	}
	char operator [] (int index) { //возвращает символ с индексом index
		return value[index];
	}
	int parseInt(int &error) { //конвертация в int. error вернет индекс первого символа не числа. иначе -1
		int i = 1;
		if (value[0] != '+' && value[0] != '-' && (value[i] < '0' || value[i] > '9')) { //не +, не -, не цифра
			error = 0;
			return 0;
		}
		while (value[i] != 0) {
			if (value[i] < '0' || value[i] > '9') { //если символ не является цифрой
				error = i;
				return 0;
			}
			char c = value[i];
			i++;
		}
		error = -1;
		return atoi(value);
	}
	float parseFloat(int &error) { //конвертация во float. error вернет индекс первого символа не числа. иначе -1
		if (value[0] == '+' || value[0] == '-') { //если за знаком сразу идет точка
			if(value[1] == '.') {
				error = 1;
				return 0;
			}
		}
		if (value[0] != '+' && value[0] != '-' && (value[0] < '0' || value[0] > '9')) { //не +, не -, не цифра
			error = 0;
			return 0;
		}
		int i = 1;
		bool dot = false; //встречалась ли разделительная точка
		while (value[i] != 0) {
			if (value[i] == '.' && dot == false) { //если это первый раз встретившаяся точка
				dot = true;
			}
			else if (value[i] < '0' || value[i] > '9') { //если символ не является цифрой
				error = i;
				return 0;
			}
			i++;
		}
		error = -1;
		return atof(value);
	}
	bool isEqual(char *str) { //сравнение со строкой на одинаковость
		int i = 0;
		bool f = true;
		while (value[i] != 0) {
			if (value[i] != str[i]) {
				return false;
			}
			i++;
		}
		if (str[i] != 0) { // если в str больше элементов, чем в value
			return false;
		}
		return true;
	}
	bool isEqual(const char *str) { //сравнение с констнтной строкой на одинаковость
		int i = 0;
		bool f = true;
		while (value[i] != 0) {
			if (value[i] != str[i]) {
				return false;
			}
			i++;
		}
		if (str[i] != 0) { // если в str больше элементов, чем в value
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
