#include <stdio.h>
// #include <conio>
#include <malloc.h>
typedef struct node
{
	int s152;
	node *kiri;
	node *kanan;
};
node *root=NULL;
void Tambahpang(node **root, int u152)
{
	if((*root)==NULL){
		node *baru;
		baru= new node;
		baru->s152 = u152;
		baru->kiri = NULL;
		baru->kanan = NULL;
		(*root)=baru;
	}
}
void preorder(node *root) {
	if(root !=NULL) {
		printf("%i, ", root->s152);
		preorder(root->kiri);
		preorder(root->kanan);}
	}
void inorder(node *root)
{
if(root !=NULL) {
inorder(root->kiri);
printf("%i, ", root->s152);
inorder(root->kanan);}
}
void postorder(node *root)
{
if(root !=NULL) {
postorder(root->kiri);
postorder(root->kanan);
printf("%i, ", root->s152);
}
}
int main(){
	// clrscr();
	int g152;
	int e152;
	int n152;
	e152=40;n152=3;
	printf("\t\t\t=> Sugeng Siswanto - 1412110152 <=");
	printf("\n***************************************************************************\n");
	gotoxy(e152,n152);
	printf("100\n");
	gotoxy(e152-10,n152+1);
	printf("90");
	gotoxy(e152+10,n152+1);
	printf("200\n");
	gotoxy(e152-20,n152+2);
	printf("80");
	gotoxy(e152+20,n152+2);
	printf("300\n");
	gotoxy(e152-30,n152+3);
	printf("70");
	gotoxy(e152+30,n152+3);
	printf("400\n");
	Tambahpang(&root,g152=100);
	Tambahpang(&root->kiri,g152=90);
	Tambahpang(&root->kiri->kiri,g152=80);
	Tambahpang(&root->kiri->kiri->kiri,g152=70);
	Tambahpang(&root->kanan,g152=200);
	Tambahpang(&root->kanan->kanan,g152=300);
	Tambahpang(&root->kanan->kanan->kanan,g152=400);
	printf("\nTampilan secara PreOrder : ");
	preorder(root);
	printf("\nTampilan secara InOrder : ");
	inorder(root);
	printf("\nTampilan secara PostOrder : ");
	postorder(root);
	printf("\n***************************************************************************\n");
	getch ();
}

// http://sugengsiiswanto.blogspot.co.id/2013/12/menyusun-angka-dengan-preorder-inorder.html