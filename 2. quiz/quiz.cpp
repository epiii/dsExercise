#include <iostream> 

int main(){
	int bil;
	cout<<"masukkan bil:";
	cin>>bil;

	for (int i = 0; i <=bil; ++i){
		for (int j = 0; j<=i; ++j){
			cout<<"* ";
		}cout<<endl;
	}
	return 0;
}