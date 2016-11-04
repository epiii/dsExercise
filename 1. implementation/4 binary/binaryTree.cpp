#include <iostream>
#include <bits>

typedef struct node {
	int angka;
	struct node *left, *right;
}node;

node*root=NULL;
int *daftar;
void inOrer(){
	if(leaf){
		inOrder(leaf->left);
		cout<<leaf->key_value<<" ";
		inOrder(leaf->right);
	}
}
void btree::insert(int key, node *leaf)
{
  if(key< leaf->key_value)
  {
    if(leaf->left!=NULL)
     insert(key, leaf->left);
    else
    {
      leaf->left=new node;
      leaf->left->key_value=key;
      leaf->left->left=NULL;    //Sets the left child of the child node to null
      leaf->left->right=NULL;   //Sets the right child of the child node to null
    }  
  }
  else if(key>=leaf->key_value)
  {
    if(leaf->right!=NULL)
      insert(key, leaf->right);
    else
    {
      leaf->right=new node;
      leaf->right->key_value=key;
      leaf->right->left=NULL;  //Sets the left child of the child node to null
      leaf->right->right=NULL; //Sets the right child of the child node to null
    }
  }
}

int main(){
	int a,x;
	cout<<"masukkan bilangan sejumlah 7:";
	cin>>a;
	for (int i=0; i<=a;++i){
		cin>>x;
		insert(x,root);
	}
	// node*root=NULL;
	inOrder(root)
	return 0;
}

