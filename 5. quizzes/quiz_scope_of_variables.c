#include <stdio.h>

// Quiz: Variable scope (variable lifetime) - Local vs. global scope.
// Try to find the output of this program before running it.

void quiz_function(){
    int j = 5;
    for (int i = 0; i < 6; i += 2){ 
        for (int i = 3; i < 10; i *= 2){ 
            while (j < 10){
                int i = 10;
                j += 2;
            }
        }
        printf("%i ", i);
    }
}

int main(){ 
    quiz_function(); 
}