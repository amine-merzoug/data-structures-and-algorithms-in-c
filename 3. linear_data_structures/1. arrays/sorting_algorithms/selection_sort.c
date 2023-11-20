#include <stdio.h>

// Remember: use constants instead of magic numbers
const int ARRAY_SIZE = 12; 

// To assess the efficiency of Selection Sort, use a large array
// const int ARRAY_SIZE = 500000;

void generate_desc_array(int[]);
void print_array(int[]);
void selection_sort(int[]);

int main(){
    // int array[] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    
    int array[ARRAY_SIZE];
    
    generate_desc_array(array);
    print_array(array);

    selection_sort(array);
    print_array(array);
}

// Sorts the given array using Selection Sort (time complexity O(N^2))
void selection_sort(int arr[]){
    for (int i = 0; i < ARRAY_SIZE - 1; i++){
        // Step 1: find the min in the remaining unsorted array.
        int min_index = i;
        for (int j = i + 1; j < ARRAY_SIZE; j++){
            if (arr[j] < arr[min_index]){
                min_index = j;
            }
        }

        // Step 2: swap the found min with the first element in the remaining unsorted array.
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
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