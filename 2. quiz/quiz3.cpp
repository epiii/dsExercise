#include <iostream> 

int main(){
	int bil;
	cout<<"masukkan bil:";
	cin>>bil;

	int x=0;
	for (int i = 0; i<=bil; i++){
		for (int j = 0; j<i; j++){
			if(x==10) {
				x=0;
				cout<<x <<" ";
			}else cout<<x<<" ";
			x++;
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