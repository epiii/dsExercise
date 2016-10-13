#include <iostream>
#include <map>
#include <string>
#define maxVal 10
#define defaultVal 9999
 
using namespace std;
double kotaArr[maxVal][maxVal];
int kotaAsal,kotaTujuan;
int nKota;

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

	//
	//void getMin(kotaRute *parentKota,kotaNode *pernahLewat){
	//	
	//}
//-----

//void initMatrix(int jumKota){
void initMatrix(){
	for(int i=0;i<nKota;i++){
		for(int j=0;j<nKota;j++){
			kotaArr[i][j]=defaultVal;
		}
	}
}

//cetak adjacency matrix
void cetakMatrix(int jumKota){
	cout<<endl<<"------- Adjacency Matrix -------\n";
	for(int i=0;i<jumKota;i++){
		for(int j=0;j<jumKota;j++){
			double jrk=kotaArr[i][j];
			if(jrk==9999)cout<<'~';
			else cout<<jrk;
			
			cout<<"\t";
			
		}cout<<"\n";
	}
}

// labeling kota
//void inputKota(int nKota){
void inputKota(){
	kotaNode kotaArr[nKota];
	cout<<endl<<"------ input nama kota ------"<<endl;	
	for(int i=0;i<nKota;i++){
		string kotaNama;
		cout<<"> kota ke-"<<i+1<<":";
		cin>>kotaNama;
		
		//set kota (struct node)
		kotaArr[i].nama=kotaNama;
		kotaArr[i].pernahLewat=false;
	}
}

//cari index dari berdasarkan nama kota x (ex: kota[0]=sby)
void getKotaIndex(string nmKota, int jmlKota){
	string kotaIndex;
	kotaNode kotaArr[jmlKota];
	for(int i=0; i<jmlKota;i++){
//		cout<<"-"<<kotaArr[i].nama;
		if(kotaArr[i].nama==nmKota){
			cout<<"ketemu";
			kotaIndex=i;	
			break;
		}else{
			cout<<"tdk ada";
			kotaIndex=99;	
		} 
	}
	cout<<"indexnya:"<<kotaIndex;
//	return kotaIndex;
}

//rute semua kota
void inputRute(){
	int kota1, kota2;
	double jarak;
	kotaNode kotaArr[nKota];
	
	cout<<endl<<"------ input rute ------"<<endl;	
	for(int i=0; i<maxVal; i++){
		cout<<"> rute ke-"<<i+1<<" (asal/tujuan/jarak):";
		cin>>kota1>>kota2>>jarak;
		
		// lanjut / tidak
		if(kota1==0 && kota2==0 && jarak==0.0)
			break;
		else 
			kotaArr[kota1][kota2]=jarak;
	}
}

//void tempParent(kotaRute *parentKota, kotaNode *pernahLewat){
//void jelajahKota(int kotaAsal,int kotaTujuan){
//    kotaNode kotaArr[nKota];
//	
//	//	set pernah lewat kota awal
//	kotaArr[kotaAsal].pernahLewat=true;
//	int kotaTerdekat;
//    cout<<kotaAsal<<" - "<<kotaTujuan;
//    for(int i=0;i<nKota;i++) {
// 		if(kotaArr[i].pernahLewat==false && (kotaArr[i].)){
//			
//		}
//    }return kotaTerdekat;
//}

void cekKotaTerdekat(){
//	for(int i=0;i<){
//		
//	}
}

int main(){
	cout<<"jumlah kota : ";
	cin>>nKota;
	initMatrix();
//	inputKota(nKota);
	inputKota();
	inputRute();	
	cetakMatrix(nKota);

//	string crKota;
//	cout<<"index kota:";cin>>crKota;
//	getKotaIndex(crKota,nKota);
	
	cout<<"masukkan kota asal :";
	cin>>kotaAsal;
	cout<<endl;
	cout<<"masukkan kota tujuan :";
	cin>>kotaTujuan;
	cout<<endl;
	
	jelajahKota(kotaAsal,kotaTujuan);
//	cout<<"kota asal :"<<kotaAsal;
	
	
//	cout<<"masukkan kota tujuan :";cin>>kotaAsal<<endl;
	return 0;
			
//	tempParent();	
}
