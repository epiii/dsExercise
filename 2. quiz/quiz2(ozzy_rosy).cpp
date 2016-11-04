#include <iostream>
using namespace std;

int main(){
    int angka;
    int a,n,c;
    cout<<"masukkan angka :";
    cin >> angka;

    int angka2 = ((2*angka)-1);
    a=1;
    for (int i=1; i<=angka2; i++){
        if (i<=angka){
            n = angka-(i-1);
            c = angka + (i-1);
        } else {
            n = a+1;
            c = angka2-a;
            a++;
        }

        for (int j=1; j<=angka2; j++){
            if ((j==n)||(j==c)) {
                cout << "*";
            } else {
                cout << " ";
            }
        } cout << endl;
    } cout << endl;

    return 0;
}
