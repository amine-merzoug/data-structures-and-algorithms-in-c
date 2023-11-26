#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// The objective in this example is to search for an item in a binary search tree (BST),
// by whether returning (true/false) or (address/NULL).

typedef struct node* ptr;
struct node{
    int data;
    ptr left;
    ptr right;
};


ptr new_node(int);
void display_tree(ptr);

// function overloading not possible in this case
bool find_item(ptr, int);
ptr find_item_address(ptr, int);

int main(){
    ptr root = new_node(20);
    root->left = new_node(5);
    root->right = new_node(30);
    root->left->left = new_node(4);
    root->left->right = new_node(7);
    root->right->left = new_node(25);

    printf("\nBST: ");
    display_tree(root);
    printf("\n");

    int item = 5;
    bool found = find_item(root, item);
    if (found){
        printf("%i found in BST", item);
    } else { printf("\n%i not found in BST", item); }

    item = 3;
    if (find_item(root, item)){
        printf("\n%i found in BST", item);
    } else { printf("\n%i not found in BST", item); }

    item = 25;
    ptr item_address = find_item_address(root, item);
    if (item_address != NULL){
        printf("\n%i found in BST, its address is %p\n", item, item_address);
        printf("Chaging item %i to 26..", item_address->data);        
        item_address->data = 26;
    } else { printf("\n %i not found in BST", item); }

    printf("\n\nBST: ");
    display_tree(root);

    item = 25;
    item_address = find_item_address(root, item);
    if (item_address != NULL){
        printf("%i found in BST, its address is %p", item, item_address);
        item_address->data = 26;
    } else { printf("\n%i not found in BST\n\n", item); }
}

// creates a new BST node and returns its address
ptr new_node(int data){
    ptr p = malloc(sizeof(struct node));
    p->data  = data;
    p->left  = NULL;
    p->right = NULL;
    return p;
}

// prints the given BST using inorder traversal
void display_tree(ptr root){
    if (root != NULL){
        display_tree(root->left);
        printf("%i ", root->data);
        display_tree(root->right);
    }
}

// searches for an item in a BST 
// returns true if found, otherwise false 
// time complexity: O(log N) = O(h), where h is the height of BST
bool find_item(ptr root, int item){
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

// Version 1: searches for an item in a BST 
// returns its address (pointer) if found, otherwise NULL 
// time complexity: O(log N) = O(h), where h is the height of BST
ptr find_item_address(ptr root, int item){
    if (root == NULL){
        return NULL;
    }

    if (item == root->data){
        return root;
    }
    else if (item < root->data){
        return find_item_address(root->left, item);
    }
    else {
        return find_item_address(root->right, item);
    }
}

// Version 2: searches for an item in a BST 
// returns its address (pointer) if found, otherwise NULL 
// time complexity: O(log N) = O(h), where h is the height of BST
ptr find_item_address_v2(ptr root, int item){
    if (root == NULL || root->data == item){
        return root;
    }

    if (item < root->data){
        return find_item_address(root->left, item);
    }
    else {
        return find_item_address(root->right, item);
    }
}