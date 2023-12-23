#include <stdio.h>

// Quiz: Recursion.
// Try to find the output of this C program before running it.

int mystery(int n){
    if (n < 10){
        return n;
    }
    else {
        int a = n / 10; 
        int b = n % 10; 
        return mystery(a + b);  
    }
}

int main(){
    printf("\n mystery(2023) = %i\n\n", mystery(2023));
}