/*----Ratnesh----*/
// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct tree{
	int key;
	tree *lchild,*rchild;
}*root=NULL,*root1=NULL;

tree *newnode(int k)
{
	tree *temp=new tree();
	temp->key=k;
	temp->lchild=temp->rchild=NULL;
	return temp;
}

void merge(int *a,int *b,int size,int size1,int *c)
{
	int i=0,k=0,j=0;
	while(k<size && j<size1)
	{
		if(a[k]<b[j])
		{
			c[i++]=a[k++];
		}
		else
		{
			c[i++]=b[j++];
		}
	}
	while(k<size)
	{
		c[i++]=a[k++];
	}
	while(j<size1)
	{
		c[i++]=b[j++];
	}
}

void storeInorder(tree *root,int *v,int i,int *sp)
{
	stack<tree*>s;
	tree *ptr=root;
	if(ptr==NULL) 
		return;

	while(1)
	{
		while(ptr->lchild)
		{
			s.push(ptr);
			ptr=ptr->lchild;
		}
		while(ptr->rchild==NULL)
		{
		    v[i++]=ptr->key;
		    (*sp)++;
			if(s.empty())
				return;
			ptr=s.top();
			s.pop();
		}
		v[i++]=ptr->key;
		(*sp)++;
		ptr=ptr->rchild;
	}
}

tree *buildBst(int *a,int low,int high)
{
	if(low>high) return NULL;
	
	int mid=(low+high)/2;
	tree *root=newnode(a[mid]);
	root->lchild=buildBst(a,low,mid-1);
	root->rchild=buildBst(a,mid+1,high);
	return root;
}


void inorder(tree *root)
{
	stack<tree*>st;							//stack for inorder
	tree *ptr=root;
	if(root==NULL)
		return;
		
	while(1)
	{
		while(ptr->lchild)
		{
			st.push(ptr);
			ptr=ptr->lchild;
		}
		while(ptr->rchild==NULL)
		{
			cout<<ptr->key<<" ";
			if(st.empty())
				return;
			ptr=st.top();
			st.pop();
		}
		cout<<ptr->key<<" ";
		ptr=ptr->rchild;
	}
}

void post(tree *root)
{
	if(root==NULL) return;
	post(root->lchild);
	post(root->rchild);
	cout<<root->key<<" ";
}

int main()
{
	root=newnode(100);
	root->lchild=newnode(50);
	root->rchild=newnode(300);
	root->lchild->lchild=newnode(20);
	root->lchild->rchild=newnode(70);
	
	inorder(root);
	cout<<endl;
	root1=newnode(80);
	root1->lchild=newnode(40);
	root1->rchild=newnode(120);
	inorder(root1);
	
	int a[100],b[100],size=0,size1=0;					
	storeInorder(root,a,0,&size);
	storeInorder(root1,b,0,&size1);

	
	int m[200]; 							//merge array
	//int size=sizeof(a)/sizeof(a[0]);
	//int size1=sizeof(b)/sizeof(b[0]);	
		
	cout<<endl<<size<<" "<<size1;
		
	merge(a,b,size,size1,m);

	tree *head=buildBst(m,0,size+size1-1);
	cout<<endl;
	inorder(head);
	cout<<endl<<"Post Order"<<endl;
	post(head);
	return 0;
}

// http://ideone.com/BrTXr6