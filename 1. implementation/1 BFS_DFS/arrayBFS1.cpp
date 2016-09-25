//adjacency matrix (array) 
#include <iostream>
#include <conio.h>
#define MAX_NODE 10

using namespace std;

struct node{
    int vertex;
    node *next;
};

node *adj[MAX_NODE]; //For storing Adjacency list of nodes.
int jmlNode; //No. of Nodes in Graph.

int queue[MAX_NODE], f=-1,r=-1;

//func enqueue 
void q_insert(int item){
    r = r+1;
    queue[r]=item;
    if(f==-1) f=0;
}

//func dequeue
int q_delete(){
    int delitem=queue[f];
    if(f==r) f=r=-1;
    else f=f+1;
    return(delitem);
}

//func cek queue kosong ?
int is_q_empty(){
    if(f==-1) return(1);
    else return(0);
}

//proses .... 
/*void bfsProses(){
    node *newl,*last;
    int neighbours,neighbour_value, nodeAwal, nodeTujuan;
    
    cout<<"jumlah node = ";
    cin>>jmlNode;
    for(int i=1;i<=jmlNode;i++){
        last=NULL;
//        cout<<" \n> iterasi ke-"<<i<<" : ";        
		cout<<"> input array : "<<i<<endl;
        for(int j=1;j<=jmlNode;j++){
//			int xx=2;
			for(int k=1;k<2;k++){
	        	if(k==1){
					cout<<"-- node awal :";
	        		cin>>nodeAwal;		
				}else{
		        	cout<<"-- node tujuan :";
		        	cin>>nodeTujuan;		
				}
//				xx--;
			}
		}
		
    }
}*/

void bfsProses(){
    node *newl,*last;
    int neighbours,neighbour_value;
    
    cout<<"jumlah node = ";
    cin>>jmlNode;
    for(int i=1;i<=jmlNode;i++){
        last=NULL;
        // cout<<" > That is Total Neighbours of "<<i<<" : ";
        cout<<" \n> iterasi ke-"<<i<<" : ";
        cin>>neighbours;
        for(int j=1;j<=neighbours;j++){
            cout<<"index 1 #"<<j<<" : ";
            cin>>neighbour_value;
            newl=new node;
            newl->vertex=neighbour_value;
            newl->next=NULL;
            if(adj[i]==NULL)
                adj[i]=last=newl;
            else{
                last->next = newl;
                last = newl;
            }
        }
    }
}

void bfsHasil(){
    node *tmp;
    int N,v,start_node,status[MAX_NODE];//status arr for maintaing status.
	const int ready=1,wait=2,processed=3; //status of node.

    cout<<"Node awal : ";
    cin>>start_node;

    //step 1 : Initialize all nodes to ready state.
	for(int i=1;i<=jmlNode;i++)
        status[i]=ready;

    //step 2 : put the start node in queue and change status.
    q_insert(start_node); //Put starting node into queue.
    status[start_node]=wait; //change it status to wait state.

    //step 3 : Repeat until queue is empty.
    while(is_q_empty()!=1){
        //step 4 : Remove the front node N of queue.//process N and change the status of N to//be processed state.
        N = q_delete(); //remove front node of queue.
        status[N]=processed; //status of N to processed.
        cout<<"   "<<N; //displaying processed node.//step 5 : Add to rear of queue all the neighbours of N,//that are in ready state and change their status to//wait state.
        tmp = adj[N];  //for status updation.
		while(tmp!=NULL){
            v = tmp->vertex;
            if(status[v]==ready){//check status of N's neighbour.
                q_insert(v); //insert N's neighbour who are in ready state.
                status[v]=wait; //and make their status to wait state.
            }
            tmp=tmp->next;
        }
    }
}

int main(){
    cout<<"BFS (adj. matrix / array)\n";
      bfsProses();
    cout<<"\nProses BFS :\n";
      bfsHasil();
}


