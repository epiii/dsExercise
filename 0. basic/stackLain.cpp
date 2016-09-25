#include "iostream"
#include "conio.h"
#define n 10

int I[n], z, atas;
void push (int a){
	atas=atas+1;
	I[atas]=a;
}

int pop(){
	int a;
	a=I[atas];
	atas=atas-1;
	return a;
}

void main()
{
	cout << "masukkan isi stack :\n";
	atas=-1;
	while(atas<=n-1){
		cout << "item : " <<n;
		cin>>z;
		push(z);
		// z=pop();
		// cout
	}cout<<"isi stack : "<<endl;
	while(atas>=0){
		z=pop();
		cout<<z<<" ";
	}
	getch();
	// return 0;
}
