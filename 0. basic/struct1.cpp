#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
 
using namespace std;
 
//Deklarasi struct
struct data_mahasiswa
{
    long int nim;
    char nama[100];
    char fakultas[100];
};
 
//Deklarasi variabel struct
data_mahasiswa mahasiswa1, mahasiswa2;
 
int main()
{    
    //Input struct data mahasiswa
    cout<<" Data Mahasiswa Pertama\n";
    cout<<"-----------------------\n";
    cout<<" NIM      : "; cin>>mahasiswa1.nim;
    cout<<" Nama     : "; fflush(stdin); gets(mahasiswa1.nama);
    cout<<" Fakultas : "; fflush(stdin); gets(mahasiswa1.fakultas);
    cout<<"\n\n";
    cout<<" Data Mahasiswa Kedua\n";
    cout<<"-----------------------\n";
    cout<<" NIM      : "; cin>>mahasiswa2.nim;
    cout<<" Nama     : "; fflush(stdin); gets(mahasiswa2.nama);
    cout<<" Fakultas : "; fflush(stdin); gets(mahasiswa2.fakultas);
    cout<<"\n\n";
 
    //Output struct data mahasiswa
    cout<<" Data Mahasiswa Pertama\n";
    cout<<"-----------------------\n";
    cout<<" NIM      : "<<mahasiswa1.nim<<endl;
    cout<<" Nama     : "<<mahasiswa1.nama<<endl;
    cout<<" Fakultas : "<<mahasiswa1.fakultas<<endl;
    cout<<"\n\n";
    cout<<" Data Mahasiswa Kedua\n";
    cout<<"----------------------\n";
    cout<<" NIM      : "<<mahasiswa2.nim<<endl;
    cout<<" Nama     : "<<mahasiswa2.nama<<endl;
    cout<<" Fakultas : "<<mahasiswa2.fakultas<<endl;
    cout<<"\n\n";
    getch();
}
