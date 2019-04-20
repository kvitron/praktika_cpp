/*Реализовать класс _String, предоставляющий функционал работы со строками.*/
//#include "pch.h"
#include <iostream>
#include <cstdlib> //для функции перевода из массива символов в число: atoi(), atof()
#include <cmath> //для функции отсечения дробной части от числа: trunc()
using namespace std;
class _String {
protected:
	char *value;
	int stringLength = -1;
public:
	_String() {//конструктор по умолчанию
		value = new char[1];
		value[0] = 0;
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
		value = new char[element.stringLength + 1];
		while (element.value[i] != 0) { //копируем
			value[i] = element.value[i];
			i++;
		}
		value[i] = 0;
		stringLength = element.stringLength;
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
		delete[] value;
		int i = 0;
		while (val[i] != 0) { //считаем длину
			i++;
		}
		value = new char[i + 1];
		i = 0;
		while (val[i] != 0) { //заполняем
			value[i] = val[i];
			i++;
		}
		value[i] = 0;
		stringLength = i;
	}
	void setValue(const char *val) { //установить константное значение
		delete[] value;
		int i = 0;
		while (val[i] != 0) { //считаем длину
			i++;
		}
		value = new char[i + 1];
		i = 0;
		while (val[i] != 0) { //заполняем
			value[i] = val[i];
			i++;
		}
		value[i] = 0;
		stringLength = i;
	}
	void setValue(int val) { //установить значение переконвертированное из int
		delete[] value;
		if (val == 0) { //если 0
			value = new char[2];
			value[0] = '0';
			value[1] = 0;
			stringLength = 1;
		}
		else { //если не 0
			int i = 0, j, length = 0, val1 = val;
			while (val1 != 0) { //считаем количество цифр в числе
				val1 /= 10;	
				length++;
			}
			if (val < 0) { //если число отрицательное
				value = new char[length + 2]; //оставляем место для знака минус
				value[0] = '-';
				i++;
			}
			else { //если число положительное
				value = new char[length + 1];
			}
			val1 = val;
			while (val1 != 0) { //записываем число в массив в перевернутом виде
				value[i] = char(abs(val1 % 10) + 48);
				val1 /= 10;
				i++;
			}
			if (val < 0) { //при отрицательном числе делаем реверс пропуская знак минус
				j = 1;
				value[length + 1] = 0;
				stringLength = length + 1; //учитывая знак минуса
			}
			else { //при положительном числе
				j = 0;
				value[length] = 0;
				stringLength = length;
			}
			for (j, i--; j < (length+1) / 2; j++, i--) { //делаем реверс массива
				swap(value[j], value[i]);
			}
		}
	}
	void setValue(double val, int precision = 10) { //установить значение переконвертированное из double c точностью 10 знаков после запятой по умолчанию
		delete[] value; //удаляем старую строку
		if (val == 0) { //при нуле
			value = new char[2];
			value[0] = '0';
			value[1] = 0;
			stringLength = 1;
		}
		else { //val != 0
			int lenintpart = 0, intpart = trunc(val), i = 0, j = 0, minus = 0;
			double floatpart = abs(val - intpart);
			char *tempstr = new char[100];
			if (val < 0) { //учитываем минус при отрицательном числе
				tempstr[0] = '-';
				minus++;
				i++;
				j++;
			}
			if (intpart == 0) { //нулевая целая часть
				lenintpart = 1;
				tempstr[i] = '0';
				i++;
			}
			else { //целая часть не нулевая
				while (intpart != 0) { //записываем целую часть в перевернутом виде и считаем количество цифр
					tempstr[i] = char(abs(intpart % 10) + 48);
					intpart /= 10;
					lenintpart++;
					i++;
				}
				for (i--, j; j < (lenintpart + 1 + minus) / 2; j++, i--) { //делаем реверс массива
					swap(tempstr[j], tempstr[i]);
				}
				i = lenintpart + minus; //передвигаемся на ячейку после цифр целой части
			}
			if (floatpart != 0) { //есть дробная часть
				tempstr[i] = '.';
				i++;
				int step = 0;
				while (floatpart != 0 && step < precision) { //записываем дробную часть
					j = trunc(floatpart * 10); //первая цифра после точки
					tempstr[i] = char(j + 48);
					floatpart = abs((floatpart * 10) - j); //модуль потому, что при ошибках округления может появиться отрицательное число
					i++;
					step++;
				}
			}
			tempstr[i] = 0;
			value = new char[i];
			for (j = 0; j < i; j++) { //копируем элементы из временной строки
				value[j] = tempstr[j];
			}
			value[j] = 0;
			stringLength = j;
			delete[] tempstr;
		}
	}
	_String operator = (const _String &element) { //возвращает дублированный объект _String исходного объекта
		char *str = new char[element.stringLength + 1];
		int i = 0;
		while (element.value[i] != 0) { //копируем строку
			str[i] = element.value[i];
			i++;
		}
		str[i] = 0;
		_String newstring;
		newstring.value = str;
		newstring.stringLength = element.stringLength;
		return newstring;
	}
	_String operator + (const _String &right) { //возвращает новый объект _String, полученный в результате конкатенации исходных
		char *str = new char[stringLength + right.stringLength + 1];
		int i = 0, j = 0;
		while (value[i] != 0) { //копируем первую часть
			str[i] = value[i];
			i++;
		}
		while (right.value[j] != 0) { //копируем вторую часть
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
	int pos(const char *str) { //первое вхождение подстроки. вернет -1 если не найдено
		if (str[0] == 0) {
			cout << "Error in _String.pos(): empty input" << endl;
			return -1;
		}
		int i, j = 0, index = 0;
		for (i = 0; i < stringLength; i++) { //проход по исходной строке
			if (str[j] == 0) { //искомая подстрока нашлась
				return index;
			}
			if (value[i] == str[j]) { //символы совпадают
				j++;
			}
			else { //символы не совпадают
				index = i + 1;
				j = 0;
			}
		}
		if (str[j] == 0) { //искомая подстрока заканчивается там же, где исходная строка
			return index;
		}
		else { //ни одного полного совпадения
			return -1;
		}
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
			for (int i = 0; i < position; i++) { //копируем до выреза
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
	int parseInt(int &error) { //конвертация в int. error вернет индекс первого символа, который не относится к числу. иначе -1
		int i = 1;
		if (value[0] != '+' && value[0] != '-' && (value[i] < '0' || value[i] > '9')) { //первый символ не +, не -, не цифра
			error = 0;
			return 0;
		}
		while (value[i] != 0) {
			if (value[i] < '0' || value[i] > '9') { //если символ не является цифрой
				error = i;
				return 0;
			}
			i++;
		}
		error = -1;
		return atoi(value);
	}
	float parseFloat(int &error) { //конвертация во float. error вернет индекс первого символа, который не относится к числу. иначе -1
		if (value[0] == '+' || value[0] == '-') { //если за знаком сразу идет точка
			if (value[1] == '.') {
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
	_String s("aadfadaf");
	double val = 0.123456;
	int p = 5;
	s.setValue(val,p);
	cout << s.value << ' ' << s.stringLength << endl;
	return 0;
}
