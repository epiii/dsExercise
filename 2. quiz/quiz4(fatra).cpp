#include <iostream>
#include <math.h>

using namespace std;
int x,y,z;

void no4(){
    int tambah, kali, kuadrat;
    int ketemu=0;
    int a,b,c;

    for(int i=1;i<floor(x/3)-1;i++){
        a=i;//penting
        b=a+1;
        c=b+2;
        while(b<c-1){
            c=x-(a+b);
            tambah=a+b+c;
            kali=a*b*c;
            kuadrat=a*a+b*b+c*c;

            if(x==tambah && y==kali && z==kuadrat){
                cout<<a<<b<<c;
                ketemu=1;
                break;
            }b++;
        }if(ketemu==1) break;
    }if(ketemu==0) cout<<"Tidak ada";
}

int main(){
    cin>>x>>y>>z;
    no4();
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
