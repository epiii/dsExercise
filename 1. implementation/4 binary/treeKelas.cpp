// #include <bits/stdc++>
#include <iostream>
using namespace std;
 
typedef struct node {
    int key_value;
    struct node *left, *right;
} node;
 
node *root = NULL;
node* daftar[100];
 
void inOrder(node *leaf) {
    if ( leaf != NULL ) {
       inOrder(leaf->left);
       cout << leaf->key_value << " ";
       inOrder(leaf->right);
    }
}
 
void insert(int key, node *leaf){
    // cout<<"key "<<key<<" leaf:"<<leaf;
    // return false;
    if(leaf == NULL){ // jika node root masih belum terbentuk
        cout<<"masuk null";
        leaf = new node();
        leaf->key_value=key;
        leaf->left=NULL;
        leaf->right=NULL;
        root = leaf;
    } else { // jika node root sudah terbentuk
        cout<<"masuk gak null";
        if(key < leaf->key_value){
            if(leaf->left!=NULL) insert(key, leaf->left);  // recursive
            else{
                leaf->left=new node();
                leaf->left->key_value=key;
                leaf->left->left=NULL;    //Sets the left child of the child node to null
                leaf->left->right=NULL;   //Sets the right child of the child node to null
            }
        }else if(key >= leaf->key_value){
            if(leaf->right!=NULL) insert(key, leaf->right);
            else{
                leaf->right=new node();
                leaf->right->key_value=key;
                leaf->right->left=NULL;  //Sets the left child of the child node to null
                leaf->right->right=NULL; //Sets the right child of the child node to null
            }
        }
    }
}

int  main(){
    int a, x ;
    cout<<"masukkan jumlah tree :";
    cin>>a;
    for(int i = 1; i <= a; i++){
        cout<<"masukkan tree ke-"<<i<<":";
        cin>>x;
        insert(x, root);
    }inOrder(root);
	return 0;
}

/*
3

2
7 10

3
3 1 11

4 
12 13 5 4 
*/