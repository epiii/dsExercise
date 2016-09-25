#include <iostream>
#include <cstdio>
#include <limits>
using namespace std;
int main(){
 	int num;
	while (cout << "Masukan angka : " && !(cin >> num)){
	    cout << "Anda salah input, ulangi sampai benar " << endl;
	    cin.clear();
	    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}cout << "anda input angka " << num;
    return 0;
}
