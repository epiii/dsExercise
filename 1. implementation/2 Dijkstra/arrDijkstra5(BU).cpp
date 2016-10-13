#include <stdio.h>
#include <conio.h>
#define INFINITY 9999
#define MAX 10

void dijkstra(int G[MAX][MAX],int n,int startnode) { // param : (matrix graph , jumlah node, node awal)
    int cost[MAX][MAX],
		distance[MAX],
		pred[MAX];
    int visited[MAX],
		count,
        mindistance,
        nextnode,i,j;
    
	//	inisialisasi msg2 jarak edge 
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j]==0) cost[i][j]=INFINITY; // matrix kosong (infinite)
            else cost[i][j]=G[i][j]; // matrix berisi 
    
    //inisialisasi pred[],distance[] and visited[]
    for(i=0;i<n;i++){ 
        distance[i]=cost[startnode][i]; // jarak masing2 dari awal node
        pred[i]=startnode; //
        visited[i]=0;
    }
    
    distance[startnode]=0;
    visited[startnode]=1;
    count=1;
    
    while(count<n-1){
        mindistance=INFINITY;
        
        //node selanjutnya yang punya jarak minimum
        for(i=0;i<n;i++)
            if(distance[i]<mindistance&&!visited[i]){// bandingkan jarak baru dg lama & pernah dikunjungi
                mindistance=distance[i];
                nextnode=i;
            }
            
            //cari jarak terpendek            
            visited[nextnode]=1;
            for(i=0;i<n;i++)
                if(!visited[i])
                    if(mindistance+cost[nextnode][i]<distance[i]){
                        distance[i]=mindistance+cost[nextnode][i];
                        pred[i]=nextnode;
                    }
        count++;
    }
 
    //cetak rute dan jarak tiap node
    for(i=0;i<n;i++)
        if(i!=startnode){
            printf("\n\nJarak ke node %d=%d",i,distance[i]);
            printf("\nRute=%d",i);
            
            j=i;
            do{
                j=pred[j];
                printf("<-%d",j);
            }while(j!=startnode);
    }
}

int main(){
    int G[MAX][MAX],i,j,n,u;
    printf("Jumlah Matrix:");
    scanf("%d",&n);
    printf("\nMasukkan Adjacency Matrix:\n");
    
	//    input graph matrix
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&G[i][j]);
    
    printf("\nMasukkan Node Asal:");
    scanf("%d",&u);
    dijkstra(G,n,u);
    
    return 0;
}

/*

0 	30 	25 	0 	0 	0 	0
0 	0 	0 	0 	10 	5 	0
0 	0 	0 	5 	0 	0 	0
0 	0 	0 	0 	5 	0 	0
0 	0 	0 	0 	0 	0 	5
0 	0 	0 	0 	0 	0 	10
0 	0 	0 	0 	0 	0 	0


*/