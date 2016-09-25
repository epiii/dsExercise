#include <iostream>
#include <queue>
#include <stack>
#define max 20

using namespace std;
int adjMat[max][max];
int nVertex;
	
struct vertex{
    char label;
    int wasVisited;
};

//func tampilkan hasil (terakhir)
void displayVertex(struct vertex *vList, int i){
    cout << vList[i].label << " ";
}

//undirected
//func tambah node tujuan (array : awal-tujuan)
void addEdgeUndir(int start, int end){
    adjMat[start][end] = 1;
    adjMat[end][start] = 1;
}

//directed
//func tambah node tujuan (array : awal-tujuan)
void addEdgeDir(int start, int end){
    adjMat[start][end] = 1;
}

//cek (telah dikkunjungi?)
int getAdjUnvisited(struct vertex *vList, int v){
    for(int i = 0; i < nVertex; i++)
        if(adjMat[v][i] == 1 && vList[i].wasVisited == 0)
            return i;
    return -1;
}

//Beard-First Search (Level Order)
void bfs(struct vertex *vList, int v){
    queue <int> theQueue;
    vList[v].wasVisited = 1;
    displayVertex(vList, v);
    theQueue.push(v);
    int v2;
    while(!theQueue.empty()){
        int v1 = theQueue.front();
        theQueue.pop();
        while((v2 = getAdjUnvisited(vList, v1)) != -1)
        {
            //vertex tetangga diperoleh dan tandai
            vList[v2].wasVisited = 1;
            //tampilkan
            displayVertex(vList, v2);
            //sisipkan vertex
            theQueue.push(v2);	
        }
    }
    cout << endl;
    for(int i = 0; i < nVertex; i++)
        vList[i].wasVisited = 0;
}

//Depth-First Search (PreOrder)
void dfs(struct vertex *vList, int v)
{
    stack <int> stack1;
    stack <int> stack2;
    //mulai dari vertex v
    vList[v].wasVisited = 1;
    stack2.push(v);
    stack1.push(stack2.top());
    stack2.pop();
    while(!stack1.empty())
    {
        int vUnvisited = getAdjUnvisited(vList, stack1.top());
        if(vUnvisited == -1)
        {
            displayVertex(vList, stack1.top());
            stack1.pop();
            while(!stack2.empty()){
                stack1.push(stack2.top());
                stack2.pop();
            }
        }
        else
        {
            vList[vUnvisited].wasVisited = 1;
            stack2.push(vUnvisited);
        }
    }
    cout << endl;
    for(int i = 0; i < nVertex; i++)
        vList[i].wasVisited = 0;
}

int main(){
    cout << "input jumlah node  : ";
    cin >> nVertex;
    fflush(stdin);
    struct vertex vertexList[nVertex];
    for (int i = 0; i < nVertex; i++) {//baris
        for (int j = 0; j < nVertex; j++) {//kolom
            adjMat[i][j] = 0;
        }
    }
    char label;
    for(int i = 0; i < nVertex; i++){
        cout << "label node [" << i << "] : ";
        cin >> label;
        fflush(stdin);
        vertexList[i].label = label;
        vertexList[i].wasVisited = 0;
    }
    cout << "menu : Undirected input 'U' dan Directed input 'D' : ";
    char mode;
    int max_edges;
    cin >> mode;
    fflush(stdin);
    switch(mode){
        case 'U':
//            cout << "Anda memilih Mode Undirected Graph" << endl;
            max_edges = (nVertex * (nVertex - 1)) / 2;
            break;
        case 'D':
//            cout << "Anda memilih Mode Directed Graph" << endl;
            max_edges = nVertex * (nVertex - 1);
            break;
        default:
            cout << "Default Mode Directed Graph" << endl;
            max_edges = nVertex * (nVertex - 1);
            break;
    }
    int asal, tujuan;
    for (int i = 1; i <= max_edges; i++) {
        cout << "input edge " << i << "(asal <spasi> tujuan) : ";
        scanf("%d %d", &asal, &tujuan);
        fflush(stdin);
        if ((asal == 0) && (tujuan == 0)) {
            break;
        }
        if (asal > nVertex || tujuan > nVertex || asal < 0 || tujuan < 0) {
            cout << "Edge tidak valid!" << endl;
            i--;
        } else {
            switch (mode) {
                case 'U':
                    addEdgeUndir(asal, tujuan);
                    break;
                case 'D':
                    addEdgeDir(asal, tujuan);
                    break;
                default:
                    addEdgeDir(asal, tujuan);
                    break;
            }
        }
    }
    int sVertex;
    cout << "input node awal : ";
    cin >> sVertex;
    cout << "hasil :" << endl;
    cout << "> bfs : ";
    bfs(vertexList, sVertex);
    cout << "> dfs ";
    dfs(vertexList, sVertex);
    return 0;
}
