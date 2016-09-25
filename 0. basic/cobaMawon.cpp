#include <iostream>
#include <map>
#include <string>
#define maxVal 10
#define defaultVal 9999
 
using namespace std;
//void listKota(string arr[], int nArr){
//	for(int i=0;i<nArr;i++){
//		cout<<"kota ke -"<<i+1<<" : "<<arr[i]<<endl;
//	}
//}
int kotaArr[maxVal][maxVal];

//cetak matrix 
void cetakMatrix(int jumKota){
//	string output="";
//	for(int i=0;i<jumKota;i++){
//		for(int j=0;j<jumKota;j++){
//			output+=kotaArr[i][j];
//			output+="\t";
//		}
//	}cout<<output;
	cout<<"masuk cetak";
}


//map<int,string>; 
void initMatrix(int jumKota){
	for(int i=0;i<jumKota;i++){
		for(int j=0;j<jumKota;j++){
			kotaArr[i][j]=0;
		}
	}cetakMatrix(jumKota);
}

int main(){
	int nKota,nRute;
	string kotaArr[maxVal];//={"aa","bb","cc"};
////
//	cout<<endl<<"jumlah element array :"<<sizeof(bilArr);
	int i =0; 
	bool lanjut=true;
//	do{
		// input total kota
		cout<<"jumlah kota : ";
		cin>>nKota;
		
		// input label kota 
		for(int i=0;i<nKota;i++){
			string nmKota;
			cout<<"kota ke-"<<i+1<<" :";cin>>nmKota;
			kotaArr[i]=nmKota;
		}
		//		init matrik kota 
		initMatrix(nKota);
		
//		cetakMatrix(nKota);
		//input rute 		
		cout<<"jumlah rute:";cin>>nRute;
		for(i<0;i<nRute;i++){
			string kotaAsal,kotaTujuan;
			cout<<">asal :";cin>>kotaAsal;
			cout<<endl;
		}

		// konfirmasi untuk lanjut 
//		string opt;
//		cout<<"keluar ?(y/n) :";
//		cin>>opt;
//		if(opt=="y"||opt=="Y") lanjut=false;
//	}while(lanjut);
		
//	int nArr=kotaArr.length;
//	cout<<endl<<"jumlah data  :"<<sizeof(kotaArr);
//	cout<<endl<<"isi array  :"<<kotaArr[0];
//	listKota(kotaArr,sizeof(kotaArr));
	system("pause");	
	return 0;
}

