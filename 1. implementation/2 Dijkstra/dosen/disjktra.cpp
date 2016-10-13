//#include <bits/stdc++.h>
#include <iostream>
int graph[10][10];
int source,
	dist[10],
	prev[0],
	visit[10];

void initGraph(){
//	inisialisasi graph
	for(int i=0; i<10; i++)
		for(int j=0; j<10; j++)
			graph[i][j]=0;

//	inisialisasi distance
	for(int i=0; i<10; i++) {
		dist[i]=0;
		prev[i]=-1; // predefined
	}
}

void cetakGraph(){
	for(int i=0; i<7; i++){
		for(int j=0; j<7; j++){
			cout<<graph[i][j]<<" ";
		}
	}
}
void bacaGraph(){
	for(int i=0; i<7; i++){
		for(int j=0; j<7; j++){
			cin>>graph[i][j];
		}
	}
}

int car_u(){
	int temp=dist[0];
	for(int i=0;i<){
		
	}
}

int main(){
	initGraph();
	bacaGraph();
	
	cout<<"input source :";
	cin>>source;
	
	dist[source]=0;
	prev[source]=source;
	
//	inisialisasi vertex ke queue
	for(int i=0; i<7;i++) 
		q.push(i);

	while(!q.empty()){
		int u=cari_u();
	}
	return 0;
}
//adjacency matrix
//	0	1	2	3	4	5	6	7
//	1	0	0	23	23	0	0	0
//	2	0	0	5	0	0	0	16
//	3	0	5	0	9	17	0	0
//	4	0	0	9	0	18	25	0
//	5	0	0	17	18	0	7	22
//	6	0	0	0	25	7	0	0
//	7	0	16	0	0	22	0	0

