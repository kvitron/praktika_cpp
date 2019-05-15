#ifndef _STRING_H
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

	class _String {
	protected:
		char *value;
		int stringLength = -1;
		//static int objectCount;  ////////////������ ����������, ������� �������� ��� ����� ������, � �� ��� ����������� �������
	public:
		//����������� �� ���������
		_String();
		
		//�� ������� char
		_String(char *val);
		
		//�� ����������� ������
		_String(const char *val);

		//����������
		~_String();

		//�� ������� ������� _Srting
		_String(const _String &element);

		//���������� ����� ������
		int length();

		//��������� ������ _String
		void append(_String str);

		//��������� ������ char
		void append(char *str);

		//��������� ������ char
		void append(char symbol);

		//��������� ����������� ������
		void append(const char *str);

		//���������� �������� ������� char
		void setValue(char *val);

		//���������� ����������� ��������
		void setValue(const char *val);

		//���������� �������� �������������������� �� int
		void setValue(int val);

		//���������� �������� �������������������� �� double c ��������� 10 ������ ����� ������� �� ���������
		void setValue(double val, int precision = 10);

		//���������� ������������� ������ _String ��������� �������
		_String operator = (const _String &element);

		//���������� ����� ������ _String, ���������� � ���������� ������������ ��������
		_String operator + (const _String &right);

		//������ ��������� ���������. ������ -1 ���� �� �������
		int pos(const char *str);

		//������� ��������� �� ������
		void remove(int position, int length);

		//������� ����������� ��������� � �������� ������
		void insert(int position, const char *source);

		//������� ��������� � �������� ������
		void insert(int position, char *source);

		//������� ��������� �� ������� ������� _String � ������
		void insert(int position, _String source);

		//���������� ����������� ���������
		_String copy(int position, int length);

		//���������� ������ � �������� index
		char operator [] (int index);

		//����������� � int. error ������ ������ ������� �������, ������� �� ��������� � �����. ����� -1
		int parseInt(int &error);

		//����������� �� float. error ������ ������ ������� �������, ������� �� ��������� � �����. ����� -1
		float parseFloat(int &error);

		//��������� �� ������� �� ������������
		bool isEqual(char *str);

		//��������� � ���������� ������� �� ������������
		bool isEqual(const char *str);

		//���������� �������� ������
		const char *getValue();
	}; 
#endif // !_STRING_H
