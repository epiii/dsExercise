#include <iostream>
#include <stack>
#include <string.h>

int x;
bool flag;
char bracket[1000];

using namespace std;

int main()
{
    cout << "Masukkan Berapa kali Percobaan ?" << endl;
    scanf("%i", &x);

    while(x--){
        stack <char> stk;
        scanf("%s", &bracket);
        flag = true;
        for(int i = 0; i < strlen(bracket) && flag; i++){
            if(bracket[i] == '('){
                stk.push('(');
            }else{
                if(stk.empty())
                    flag = false;
                else
                    stk.pop();
            }
        }
        if (flag && stk.empty())
            cout << "Ya\n";
        else
            cout << "Tidak\n";
    }
    system("pause");
    return 0;
}
