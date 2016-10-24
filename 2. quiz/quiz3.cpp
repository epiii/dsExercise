#include <iostream> 
int main(){
	int bil;
	cout<<"masukkan bil:";
	cin>>bil;
	int counter=0;
	for (int i = 0; i<=bil; i++){
		for (int j = 0; j<i+1; j++){
			if(j==10) cout<<9;
			else cout<<j;
		}cout<<endl;
	}
	return 0;
}

/*
input = 5
output :
0
1 2
3 4 5
6 7 8 9
0 1 2 3 4
*/