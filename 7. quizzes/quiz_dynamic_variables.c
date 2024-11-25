#include <stdio.h>
#include <stdlib.h>
  
// Quiz: Dynamic variables (Dynamic memory allocation).
// Try to find the output of this program before running it.

void test_function(int **a);

int main(){
    int *p = NULL;
    test_function(&p);

    printf("Result = %d\n", (*p) * 2);
    
    free(p);
    p = NULL;
}

void test_function(int **a){
    *a = (int*)malloc(sizeof(int));
    *(*a) = 8;
}