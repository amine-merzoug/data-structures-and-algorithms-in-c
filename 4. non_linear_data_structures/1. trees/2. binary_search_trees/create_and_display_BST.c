#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node* ptr;
struct tree_node{
    int data;
    ptr left;
    ptr right;
};

ptr new_node(int);
void display_tree(ptr);

/* The objective in this first example is to create and display 
the following binary search tree (BST):
             20
            /  \
           5   30
         /  \    
        4    7                                   
*/

int main(){
    // Create BST
    ptr root = new_node(20);
    root->left = new_node(5);
    root->right = new_node(30);
    root->left->right = new_node(7);
    root->left->left = new_node(4);

    printf("\nBST: ");
    display_tree(root);
    printf("\n\n");
}

// creates a new BST node and returns its address
ptr new_node(int data){
    ptr p = malloc(sizeof(struct tree_node));
    p->data  = data;
    p->left  = NULL;
    p->right = NULL;
    return p;
}

// prints the given BST using in-order traversal
void display_tree(ptr root){
    if (root != NULL){
        display_tree(root->left);
        printf("%i ", root->data);
        display_tree(root->right);
    }
}