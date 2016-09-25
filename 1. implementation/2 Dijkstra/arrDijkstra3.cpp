#include <iostream> 					
#include <vector>						
#define lli long long int
#define veci vector <int>
#define vecb vector <bool>

using namespace std;

int main(){
	lli n;
	lli src; 
	vector <veci> matrix;
	matrix.clear();
	veci dist;							
	vecb visit;							
	lli nxtNode;						
	lli min=999999999; //default untuk jarak infinite 
						
	dist.clear(); 
	visit.clear();
	
	cout<<endl<<"Jumlah node  :";//<<endl;
	cin>>n;
	
	cout<<"node asal  :";
	cin>>src;
	
//	loop untuk node
	for (int i=0; i<n; i++){
		dist.push_back(0);
		visit.push_back(false);
	}

	cout<<endl<<"input matrix (tabular) :"<<endl;
	
//	loop untk matrix 
	for (int y=0; y<n; y++){
		veci row;
		row.clear();
		for (int r=0; r<n; r++){
			lli d;
			cin>>d;
			row.push_back(d);
		}matrix.push_back(row);
	}
	
	dist = matrix.at(src);
	dist.at(src)=0;
	visit.at(src)=true;
	
	for (int i=0; i<n; i++){
		min=999999999;//default jarak infinite 
		
		for (int h=0; h<n; h++){
			if (min>=dist.at(h) && !visit.at(h)){
				min = dist.at(h);
				nxtNode = h;
			}
		}
		visit.at(nxtNode)=true;
		
		for (int s=0; s<n; s++){
			if (!visit.at(s)){
				if (min+matrix.at(nxtNode).at(s) < dist.at(s)){
						dist.at(s)=min+matrix.at(nxtNode).at(s);
					}
				}
			}
		}
		for (int c=0; c<n; c++){
			cout<<endl<<"Jarak node "<<c<<" dari "<<src<<" is "<<dist.at(c)<<endl;
		}return 0;	
	}	
