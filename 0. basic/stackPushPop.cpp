#include<stdio.h>
#include<conio.h>
#include<iostream>
//http://suputradwipratama274.blogspot.co.id/2015/06/v-behaviorurldefaultvmlo.html

struct stack{
	int data[5];
	int atas;
};
stack tumpuk;

int main(){
	system("cls");
//	clrscr();
	int pilihan, baru, i;

	tumpuk.atas=-1;
	do{
		system("cls");
//		clrscr();
		cout<<"1. PUSH DATA"<<endl;
		cout<<"2. POP DATA"<<endl;
		cout<<"3. PRINT DATA"<<endl<<endl;
		cout<<"MASUKKAN PILIHAN : ";
		cin>>pilihan;

		switch (pilihan){
           	case 1 :
	           	if(tumpuk.atas==5-1){
	                cout<<"TUMPUKAN PENUH";
	               	getch();
	            }else{
					cout<<"MASUKKAN DATA : ";
					cin>>baru;
					tumpuk.atas++;
					tumpuk.data[tumpuk.atas]=baru;
				}
            break;

         	case 2 :
	           	if(tumpuk.atas==-1){
	                cout<<"TUMPUKAN KOSONG";
					getch();
	            }else{
	               	cout<<"DATA YANG AKAN DI POP = "<<tumpuk.data[tumpuk.atas]<<endl;
	                tumpuk.atas--;
	               	getch();
	            }
            break;

         	case 3 :
	           	if(tumpuk.atas==-1){
	                cout<<"TUMPUKAN KOSONG";
	               	getch();
	            }else{
	                cout<<"DATA - "<<endl;
	               	for(i=tumpuk.atas; i>=0; i--){
	               		cout<<tumpuk.data[i]<<ends;
	               	}
	               	getch();
	            }
            break;

		default :
           cout<<"TIDAK ADA DALAM PILIHAN";
		break;
      	}	
   	
	   	}
   		while((pilihan>=1) && (pilihan<=3));
		getch();
	return 0;
}

