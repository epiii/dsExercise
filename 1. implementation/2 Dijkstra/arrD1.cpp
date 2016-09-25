#include <iostream>
// #include <cstdio>
// #include <limits>

using namespace std;
typedef struct{
	char namaStc[20];
	int terpilihStc;
} kotaStc ;


int main (){
 	int nNode;
// 	jumlah node
	cout << "input jumlah node : ";
	cin >> nNode;
	char namaArr[20];
	kotaStc kotaArr[100];
	for(int i=0;i<nNode; i++){
		cout<<"Nama kota ke-"<<i+1<<endl;
		cin>>namaArr;
		kotaArr[i].namaStc=namaArr;
	}

	
	cout << "jumlah node :" << nNode;
    return 0;
}
