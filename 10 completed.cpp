/*Арифметическое выражение можно представить в обратной польской записи,
где знаки операции следуют за операндами, а не ставятся между ними, как в обычной записи выражений.
Обратная польская запись не требует скобок. Например, выражению 1+2 соответствует запись 1 2 +,
а выражению 1+2*3 соответствует запись 1 2 3 * +, запись (2+3)*(3-1) записывается как 2 3 + 3 1 - *.
Зада?тся строка – выражение в обратной полькой записи (числа и знаки +, -, * разделены пробелами).
Используя стек, вычислите значение выражения.*/
//#include "pch.h"
#include <iostream>
#include <cstdlib>
using namespace std;
class ListElement {
public:
	int value;
	ListElement *next = NULL;
	ListElement *prev = NULL; //для метода clear
};

class Stack {
private:
	ListElement stackobj;
public:
	void push(int n) {
		//добавляет новый элемент
		ListElement *current = &stackobj;
		while (current->next != NULL) {
			current = current->next;
		}
		ListElement *newElement = new ListElement;
		current->next = newElement;
		newElement->value = n;
		newElement->prev = current;
		//cout << "OK" << endl;
	}

	int pop() {
		//удаляет последний элемент стека и возвращает его
		ListElement *current = &stackobj, *prev = NULL;
		while (current->next != NULL) {
			prev = current;
			current = current->next;
		}
		if (prev != NULL) {//если стек не пуст
			prev->next = NULL; //обрубаем хвост у предпоследнего узла
			int element = current->value; //для очистки памяти от динамического объекта
			delete current;
			return element;
		}
		else cout << "EMPTY STACK";
	}

	int back() {
		//возвращает последний элемент стека
		ListElement *current = &stackobj;
		while (current->next != NULL) {
			current = current->next;
		}
		return current->value;
	}

	int size() {
		//возвращает размер стека
		int size = 0;
		ListElement *current = &stackobj;
		while (current->next != NULL) {
			current = current->next;
			size++;
		}
		return size;
	}

	void clear() {
		//очищает стек
		ListElement *current = &stackobj, *prev = NULL;
		while (current->next != NULL) {
			prev = current;
			current = current->next;
		}
		while (prev != NULL) {
			delete current;
			current = prev;
			current->next = NULL;
			prev = current->prev;
		}
		//cout << "OK" << endl;
	}

	void showList() {
		//выводит элементы через пробел. если пустой, то выводит EMPTY
		ListElement *current = &stackobj;
		bool empty = true; //проверка на пустоту
		while (current->next != NULL) {
			current = current->next;
			cout << current->value << ' ';
			empty = false;
		}
		if (empty) cout << "EMPTY";
		cout << endl;
	}
};

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
void reversepolish(Stack &stack, char *input){
	/*выполняет обратную польскую операция над стеком*/
	int last = stack.pop();
	int secondlast = stack.pop();
	if (input[0] == '+') {//если сложение
		stack.push(last + secondlast);
	}
	if (input[0] == '-') {//если вычитание
		stack.push(secondlast - last);
	}
	if (input[0] == '*') {//если умножение
		stack.push(last * secondlast);
	}
}
int main() {
	Stack stack;
	char *input = new char[1000];
	cin.get(input, 999);
	int numgap = find(input, " "); //номер первого пробела
	while (numgap != -1) { // пока в строке есть пробелы
		if (input[0] >= '0' && input[0] <= '9') {//если на первом месте число
			char *s1 = copy(input, 0, numgap);
			stack.push(atoi(s1));
			delete[] s1;
		}
		else { //если на первом месте знак операции
			reversepolish(stack, input);
		}
		input = del(input, 0, numgap + 1); //удалить число или символ вместе с пробелом
		numgap = find(input, " "); //номер нового первого пробела
		stack.showList(); //вывод каждого действия. заккоментировать при ненадобности
	}
	//то же самое для последней операции
	reversepolish(stack, input);
	stack.showList(); //результат
	return 0;
}
