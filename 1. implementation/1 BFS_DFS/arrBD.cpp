//adjacency matrix (array) 
#include <iostream>
#include <conio.h>
#define maxNode 10

using namespace std;
typedef struct(
	
)

void bfsProses(){
	cout<<"masuk bfs"<<endl;
}
	
void dfsProses(){
	cout<<"masuk dfs"<<endl;
//	cout<<maxJmlEdge;
}

int matriks[maxNode][maxNode];
void kalkulasi(int mje){
	int jmlEdge;
	cout<<mje<<endl;
	cout<<"input jumlah edges :";
	cin>>jmlEdge;
	
	int item;
	for (int x = 0; x < jmlEdge; x++) {	//row
		cout<< "edge ke-"<<x;
		
		for (int y = 0; y < jmlEdge; y++) {	//col
			cout<<">item ["<<x<<"]["<<y<<"] : "<<endl;

			for(int k=1;k<=2;k++){
				int val;
				cout<<">> "<<(k==1?"x":"y")<<" =";
				cin>>val;
				matriks[x][y]=val;
			}
//			cin>>item;
//			matriks
//			cout<<endl;
//		    cin<< matriks[x][y] = 0;
		}
	}
}

int jmlNode;
void pilihMenu(int mn){
	int maxJmlEdge;
	cout<<"jumlah node (max 10) : ";
	cin>>jmlNode;
	
	if(mn==1){ //undirected
		cout<<"masuk kalkulasi undirected";
		maxJmlEdge = (jmlNode * (jmlNode - 1)) / 2;
		kalkulasi(maxJmlEdge);
	}else{ // directed
		cout<<"masuk kalkulasi directed";
		maxJmlEdge = jmlNode * (jmlNode- 1);
		kalkulasi(maxJmlEdge);
	}
}
int main(){
	int pilih;
	cout<<"Pilih menu :"<<endl;
	cout<<"1. Undirected Graph"<<endl;
	cout<<"2. Directed Graph"<<endl;
	cin>>pilih;
	
	switch(pilih){
		case 1:
	        cout << ">> unDirected Graph" << endl;
//		    maxJmlEdge = (jmlNode * (jmlNode - 1)) / 2;
			pilihMenu(pilih);			        
		break;
		case 2:
	        cout << ">> Directed Graph" << endl;
//	        maxJmlEdge = jmlNode * (jmlNode- 1);
	        pilihMenu(pilih);
	    break;
	}
}
    
    
