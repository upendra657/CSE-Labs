#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* CreateNode(int data){
	struct node* n;
	n = (struct node*)malloc(sizeof(struct node*));
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void InOrder(struct node* root){
	if(root != NULL){
		InOrder(root->left);
		printf("%d  ",root->data);
		InOrder(root->right);
	}
}

void PreOrder(struct node* root){
	if(root != NULL){
		printf("%d  ",root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

void PostOrder(struct node* root){
	if(root != NULL){
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%d  ",root->data);
	}
}

int isBST(struct  node* root){
    static struct node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

struct node* Search(struct node* root, int key){
	if(root == NULL){
		return NULL;
	}
	if(root->data == key){
		return root;
	}else if(key < root->data){
		return Search(root->left,key);
	}else{
		return Search(root->right,key);
	}
}

void insert(struct node *root, int key){
   struct node *prev = NULL;
   while(root!=NULL){
       prev = root;
       if(key==root->data){
           printf("Cannot insert %d, already in BST", key);
           return;
       }
       else if(key<root->data){
           root = root->left;
       }
       else{
           root = root->right;
       }
   }
   struct node* new = CreateNode(key);
   if(key<prev->data){
       prev->left = new;
   }
   else{
       prev->right = new;
   }
}




int main(){
	struct node* root = CreateNode(20);
	struct node* p1 = CreateNode(15);
	struct node* p2 = CreateNode(29);
	struct node* p3 = CreateNode(10);
	struct node* p4 = CreateNode(18);

	root->left = p1;
	root->right = p2;
	p1->left = p3;
	p1->right = p4;

	// 	   20
	//    /  \
	//   15   29
	//  /  \
	// 10   18

	
	 struct node* n = Search(root, 29);
    if(n!=NULL){
    printf("Found: %d\n", n->data);
    }
    else{
        insert(root,29);
    }

    printf("InOrder: ");
    InOrder(root);
    printf("\n");

    printf("PreOrder: ");
    PreOrder(root);
    printf("\n");

    printf("PostOrder: ");
    PostOrder(root);
    printf("\n");


	return 0;
}
