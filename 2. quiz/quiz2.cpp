#include <iostream> 

int main(){
	int bil;
	cout<<"masukkan bil:";
	cin>>bil;

	for(int i=1;i<=(2*bil-1);i++ ){ // 1
		if(i<=bil){
			for(int j=1;j<=bil-i;j++ ){ // 
				cout<<"-";
			}
			for(int k=1;k<=i-1;k++ ){ //cetak *
				cout<<"*-"; 
			}cout<<"*"<<endl;	
		}else{
			for(int a=bil-i;a>1;a--){
				cout<<"*-";
			}for(int b=i-1;b>1;b--){
				cout<<"-";
			}cout<<endl;
		}
	}return 0;
}

/*
  *
 * *
  *
--*
-*-*
*---*
-*-*
--*

	row
	1=1
	2=3
	3=5
	
	col
	1=1
	2=3
	3=5

*/