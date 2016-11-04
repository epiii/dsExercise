#include <iostream> 
#include <stdlib.h>  // malloc, struct
 
using namespace std;
// struct node{
typedef struct node {
   int data;
   node *left;
   node *right;
}node;

//prototype : hanya jika main  didefinisikan "sebelum" fungsi tsb 
    // node *insert(node *tree,int ele);
    // void inorder(node *tree);
    // node *gabung(node *tree1,node *tree2);

node *insert(node *tree,int ele){
    if(tree==NULL){
        // tree=(node*)malloc(sizeof(node));
        tree=(node*)malloc(sizeof(node));
        tree=new node;
        tree->data=ele;
        tree->left=tree->right=NULL;
    }else if(tree->data>ele){ 
        tree->left=insert(tree->left,ele);
    }else if(tree->data<=ele){
        tree->right=insert(tree->right,ele);
    }return(tree);
}

void inorder(node *tree){
   if(tree!=NULL){
        inorder(tree->left);
        cout<<tree->data << " ";
        inorder(tree->right);
   }
}

node *gabung(node *tree1,node *tree2){
    if(tree1==NULL){
        return(tree2);
    }else if(tree2->data<tree1->data){
        tree1->left=gabung(tree1->left,tree2); //recursive
    }else if(tree2->data>tree1->data){
        tree1->right=gabung(tree1->right,tree2);
    }return tree1;
}

int main(){
    int a,x,n;
    int angka_gabung1,angka_gabung2;
    node *tree[100];
    node *tree_gabung;

    cout<<"Input jumlah tree, jumlah node & masing2 node :\n";
    cin>>n;
    for(int i = 1; i <=n; i++){ // jumlah tree
        tree[i] = NULL;
        cin>>a;
        for(int j = 1; j <= a; j++){ // jumlah node tiap tree
          cin >> x;
          tree[i] = insert(tree[i], x);
        }cout<<"inorder (T"<<i<<"):";
        inorder(tree[i]);
        cout<<endl;
    }cin>>angka_gabung1>>angka_gabung2;
    tree_gabung = gabung(tree[angka_gabung1],tree[angka_gabung2]);
    cout<<"Gabungan (T"<<angka_gabung1<<"+T"<<angka_gabung2<<"):";
    inorder(tree_gabung);
}

/*
3
2
7 10
3
3 1 11
4
12 13 5 4
1 2
hasil : 1 3 11 7 10

3
2
7 10
3
3 1 11
4
12 13 5 4
1 3
hasil  : 7 10 4 5 12 13

3
2
7 10
3
3 1 11
4
12 13 5 4
3 1
hasil : 4 5 7 10 12 13 

3
2
7 10
3
3 1 11
4
12 13 5 4
3 2
hasil : 1 3 11 4 5 12 13 

http://www.cplusplus.com/articles/yAqpX9L8/
*/
