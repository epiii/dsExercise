#include <iostream>
using namespace std;
int main(){
	int bil,bilArr[1];
	int i =0; 
	bool lanjut=true;
	do{
		cout<<"input : " && 
		cin>>bil;
		bilArr[i]=bil;
		
		i++;
		string opt;
		cout<<"keluar ?(y/n) :";
		cin>>opt;
		if(opt=="y"||opt=="Y") lanjut=false;
	}while(lanjut);
	cout<<endl<<"hasil inputan :"<<endl;
	
	for(int i=0;i<sizeof(bilArr);i++){
		cout<<"elemen ke -"<<i+1<<" : "<<bilArr[i]<<endl;
	}
	return 0;
}
