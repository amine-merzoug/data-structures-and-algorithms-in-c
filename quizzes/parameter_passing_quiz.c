#include <stdio.h>

// Quiz: Parameter passing to functions - Pass by value and pass by pointer.
// Try to find the output of this program before running it.

void mystery(int *y, int z, int *x){
    (*x) += 9;
    (*y)--;    
    z *= (*x); 
}

int main(){
    int x = 10, y = 20, z = 24; 

    printf("\n Before function call: x = %i, y = %i, z = %d\n", x, y, z);
    mystery(&z, x, &y);
    printf(" After function call:  x = %i, y = %i, z = %d\n\n", x, y, z);
}