#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<stdlib.h>
#define n 4

using namespace std;
int q[n], f, r, x;

void awal(){
  f=0;
  r=-1;
}

void insert(){
  if (r<n-1){
    r=r+1;
    q[r]=x;
  }else{
     cout<<"ANTRIAN PENUH";
  }  
}

void read(){
  if(f<r+1){
	for(int ii=0;ii<=r;ii++){
	  cout<<"item : "<<q[ii]<<endl;
	}
  }else{
     cout<<"ANTRIAN KOSONG";
  }  
}

void deleteq(){
  //hanya menampilkan satu data terdepan
  //pakai while kalau mau menampilkan semua data antrian
  if(f<r+1){
    x=q[f];
    f=f+1;
    cout<<x;
    if((f==r+1) && (r==n-1)){
      awal();
    }
  }else{
     cout<<"ANTRIAN KOSONG";
  }
}

int main(){
  int pilih;
  awal();

  atas:
   cout<<endl<<"1. INSERT DATA"<<endl;
   cout<<"2. DELETE DATA"<<endl;
   cout<<"3. EXIT DATA"<<endl;
   cout<<"4. READ DATA"<<endl;
   cout<<"MASUKKAN PILIHAN ANDA : ";
   cin>>pilih;

  switch(pilih){
    case 1 :
      if(r<n-1){
        cout<<"MASUKKAN BILANGAN : ";
        cin>>x;
        insert();
      }else{
        cout<<"ANTRIAN PENUH";
      }
      goto atas;
    break;
    case 2 :
      deleteq();
      goto atas;
    break;
    case 3 :
      exit;
    break;
	case 4 :
		read();
    break;
    default :
      cout<<"MASUKKAN ANGKA ANTARA 1 SAMPAI 3";
      goto atas;
    break;
  }
  getch();
//  system("pause");
}
//http://suputradwipratama274.blogspot.co.id/2015/06/penjelasan-tentang-queue-contoh-program.html
