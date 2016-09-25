#include <string>
#include <iostream>
// #include <ostream>
#include <stack>

using namespace std;
int main(){
	string str;
	stack <char> s;
//	basic_ostream stack <char> s;
	cout<<"input string :";
	cin>>str;

	for (int i = 0; i < str.size(); ++i){
		// cout<<str[i]<<"\n";
		s.push(str[i]);
		cout<<"top of the stack :"<<s.top()<<endl;
		cout<<"bottom of the stack :"<<s.top()<<endl;
	}
	// cout<<"hasil stack:"<<std::stack s;
	cout<<"\n";
	return 0;
}

