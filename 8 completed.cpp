#include <iostream>
using namespace std;
const int MAX_SIZE = 1000;
struct stack{
	int m_size;
	int m_elems[MAX_SIZE];
	//stack();
	//~stack();
	void push(int d){
		m_size++;
		m_elems[m_size] = d;
	}
	int pop(){
		m_size--;
		return m_elems[m_size + 1];
	}
	int back(){
		return m_elems[m_size];
	}
	int size(){
		return m_size;
	}
	void clear(){
		m_size = 0;
	}
};
int main(){
	stack s;
	s.m_size = 0;
	string command;
	do{
		cin >> command;
		if (command == "push"){
			int n;
			cin >> n;
			s.push(n);
			cout << "ok" << endl;
		}
		else if (command == "pop"){
			if (s.m_size == 0) cout << "error" << endl;
			else cout << s.pop() << endl;
		}
		else if (command == "back"){
			if (s.m_size == 0) cout << "error" << endl;
			else cout << s.back() << endl;
		}
		else if (command == "size"){
			cout << s.size() << endl;
		}
		else if (command == "clear"){
			s.clear();
			cout << "ok" << endl;
		}
	} while (command != "exit");
	cout << "bye";
	return 0;
}
