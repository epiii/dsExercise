#include <iostream>

int main(){
    using namespace std;

    const int maxchar = 5;
    string nationname;

    cout << "What is the name of your nation?" << endl;
	cin >> nationname;

    if (nationname.size() > maxchar){
       cout << "The input is too long." << endl;
       return 1;
    }
}
