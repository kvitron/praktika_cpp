/*Дан двумерный динамический массив. Создать два новых массива
на основании исходного. Первый отсортировать по возрастанию
суммы элементов строк. Второй отсортировать по убыванию суммы
элементов столбцов. К элементам массива не обращаться через
квадратные скобки. Использовать указатели.*/
#include<iostream>
using namespace std;
int main(){
	int x,y;
	cin>>x>>y;
	//создаем новую матрицу
	int **matr = new int *[x];
	for(int i=0; i<y; ++i) matr[i] = new int[y];
	//заполняем матрицу
	for(int i=0; i<y; ++i)
		for(int j=0; j<x; ++j)
			cin>>*(*(matr+i)+j);
			//*(*(matr+i)+j) обращение к элементу матрицы
	cout<<endl;
			
	//создаем первую новую матрицу на основании исходной
	int **matr1 = new int *[x];
	for(int i=0; i<y; ++i) matr1[i] = new int[y];
	//заполняем
	for(int i=0; i<y; ++i)
		for(int j=0; j<x; ++j)
			*(*(matr1+i)+j) = *(*(matr+i)+j);
	//сортируем пузырьком
	for(int k=0; k<y-1; ++k)
		for(int i=0; i<y-1; ++i){
			int sum1=0, sum2=0;
			//считаем суммы двух строк
			for(int j=0; j<x; ++j){
				sum1+=*(*(matr1+i)+j);//эта строка
				sum2+=*(*(matr1+i+1)+j);//следующая строка
			}
			//меняем местами строки
			if(sum1>sum2){
				for(int j=0; j<x; ++j)
					swap(*(*(matr1+i)+j), *(*(matr1+i+1)+j));
			}
		}
	
	//создаем вторую новую матрицу на основании исходной
	int **matr2 = new int *[x];
	for(int i=0; i<y; ++i) matr2[i] = new int[y];
	//заполняем
	for(int i=0; i<y; ++i)
		for(int j=0; j<x; ++j)
			*(*(matr2+i)+j) = *(*(matr+i)+j);
	//сортируем пузырьком
	for(int k=0; k<x-1; ++k)
		for(int j=0; j<x-1; ++j){
			int sum1=0, sum2=0;
			//считаем суммы двух столбцов
			for(int i=0; i<y; ++i){
				sum1+=*(*(matr2+i)+j);//этот столбец
				sum2+=*(*(matr2+i)+j+1);//следующий столбец
			}
			//меняем местами столбцы
			if(sum1<sum2){
				for(int i=0; i<y; ++i)
					swap(*(*(matr2+i)+j), *(*(matr2+i)+j+1));
			}
		}
	
	//выводим матрицы
	for(int i=0; i<y; ++i){
		for(int j=0; j<x; ++j)
			cout<<*(*(matr1+i)+j)<<' ';
		cout<<endl;
	}
	cout<<endl;
	for(int i=0; i<y; ++i){
		for(int j=0; j<x; ++j)
			cout<<*(*(matr2+i)+j)<<' ';
		cout<<endl;
	}
	
	delete [] matr;
	delete [] matr1;
	delete [] matr2;
return 0;}
