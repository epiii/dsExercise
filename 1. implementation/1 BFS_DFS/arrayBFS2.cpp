#include<bits/stdc++.h>

using namespace std;
class Graph{
	//private:
	
	int vertex,edge;
	int **a;int *visited;
	public:
		Graph(int ver,int edg){
			vertex=ver;
			edge=edg;
			a=new int*[ver];
			for(int i=0;i<ver;i++){
				a[i]=new int[ver];
			}
			visited=new int[ver];
			for(int i=0;i<ver;i++){
				visited[i]=0;
			//	cout<<visited[i];
			}
		} 
		
		bool create_graph(){
			for(int i=0;i<vertex;i++){
				for(int j=0;j<vertex;j++){
					cin>>a[i][j];
				}
			}
		}
		
		void dfs(int node){
			visited[node]=1;
		//	cout<<visited[node];
		int i;
		cout<<node<<" ";
			for(i=0;i<vertex;i++){
				if(a[node][i] && !visited[i]){
					//cout<<a[i][node]<<" ";
				//	cout<<i<<" "<<node<<endl;
				//	cout<<node<<" ";
					dfs(i);
				}
			}
			
		}
		
		void bfs(int node){
			visited[node]=1;
			queue<int> qu;
			qu.push(node);
			
			while(!qu.empty()){
				int element=qu.front();
				int i;
				qu.pop();
				cout<<element<<" ";
				for(i=0;i<vertex;i++){
					if(a[element][i] && !visited[i]){
						qu.push(i);
						visited[i]=1;
					}
				}
			}
		}
			
};
int main(){
	Graph gh(5,4);
	cout<<"creating graph...\n";
	gh.create_graph();
	cout<<"dfsing....\n";
	gh.dfs(0);
}
