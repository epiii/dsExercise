#include <stdio.h>
//#include <conio.h>
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
    
	//	edge : init  msg2 jarak (7x7=49 edge)
    for(i=0;i<n;i++){       // 7x
        for(j=0;j<n;j++){   // 7x
            if(G[i][j]==0) cost[i][j]=INFINITY; // matrix kosong (infinite)
            else cost[i][j]=G[i][j]; // matrix berisi 
		}
	}
    
	// node : init bobot tiap node (7 node)
    for(i=0;i<n;i++){                   // iterasi 7x
        distance[i]=cost[startnode][i]; // jarak masing2 dari awal node
        pred[i]=startnode; 				// node sebelumnya
        visited[i]=0; 					// telah/belum  dikunjungi
    }
    
    distance[startnode]=0; 	// init jarak untuk node awal = 0
    visited[startnode]=1;	// init telah dikunjungi untuk node awal = 1
    count=1;				// counter ( var untuk iterasi)
    
    while(count<n-1){ // (1<7-1 => 1<6 => 5) diiterasi sebanyak 5x 
        mindistance=INFINITY; // init jarak minimum = INF (99)
        
        //node selanjutnya yang punya jarak minimum
        for(i=0;i<n;i++){ // iterasi 7x
            if(distance[i]<mindistance&&!visited[i]){// bandingkan jarak baru dg lama & pernah dikunjungi
                mindistance=distance[i];    // update jarak terpilih  (dr node i)
                nextnode=i;                 // update node terpilih  (untuk dijadikan node awal pd tahap selanjutnya ) 
            }
        }
        
		//cari jarak terpendek            
        visited[nextnode]=1;    // update status node terpilih --> "telah dikunjungi"
        for(i=0;i<n;i++){       // iterasi 7x
            if(!visited[i]){    // belum dikunjungi
				if(mindistance + cost[nextnode][i] < distance[i]){ // 
                    distance[i]=mindistance+cost[nextnode][i];
                    pred[i]=nextnode;
                }
        	}
		}count++;
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
                // j++;
            }while(j!=startnode);
    }
}

int main(){
    int G[MAX][MAX],i,j,n,u;
    printf("Jumlah Matrix:");
    scanf("%d",&n);
    printf("\nMasukkan Adjacency Matrix:\n");
    
	// input graph matrix
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
