#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef pair<int, int> vertex;
int main(){
	
//	queue<int> q;
//	priority_queue<int> q;
//  priority_queue<int, vector<int>, greater<int> > q;
 	priority_queue<vertex, vector<vertex>, greater<vertex> > q;
 
	
	q.push(new vertex(8,10));
	q.push(2);
	q.push(10);
//	q.push(8);
//	q.push(2);
//	q.push(10);
	while(!q.empty()){
		cout<<q.top()<<" ";
		q.pop();
	}
	return 0;
}
 
  
