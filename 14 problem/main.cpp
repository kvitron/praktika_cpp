#include <iostream>
#include "_String.h"
#include "_String Stack.h" //���� �����
using namespace  std;

int main() {
	//��������� �������� ������
	char *tempstring = new char[1000];
	cin.get(tempstring, 999);
	_String source(tempstring);
	delete[] tempstring;

	
	//��������� ������������ ����������� ������
	Stack operations; //����, �������� �������������� ��������
	int i = 0;
	while (source[i] != 0) { // �������� �� ������
		if (source[i] == '(') { // ��� ������������� ������
			operations.push("(");
			cout << "( was pushed" << endl;
		}
		if (source[i] == ')') { // ��� ������������� ������
			if (operations.back().isEqual("(")) { // ���� ��������� ������ � ����� �������������
				operations.pop();
			}
			else { // ��������� �������� � ����� �� �������� ������������� �������
				cout << ") ne vstretila ( v steke" << endl;
				return 0;
			}
		}
		i++;
	}
	if (operations.size() != 0) { //���������� ")" ������ ��������� "("
		cout<<"count ) < count (" << endl;
		return 0;
	}
	else { // ���������� ����������� ������
		cout << "correct bracketing " << endl;
	}


	//��������� �������� ������ � ��� �������� �������� ������
	i = 0; // ������ �������� ������
	_String result;
	while (source[i] != 0) { //������ �� �������� ������
		if (source[i] >= '0' && source[i] <= '9') { //���� ����������� �����
			result.append(source[i]); //���������� �
		}
		if (source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '/') { //���� ����������� ��������
			if (operations.size() == 0 || operations.back().isEqual("(")) { //���� ���� ���� ��� ��������� �������� "("
				_String tempstring;
				tempstring.append(source[i]);
				operations.push(tempstring); // ������ �������� � ����
			}
			if ((source[i] == '*' || source[i] == '/') && (operations.back().isEqual("+") || operations.back().isEqual("-"))) {
				// ���� ����� �������� ����� ������� ���������, ��� ������� �������� � �����
				_String tempstring;
				tempstring.append(source[i]);
				operations.push(tempstring); // ������ �������� � ����
			}
			else { //����� �������� ����� ������� ��� ������ ���������, ��� ������� �������� � �����
				result.append(' '); // ������ ������ ����� �����
				while (operations.size() != 0 && !operations.back().isEqual("(") &&
					(source[i] == '+' || source[i] == '-' || operations.back().isEqual("+") || operations.back().isEqual("-"))) {
					// ���� ���� �� ���� � ��������� � ����� �� "(" � ��������� �������� � ����� �� ������ ������� �� ����������
					result.append(operations.pop() + " "); //���������� �������� �� ����� � ���������
				}
				_String tempstring;
				tempstring.append(source[i]);
				operations.push(tempstring); // ������ �������� � ����
			}
		}
		if (source[i] == '(') { //���� ����������� "("
			operations.push("("); // ������ "(" � ����
		}
		if (source[i] == ')') { //���� ����������� ")"
			result.append(' '); // ������ ������ ����� �����
			while (!operations.back().isEqual("(")) { // ���� �� ����������� "("
				result.append(operations.pop() + " "); //���������� �������� �� ����� � ���������
			}
			operations.pop(); // ������� "(" �� �����
		}
		i++;
	}
	while (operations.size() != 0) { //������������� ���������� �������� �� ����� � ���������
		result.append(operations.pop() + " ");
	}


	//������� ���������
	cout << result.getValue() <<endl;
	return 0;
}
/*
�������� �� ������������ ������:
	��� ����������� ) ����� ������� �� ����� �������� (, ����� ������
	��� ����������� ( ���������� �� � ����
	���� ����� �� ����� � ���� ����, �� ��� �����, ����� ������


��������� ����:
	- ����� append �������� ����������, ����� ���������� ������ ��� ������ ����� �����
	- ���������� �������� ���������� ����� ����������� �������� � ����
*/