/*�������� ������������ ������. ����� ������� ������� � ����������.
��������� ������ ���������� ������� � ����� ������������ �� �����
������������ ������������������ ������ ������ ��������� �������.
� ��������� ������� �� ���������� ����� ���������� ������.
������������ ���������.*/
#include<iostream>
using namespace std;
int main(){
	int n; //����� �������
	cin>>n;
	int count=1, last, maxcount=0;
	bool flag=false; //���������� ��� �� ������ ������� ������
	int *mas = new int[n];
	for(int i=0;i<n;++i){
		//��������� ������ � ����� ���� ������������ �������
		cin>>*mas;
		if(!flag){
			//���� �������� ������ �������
			flag = true;
			last = *mas;
			mas++;
			continue;						
		}
		if(*mas>last){
			//���� ������� ������������
			count += 1;
			last = *mas;
		}
		else{
			//���� �� ������������
			if(maxcount<count) maxcount = count;
			count = 1;
			last = *mas;
		}
		mas++;
	}
	if(maxcount<count) maxcount = count;
	cout<<maxcount;
return 0;}
