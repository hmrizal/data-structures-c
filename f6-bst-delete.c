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
	printf(" BST Kosong\n\n");
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

void inorderTraversal(struct node *tree){
	if(tree != NULL){
		inorderTraversal(tree->left);
		printf(" %d ", tree->data);
		inorderTraversal(tree->right);
	}
}

// Find the inorder successor
struct node *minValueNode(struct node *tree) {
  struct node *current = tree;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Deleting a node
struct node *deleteNode(struct node *tree, int data) {
  // Return if the tree is empty
  if (tree == NULL) return tree;
  // Find the node to be deleted
  if (data < tree->data)
    tree->left = deleteNode(tree->left, data);
  else if (data > tree->data)
    tree->right = deleteNode(tree->right, data);
  else {
    // If the node is with only one child or no child
    if (tree->left == NULL) {
      struct node *temp = tree->right;
      free(tree);
      return temp;
    } else if (tree->right == NULL) {
      struct node *temp = tree->left;
      free(tree);
      return temp;
    }

    // If the node has two children
    struct node *temp = minValueNode(tree->right);

    // Place the inorder successor in position of the node to be deleted
    tree->data = temp->data;

    // Delete the inorder successor
    tree->right = deleteNode(tree->right, temp->data);
  }
  return tree;
}

int main(){
	int deret[] = {13, 27, 83, 67, 1, 90, 37, 40, 62, 102, 53, 72, 34, 21, 20};
	create_tree(tree);
	
	printf(" Masukkan deret pada soal ke BST\n\n");
	for(int i=0;i<sizeof(deret)/sizeof(deret[0]);i++){
		tree = insertElement(tree, deret[i]);
	}

	printf(" InOrder traversal: \n");
	inorderTraversal(tree);
	
	printf("\n\n Menghapus angka 102");
	tree = deleteNode(tree, 102);
	printf("\n\n");
	
	printf(" InOrder traversal setelah 102 dihapus: \n");
	inorderTraversal(tree);
	return 0;
}
