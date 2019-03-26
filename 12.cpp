/*–еализовать класс _String, предоставл€ющий функционал работы со строками.*/
#include <iostream>
using namespace std;
class _String{
	char *value;
	int stringLength = -1;
public:
	_String() {
	}
	_String(char *val) {
	}
	_String(const char *val) {
	}
	~_String() {
	}
	_String(const _String &element) {
	}
	int length(){ //возвращает длину строки
		return stringLength + 1;
	}
	void append(_String str){
	}
	void append(char *str){
	}
	void append(const char *str){
	}
	void setValue(char *val){
	}
	void setValue(const char *val){ //установить константное значение
		
	}
	void setValue(int val){
	}
	void setValue(double val, int precision = 10){
	}
	_String operator = (const _String &element){
	}
	_String operator + (const _String &right){
	}
	int pos(const char *str){
	}
	void remove(int position, int length){
	}
	void insert(int position, int length, const char *source){
	}
	void insert(int position, int length, char *source){
	}
	void insert(int position, int length, _String source){
	}
	_String copy(int position, int length){
	}
	char operator [] (int index){
	}
	int parseInt(int &error){
	}
	float parseFloat(int &error){
	}
	bool isEqual(char *str){
	}
	bool isEqual(const char *str){
	}
};
int main(){
	_String s;
	return 0;
}
