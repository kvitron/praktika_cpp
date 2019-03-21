#include<cstdlib> //содержит rand() и srand()
#include<fstream>
#include <ctime> // содержит time()
using namespace std;
int main(){
	int *chisla = new int [100];
	srand(time(NULL)); //передает системное время компилятору, чтобы
	//генерировать каждый раз случайное число
	int max=0, count=0;
	ofstream fout("out.txt");
	
	for(int i=0; i<100; ++i){
		*chisla=10+rand()%89;
		if (*chisla>max) {
			max=*chisla;
			count=1;
		}
		else if (*chisla==max)
			count++;
		fout<<*chisla<<' ';
		chisla++;
	}
	
	fout<<endl<<max<<' '<<count;
return 0;}
