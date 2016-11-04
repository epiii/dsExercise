#include <iostream> 

int main(){
	int bil;
	cout<<"masukkan bil:";
	cin>>bil;
	// int xx=(2*bil-1);
	// cout<<xx;
	// return 0;
	for(int i=1;i<=(2*bil-1);i++ ){ // 1
		int b,s;
		if(i<=bil){ // naik 
			b=bil-(i-1);
			s=bil+(i-1);
		}else{
			b=bil-(i-1);
			s=bil+(i-1);
		}
			
		// else{
		// 	b=
		// }

		for (int j = 0; j < bil; ++j){
			if(j==b||j==s) cout<<"*";
			else cout<<"-";
		}cout<<endl;
		// 	for(int j=1;j<=bil-i;j++ ){ // 
		// 		cout<<" ";
		// 	}
		// 	for(int k=1;k<=i-1;k++ ){ //cetak *
		// 		cout<<"* "; 
		// 	}cout<<"*"<<endl;	
		// }else{ // turun
		// 	for(int a=i-bil;a>=1;a--){ // -
		// 		cout<<" ";
		// 	// }for(int b=i-1;b>=1;b--){
		// 	}for(int b=i-1;b>=1;b--){ //*
		// 		cout<<"*";
		// 	}cout<<endl;
		// }
	}return 0;
}

/*
  *
 * *
  *
--*--
-*-*-
*---*
-*-*-
--*--

	row
	1=1
	2=3
	3=5
	
	col
	1=1
	2=3
	3=5

*/
