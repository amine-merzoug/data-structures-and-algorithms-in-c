#include <stdio.h>
#include <stdlib.h>

/* The objective in this first example is to create and display 
the following binary search tree (BST):
             20
            /  \
           5   30
         /  \    
        4    7                                   
*/

typedef struct tree_node* tree_ptr;
struct tree_node{
    int data;
    tree_ptr left;
    tree_ptr right;
};

tree_ptr new_node(int);
void display_tree(tree_ptr);

int main(){
    // create and link BST nodes
    tree_ptr root = new_node(20);
    root->left = new_node(5);
    root->right = new_node(30);
    root->left->left = new_node(4);
    root->left->right = new_node(7);

    printf("\nBST (inorder): ");
    display_tree(root);
    printf("\n\n");
}

// creates a new BST node and returns its address
tree_ptr new_node(int data){
    tree_ptr p = malloc(sizeof(struct tree_node));
    p->data  = data;
    p->left  = NULL;
    p->right = NULL;
    return p;
}

// prints the given BST using inorder traversal
void display_tree(tree_ptr root){
    if (root != NULL){
        display_tree(root->left);
        printf("%i ", root->data);
        display_tree(root->right);
    }
}