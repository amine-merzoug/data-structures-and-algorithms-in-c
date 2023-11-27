#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// The objective in this example is to search for an item in a binary search tree (BST) 
// by returning whether (true, false) or (item_address, NULL). 

typedef struct node* tree_ptr;
struct node{
    int data;
    tree_ptr left;
    tree_ptr right;
};

void create_tree(tree_ptr*);
tree_ptr new_node(int);
void display_tree(tree_ptr);

// function overloading not possible in this case
bool find_item(tree_ptr, int);
tree_ptr find_item_address(tree_ptr, int);

void search_item_example(tree_ptr);
void search_item_address_example(tree_ptr);

int main(){
    tree_ptr root = NULL;
    create_tree(&root);

    printf("\nBST (inorder): ");
    display_tree(root);
    printf("\n");

    search_item_example(root);
    search_item_address_example(root);
}

// creates the following BST (inorder): 4 5 7 20 25 30
void create_tree(tree_ptr *root){
    *root = new_node(20);
    (*root)->left = new_node(5);
    (*root)->right = new_node(30);
    (*root)->left->left = new_node(4);
    (*root)->left->right = new_node(7);
    (*root)->right->left = new_node(25);
}

// creates a new BST node and returns its address
tree_ptr new_node(int data){
    tree_ptr p = malloc(sizeof(struct node));
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

// searches for an item in a BST 
// returns true if found, otherwise false 
// time complexity: O(log N) = O(h), where h is the height of BST and N is its size.
bool find_item(tree_ptr root, int item){
    if (root == NULL){
        return false;
    }

    if (item == root->data){
        return true;
    } else if (item < root->data){
        return find_item(root->left, item);
    } else {
        return find_item(root->right, item);
    }
}

// searches for an item in a BST 
// returns its address (pointer) if found, otherwise NULL 
// time complexity: O(log N) = O(h), where h is the height of BST and N is its size.
tree_ptr find_item_address(tree_ptr root, int item){
    if (root == NULL || root->data == item){
        return root;
    }

    if (item < root->data){
        return find_item_address(root->left, item);
    } else {
        return find_item_address(root->right, item);
    }
}

/*
// searches for an item in a BST 
// returns its address (pointer) if found, otherwise NULL 
// time complexity: O(log N) = O(h), where h is the height of BST and N is its size.
tree_ptr find_item_address(tree_ptr root, int item){
    if (root == NULL){
        return NULL;
    }

    if (item == root->data){
        return root;
    } else if (item < root->data){
        return find_item_address(root->left, item);
    } else {
        return find_item_address(root->right, item);
    }
}*/

// an example to show how to search for an item in BST
// by returning true or false 
void search_item_example(tree_ptr root){
    int item = 5;
    bool found = find_item(root, item);
    if (found){
        printf("item %i found in BST", item);
    } else { printf("\nitem %i not found in BST", item); }

    item = 3;
    if (find_item(root, item)){
        printf("\nitem %i found in BST", item);
    } else { printf("\nitem %i not found in BST", item); }
}

// an example to show how to search for an item in BST 
// by returning item_address or NULL 
void search_item_address_example(tree_ptr root){
    int item = 25;
    tree_ptr item_address = find_item_address(root, item);
    if (item_address != NULL){
        printf("\nitem %i found in BST, its address is %p\n", item, item_address);
        printf("Changing item %i to be 26..", item_address->data);        
        item_address->data = 26;
    } else { printf("\nitem %i not found in BST", item); }

    printf("\n\nBST (inorder): ");
    display_tree(root);

    item = 26;
    item_address = find_item_address(root, item);
    if (item_address != NULL){
        printf("\nitem %i found in BST, its address is %p\n", item, item_address);
    } else { printf("\nitem %i not found in BST\n\n", item); }
}