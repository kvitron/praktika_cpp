#include <iostream>
#include "_String.h"
#include "_String Stack.h" //стек строк
using namespace  std;

int main() {
	//считываем исходную строку
	char *tempstring = new char[1000];
	cin.get(tempstring, 999);
	_String source(tempstring);
	delete[] tempstring;

	
	//проверяем правильность расстановки скобок
	Stack operations; //стек, хранящий арифметические операции
	int i = 0;
	while (source[i] != 0) { // проходим по строке
		if (source[i] == '(') { // при открывающейся скобке
			operations.push("(");
			cout << "( was pushed" << endl;
		}
		if (source[i] == ')') { // при закрывающейся скобке
			if (operations.back().isEqual("(")) { // если последняя скобка в стеке открывающаяся
				operations.pop();
			}
			else { // последняя операция в стеке не является открывающейся скобкой
				cout << ") ne vstretila ( v steke" << endl;
				return 0;
			}
		}
		i++;
	}
	if (operations.size() != 0) { //количество ")" меньше колиества "("
		cout<<"count ) < count (" << endl;
		return 0;
	}
	else { // корректная расстановка скобок
		cout << "correct bracketing " << endl;
	}


	//переводим исходную строку в вид обратной польской записи
	i = 0; // индекс исходной строки
	_String result;
	while (source[i] != 0) { //проход по исходной строке
		if (source[i] >= '0' && source[i] <= '9') { //если встретилась цифра
			result.append(source[i]); //записываем её
		}
		if (source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '/') { //если встретилась операция
			if (operations.size() == 0 || operations.back().isEqual("(")) { //если стек пуст или последняя операция "("
				_String tempstring;
				tempstring.append(source[i]);
				operations.push(tempstring); // кладем операцию в стек
			}
			if ((source[i] == '*' || source[i] == '/') && (operations.back().isEqual("+") || operations.back().isEqual("-"))) {
				// если новая операция имеет больший приоритет, чем верхняя операции в стеке
				_String tempstring;
				tempstring.append(source[i]);
				operations.push(tempstring); // кладем операцию в стек
			}
			else { //новая операция имеет меньший или равный приоритет, чем верхняя операция в стеке
				result.append(' '); // ставим пробел после числа
				while (operations.size() != 0 && !operations.back().isEqual("(") &&
					(source[i] == '+' || source[i] == '-' || operations.back().isEqual("+") || operations.back().isEqual("-"))) {
					// пока стек не пуст и последняя в стеке не "(" и последняя операция в стеке не больше текущей по приоритету
					result.append(operations.pop() + " "); //записываем операции из стека в результат
				}
				_String tempstring;
				tempstring.append(source[i]);
				operations.push(tempstring); // кладем операцию в стек
			}
		}
		if (source[i] == '(') { //если встретилась "("
			operations.push("("); // кладем "(" в стек
		}
		if (source[i] == ')') { //если встретилась ")"
			result.append(' '); // ставим пробел после числа
			while (!operations.back().isEqual("(")) { // пока не встретилась "("
				result.append(operations.pop() + " "); //записываем операции из стека в результат
			}
			operations.pop(); // удаляем "(" из стека
		}
		i++;
	}
	while (operations.size() != 0) { //перекладываем оставшиеся операции из стека в результат
		result.append(operations.pop() + " ");
	}


	//выводим результат
	cout << result.getValue() <<endl;
	return 0;
}
/*
Проверка на корректность скобок:
	при встреченной ) нужно удалить из стека операций (, иначе ошибка
	при встреченной ( запушиваем ее в стек
	если дошли до конца и стек пуст, то все верно, иначе ошибка


Найденные баги:
	- метод append вызывает исключение, когда печатается больше чем первая цифра числа
	- деструктор вызывает исключение после запушивания операции в стек
*/