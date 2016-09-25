//http://stackoverflow.com/questions/22642902/how-to-implement-bfs-on-a-matrix
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int bfs(int, int);

bool visited[100][100];
char matrica[100][100];

int m, n, d;

int main()
{

    scanf("%d %d", &m, &n);

    for(int i = 0;i < m;i++){
        for(int j = 0; j < n; j++){
            cin >> matrica[i][j];
            visited[i][j] = false;
        }
    }

    for(int i = 0;i < m;i++){
        for(int j = 0; j < n; j++){
            if(matrica[i][j] == 'B'){
                bfs(i, j);
            }
        }
    }

    cout << endl << d;

    return 0;
}

int gk[] = {1, 0, -1, 0};
int gr[] = {0, 1, 0, -1};

int bfs(int x, int y){

    cout << endl;

    queue<int>queue_x, queue_y;
    int topx, topy, d=0;

    //memset(visited, 0, sizeof visited);

    visited[x][y] = true;

    queue_x.push(x);
    queue_y.push(y);

    while(!queue_x.empty()){
        topx = queue_x.front();
        topy = queue_y.front();
        queue_x.pop();
        queue_y.pop();

        if(matrica[topx][topy] == 'H'){
            cout << endl << d << endl;
            d++;
            return d;
        }

        for(int i = 0; i < 4; i++){
            x += gk[i];
            y += gr[i];
            if(visited[x][y] == false && matrica[x][y] != '#'){
                visited[x][y] = true;
                matrica[x][y] = '*';
                queue_x.push(x);
                queue_y.push(y);
                d++;

                //-------------
                for(int i = 0; i < m;i++){
                    for(int j = 0; j < n;j++){
                        cout << matrica[i][j];
                    }
                    cout << endl;
                }
                //-------------
            }
        }
    }
}
