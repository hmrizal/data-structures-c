#include<stdlib.h>
#include<stdio.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
}; 

struct node *tree;

void create_tree(struct node *tree){
	tree = NULL;
	printf("\n BST kosong\n");
}

struct node *insertElement(struct node *tree, int val){
	struct node *ptr, *nodeptr, *parentptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data = val;
	ptr->left = NULL;
	ptr->right = NULL;
	if(tree==NULL){
		tree=ptr;
		tree->left=NULL;
		tree->right=NULL;
	}
	else{
		parentptr=NULL;
		nodeptr=tree;
		while(nodeptr!=NULL){
			parentptr=nodeptr;
			if(val<nodeptr->data){
				nodeptr=nodeptr->left;
			}
			else{
				nodeptr = nodeptr->right;
			}
		}
		if(val<parentptr->data){
			parentptr->left = ptr;
		}
		else{
			parentptr->right = ptr;
		}
	}
return tree;
}

void preorderTraversal(struct node *tree){
	if(tree != NULL){
		printf(" %d ", tree->data);
		preorderTraversal(tree->left);
		preorderTraversal(tree->right);
	}
}

void inorderTraversal(struct node *tree){
	if(tree != NULL){
		inorderTraversal(tree->left);
		printf(" %d ", tree->data);
		inorderTraversal(tree->right);
	}
}

void postorderTraversal(struct node *tree){
	if(tree != NULL){
		postorderTraversal(tree->left);
		postorderTraversal(tree->right);
		printf(" %d ", tree->data);
	}
}

int main(){
	int deret[] = {13, 27, 83, 67, 1, 90, 37, 40, 62, 102, 53, 72, 34, 21, 20};
	create_tree(tree);
	
	printf("\n Masukkan deret pada soal ke BST\n");
	for(int i=0;i<sizeof(deret)/sizeof(deret[0]);i++){
		tree = insertElement(tree, deret[i]);
	}
	printf("\n PreOrder traversal: \n");
	preorderTraversal(tree);
	printf("\n");
	printf("\n InOrder traversal: \n");
	inorderTraversal(tree);
	printf("\n");
	printf("\n PostOrder traversal: \n");
	postorderTraversal(tree);

	return 0;
}

