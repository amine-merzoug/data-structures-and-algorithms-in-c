#include <iostream>

// Quiz: Singly linked lists (SLL)
// Try to find the output of this program before running it.

typedef struct node* ptr;
struct node {
    int data;
    ptr next;
};

void function_2(ptr head){
    while (head != NULL){
        printf("%i ", head->data);
        head = head->next;
    }
    printf("\n");
}

void function_1(){
    ptr head_1 = new node;
    head_1->data = 3;
    ptr head_2 = new node; 
    head_1->next = head_2;
    (*head_2).data = 7;
    (*head_2).next = NULL;
    
    function_2(head_1);

    delete head_1;
    delete head_2;
}

int main(){ 
    function_1(); 
}