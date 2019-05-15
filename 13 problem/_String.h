#ifndef _STRING_H
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

	class _String {
	protected:
		char *value;
		int stringLength = -1;
		//static int objectCount;  ////////////пример переменной, которая работает для всего класса, а не для конкретного объекта
	public:
		//конструктор по умолчанию
		_String();
		
		//из массива char
		_String(char *val);
		
		//из константной строки
		_String(const char *val);

		//деструктор
		~_String();

		//из другого объекта _Srting
		_String(const _String &element);

		//возвращает длину строки
		int length();

		//добавляем объект _String
		void append(_String str);

		//добавляем массив char
		void append(char *str);

		//добавляем символ char
		void append(char symbol);

		//добавляем константную строку
		void append(const char *str);

		//установить значение массива char
		void setValue(char *val);

		//установить константное значение
		void setValue(const char *val);

		//установить значение переконвертированное из int
		void setValue(int val);

		//установить значение переконвертированное из double c точностью 10 знаков после запятой по умолчанию
		void setValue(double val, int precision = 10);

		//возвращает дублированный объект _String исходного объекта
		_String operator = (const _String &element);

		//возвращает новый объект _String, полученный в результате конкатенации исходных
		_String operator + (const _String &right);

		//первое вхождение подстроки. вернет -1 если не найдено
		int pos(const char *str);

		//удалить подстроку из строки
		void remove(int position, int length);

		//вставка константной подстроки в исходную строку
		void insert(int position, const char *source);

		//вставка подстроки в исходную строку
		void insert(int position, char *source);

		//вставка подстроки из другого объекта _String в строку
		void insert(int position, _String source);

		//возвращает динмическую подстроку
		_String copy(int position, int length);

		//возвращает символ с индексом index
		char operator [] (int index);

		//конвертация в int. error вернет индекс первого символа, который не относится к числу. иначе -1
		int parseInt(int &error);

		//конвертация во float. error вернет индекс первого символа, который не относится к числу. иначе -1
		float parseFloat(int &error);

		//сравнение со строкой на одинаковость
		bool isEqual(char *str);

		//сравнение с констнтной строкой на одинаковость
		bool isEqual(const char *str);

		//возвращает значение строку
		const char *getValue();
	}; 
#endif // !_STRING_H
