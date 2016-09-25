#include <iostream>
using namespace std;

int main(){
	cout<<"array asli  : 5,3,4"<<endl;
	int bilArr[]={5,3,4}; // jumlah element harusnya ada : 3
	int n=sizeof(bilArr)/sizeof(bilArr[0]);
	cout<<"jumlah element array :"<<n<<endl; // 
	
//	cout<<"jumlah element array :"<<sizeOfArray(bilArr)<<endl; // 
//	cout<<"jumlah element array :"<<sizeof(bilArr)<<endl; // 
//	cout<<"jumlah element array :"<<sizeof(&bilArr)<<endl; // 
//	cout<<"jumlah element array :"<<sizeof(*bilArr)<<endl; // 
	return 0;
}

