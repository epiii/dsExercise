#include <iostream> 
int main(){
	int x,y,z;
	cout<<"masukkan bil:";
	cin>>x>>y>>z;

	bool r1;
	bool r2;
	bool r3;
	bool r4;
	bool r5;

// c libih besar
	if(x<y && y<z){
		cout<<"a<b<c:true";
		cout<<endl;
	}else{
		r1=false;
		cout<<"a<b<c:false";
		cout<<endl;
	}

// positif
	if(x>0 && y>0 && z>0 ) {
		cout<<"a,b,c>0:true";
		cout<<endl;
	}else{
		r2=false;
		cout<<"a,b,c>0:false";
		cout<<endl;
	} 

// kali	
	if(x*y*z==y) {
		cout<<"a*b*c=y:true";
		cout<<endl;
	}
	else{
		r3=false;
		cout<<"a*b*c=y:false";
		cout<<endl;
	}

//tambah 
	if(x+y+z==x) {
		cout<<"a+b+c=x:true";
		cout<<endl;
	}
	else{
		r3=false;
		cout<<"a+b+c=x:false";
		cout<<endl;
	} 
	return 0;
}

/*
R1	a<b<c
R2	a,b,c>0
R3	a+b+c=x
R4	a*b*c=y 
R5 a^2 +b^2+c^2=z

input x y z
outut a b c atau tidak ada jawaban

in: 1 1 1
out : tidak ada

in : 6 6 14
out : 1 2 3

in : 15 80 93
out: 2 5 8

*/

