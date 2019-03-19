/*Объявить динамический массив. Длину массива вводить с клавиатуры.
Заполнить массив случайными числами и найти максимальную по длине
возрастающую последовательность подряд идущих элементов массива.
К элементам массива не обращаться через квадратные скобки.
Использовать указатели.*/
#include<iostream>
using namespace std;
int main(){
	int n; //длина массива
	cin>>n;
	int count=1, last, maxcount=0;
	bool flag=false; //обозначает был ли первый элемент считан
	int *mas = new int[n];
	for(int i=0;i<n;++i){
		//заполняем массив и сразу ищем максимальную цепочку
		cin>>*mas;
		if(!flag){
			//если вводится первый элемент
			flag = true;
			last = *mas;
			mas++;
			continue;						
		}
		if(*mas>last){
			//если цепочка продолжается
			count += 1;
			last = *mas;
		}
		else{
			//если не продолжается
			if(maxcount<count) maxcount = count;
			count = 1;
			last = *mas;
		}
		mas++;
	}
	if(maxcount<count) maxcount = count;
	cout<<maxcount;
return 0;}
