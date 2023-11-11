#include <stdio.h>

// Remember: use constants instead of magic numbers
const int ARRAY_SIZE = 12; 

// To assess the efficiency of Insertion Sort, use a large array
// const int ARRAY_SIZE = 500000;

void generate_desc_array(int[]);
void print_array(int[]);
void insertion_sort(int[]);

int main(){
    // int array[] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    
    int array[ARRAY_SIZE];
    
    generate_desc_array(array);
    print_array(array);

    insertion_sort(array);
    print_array(array);
}

// Sorts the given array using Insertion Sort (time complexity O(N^2))
void insertion_sort(int arr[]){
    for (int i = 1; i < ARRAY_SIZE; i++){
        int element_to_insert = arr[i];  // So as not to lose arr[i] when shifting elements

        // Step 1: shift right all elements in [0, i - 1] that are greater than "element_to_insert" 
        int j = i - 1;
        while (j >= 0 && arr[j] > element_to_insert){
            arr[j + 1] = arr[j];
            j--;
        }
        
        // Step 2: once shifting is done, insert "element_to_insert" in position
        arr[j + 1] = element_to_insert;
    }
}

// Generates an array in descending order, with values going from ARRAY_SIZE to 1
void generate_desc_array(int arr[]){
    for (int i = 0; i < ARRAY_SIZE; i++){
        arr[i] = ARRAY_SIZE - i;
    }
}

// Prints the given array
void print_array(int arr[]){
    printf("Array: ");
    for (int i = 0; i < ARRAY_SIZE; i++){
        printf("%d ", arr[i]);    
    }
    printf("\n");
}