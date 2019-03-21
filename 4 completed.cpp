/*В файле хранится строка, содержащая арифметическое выражение из
целых чисел, а также знаков +, -, *, / без скобок. Вычислить значение выражения.*/
//#include "pch.h"
#include <iostream>
#include <cmath>
using namespace std;
int find(char *source, const char *search) {
	//находит первое вхождение символа в строку
	int count = 0; //на сколько сдвинули итератор
	while (*source != 0) {
		if (*source == *search) {
			source -= count;
			return count;
		}
		else {
			count++;
			source++;
		}
	}
	source -= count;
	return -1;
}
char *copy(char *source, int index, int count) {
	//возвращает указатель на подстроку. необходимо удалить новый динасический массив в основной программе
	char* s1 = new char[count + 1];
	source += index;
	for (int i = 0; i < count; ++i) {
		*s1 = *source;
		s1++;
		source++;
	}
	*s1 = 0;
	s1 -= count;
	source -= (count + index);
	return s1;
}
char *del(char *source, int index, int count) {
	//возвращает строку с удаленными count элементами
	int length = 0;
	for (length = 0; *(source + length) != 0; length++) continue; //подсчет длины исходной строки
	char* s1 = new char[length - count + 1]; //создаем новую строку
	for (int i = 0; i < index; ++i) { //копируем элементы до index
		*(s1 + i) = *(source + i);
	}
	int p = index + count;
	for (int i = 0; i < length - index - count; i++) {//копируем элементы после index
		*(s1 + index + i) = *(source + p + i);
	}
	*(s1 + length - count) = 0;
	delete[] source;
	return s1;
}
char *insert(char *source, int index, char *paste) {
	//возвращает строку со вставленной подстрокой
	int len_source = 0, len_paste = 0;
	for (len_source = 0; *(source + len_source) != 0; len_source++) continue; //подсчет длины исходной строки
	for (len_paste = 0; *(paste + len_paste) != 0; len_paste++) continue; //подсчет длины подстроки
	char* s1 = new char[len_source + len_paste];
	for (int i = 0; i < index; ++i) { //копируем элементы до index
		*(s1 + i) = *(source + i);
	}
	for (int i = index, j = 0; j < len_paste; ++i, ++j) { //вставляем подстроку paste в s1
		*(s1 + i) = *(paste + j);
	}
	for (int i = index + len_paste; i < len_paste + len_source; ++i) {//копируем оставшиеся элементы
		*(s1 + i) = *(source + i - len_paste);
	}
	*(s1 + len_source + len_paste) = 0;
	delete[] source;
	return s1;
}
float str_to_f(char *source) {
	// возвращает действительное число из строки
	float result = 0; int count = 0, beforedot = 0, afterdot = 0; bool dot = false;
	while (*(source + count) != 0) { //подсчитываем количество цифр в числе
		if (*(source + count) != '.' && dot == false) { //до точки
			beforedot++;
			count++;
		}
		else if (*(source + count) == '.') { //точка
			dot = true;
			count++;
		}
		else { //после точки
			afterdot++;
			count++;
		}
	}
	for (int i = 0; i < beforedot; ++i) { //высчитываем целую часть
		result += (int(*(source + i)) - int('0')) * pow(10, beforedot - 1 - i);
	}
	if (dot) { //высчитываем дробную часть
		int number = 0;
		for (int i = beforedot + 1, j = 0; i <= beforedot + afterdot; ++i, ++j) {
			number += (int(*(source + i)) - int('0')) * pow(10, afterdot - 1 - j);
		}
		result += number / pow(10, afterdot);
	}
	return result;
}
char *f_to_str(float source) {
	//возвращает строку из числа
	int intpart = trunc(source), lenintpart = 0;
	float floatpart = source - intpart;
	char* s1 = new char[100];
	int i = 0;
	if (intpart == 0) {//если целая часть = 0
		*s1 = '0';
		i++;
	}
	for (int ostatok; intpart > 0; ++i, intpart /= 10, lenintpart++) {//записываем целую часть
		ostatok = intpart % 10;
		*(s1 + i) = char(ostatok + int('0'));
	}
	for (int j = 0, k = lenintpart - 1; k >= lenintpart / 2; k--, j++){//реверс цифр целой части
		swap(*(s1 + j), *(s1 + k));
	}
	//неверно выдает дробную часть при большом размере числа. возможно из-за cout************
	if (floatpart != 0) {//если есть дробная часть
		*(s1 + i) = '.';
		i++;
		int ostatok, step = 0;
		while (floatpart > 0 && step < 6) {//записываем дробную часть (не больше n символов)
			ostatok = trunc(floatpart * 10);
			*(s1 + i) = char(ostatok + int('0'));
			floatpart = (floatpart * 10) - ostatok;
			i++;
			step++;
		}
	}
	*(s1 + i) = 0;
	return s1;
}
int findleftindex(char *source, int index){//поиск левого индекса числа
	while (index > 0){
		index--;
		if (*(source + index) == '+' || *(source + index) == '-' || *(source + index) == '*' || *(source + index) == '/') return index + 1;
		if (index == 0) return 0;
	}
}
int findrightindex(char *source, int index){//поиск правого индекса числа
	while (*(source + index) != 0){
		index++;
		if (*(source + index) == '+' || *(source + index) == '-' || *(source + index) == '*' || *(source + index) == '/') return index - 1;
	}
	return index - 1;
}
char *math(char *s, const char *operation, int znak){
	/*выполняет математическую операцию со строкой*/
	int lgran, rgran; //индексы левой и правой границ левого и правого числа
	float leftnumber, rightnumber, result; //сами числа
	//находим левое число
	lgran = findleftindex(s, znak);
	char *s1 = copy(s, lgran, znak - lgran);
	leftnumber = str_to_f(s1);
	delete[] s1;
	//находим правое число
	rgran = findrightindex(s, znak);
	s1 = copy(s, znak + 1, rgran - znak);
	rightnumber = str_to_f(s1);
	delete[] s1;
	//выполняем действие с числами
	if(operation == "*") result = leftnumber*rightnumber;
	else if(operation == "/") result = leftnumber/rightnumber;
	else if(operation == "+") result = leftnumber+rightnumber;
	else if(operation == "-") result = leftnumber-rightnumber;
	//добавляем результат в s
	s = del(s, lgran, rgran - lgran + 1);
	s1 = f_to_str(result);
	s = insert(s, lgran, s1);
	delete[] s1;
	return s;
}
int main() {
	char* s = new char[1000];
	cin.get(s, 999);
	int nummult, numdiv, numsum, numdiff; //индекс элемента знака операции
	bool multexist, divexist, sumexist, diffexist; // флаги существования операций в строке
	
	//проверяем на существование * и /
	if ((nummult = find(s, "*")) != -1) {
		multexist = true;
	}
	else {
		multexist = false;
	}
	if ((numdiv = find(s, "/")) != -1) {
		divexist = true;
	}
	else {
		divexist = false;
	}
	//решаем все умножения и деления
	while (multexist || divexist){ //если есть умножение или деление
		if (numdiv == -1) { //только умножение
			s = math(s, "*", nummult);
		}
		else if (nummult == -1) { //только деление
			s = math(s, "/", numdiv);
		}
		else{ //есть и то, и то
			if (nummult < numdiv) {
				s = math(s, "*", nummult);
			}
			else {
				s = math(s, "/", numdiv);
			}
		}
		//проверяем на существование * и /
		if ((nummult = find(s, "*")) != -1) {
			multexist = true;
		}
		else {
			multexist = false;
		}
		if ((numdiv = find(s, "/")) != -1) {
			divexist = true;
		}
		else {
			divexist = false;
		}
		cout << s << endl;
	}
	
	//проверяем на существование + и -
	if ((numsum = find(s, "+")) != -1) {
		sumexist = true;
	}
	else {
		sumexist = false;
	}
	if ((numdiff = find(s, "-")) != -1) {
		diffexist = true;
	}
	else {
		diffexist = false;
	}
	//решаем все сложения и вычитания
	while (sumexist || diffexist){ //если есть сложение или вычитание
		if (numdiff == -1) { //только сложение
			s = math(s, "+", numsum);
		}
		else if (numsum == -1) { //только вычитание
			s = math(s, "-", numdiff);
		}
		else{ //есть и то, и то
			if (numsum < numdiff) {
				s = math(s, "+", numsum);
			}
			else {
				s = math(s, "-", numdiff);
			}
		}
		
		//проверяем на существование + и -
		if ((numsum = find(s, "+")) != -1) {
			sumexist = true;
		}
		else {
			sumexist = false;
		}
		if ((numdiff = find(s, "-")) != -1) {
			diffexist = true;
		}
		else {
			diffexist = false;
		}
		cout << s << endl;
	}
	
	delete[] s;
	return 0;
}
//следующая строка не работает при нахождении индекса деления
//while (((nummult = find(s, "*")) != -1) || ((numdiv = find(s, "/")) != -1)){
