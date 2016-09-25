#include <iostream>
#include <map>
#include <string>
#define maxVal 10
#define defaultVal 9999
 
using namespace std;
double kotaArr[maxVal][maxVal];

//struct node
typedef struct {
	string nama;
	bool pernahLewat;
}kotaNode;

//struct edge
typedef struct {
	int parentKota;
	double jarak;
}kotaRute;

void adaRute(){
	
}
//-----
	void tempParent(kotaRute *parentKota, kotaNode *pernahLewat){
		for(){
			
		}				
	}
	//
	//void getMin(kotaRute *parentKota,kotaNode *pernahLewat){
	//	
	//}
//-----

void initMatrix(int jumKota){
	for(int i=0;i<jumKota;i++){
		for(int j=0;j<jumKota;j++){
			kotaArr[i][j]=defaultVal;
		}
	}
}

//cetak adjacency matrix
void cetakMatrix(int jumKota){
	cout<<endl;
	for(int i=0;i<jumKota;i++){
		for(int j=0;j<jumKota;j++){
			cout<<kotaArr[i][j]<<"\t";
		}cout<<"\n";
	}
}

int main(){
	int nKota,nRute;
	cout<<"jumlah kota : ";
	cin>>nKota;
	
	int x1, x2;
	double w;

	cout<<"------ input rute ------"<<endl;	
	for(int i=0; i<maxVal; i++){
		cout<<"> kota ke-"<<i+1<<":";
		cin>>x1>>x2>>w;
		
		// lanjut / tidak
		if(x1==0 && x2==0 && w==0.0)break;
		else kotaArr[x1][x2]=w;
	}
	cetakMatrix(nKota);

	//input kota nama	
	kotaNode kotaArr[nKota];
	cout<<"------ input label ------"<<endl;	
	for(int i=0;i<nKota;i++){
		string kotaNama;
		cout<<"input nama ke-"<<i+1<<":";
		cin>>kotaNama;
		
		//set kota (struct node)
		kotaArr[i].nama=kotaNama;
		kotaArr[i].pernahLewat=false;
	}return 0;
	
	int kotaAsal,kotaTujuan;
	cout<<"masukkan kota asal :";cin>>kotaAsal<<endl;
	cout<<"masukkan kota tujuan :";cin>>kotaAsal<<endl;

			
//	tempParent();	
}
