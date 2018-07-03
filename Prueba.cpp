#include <iostream>
#include <stdio.h>

int main () {
    int array[5][20];

    for (int i=0; i<20; i++){
        array[0][i] = i;
    }

    for (int i = 1; i<5; i++){
        for (int a = 0; a < 19; a++){
            array[i][a] = array[i-1][a] + array[i-1][a+1];
        }
    }
        
    for (int i=0; i<5; i++){
        for (int a=0; a<20; a++){

            std::cout << array[i][a];
            std::cout << " \t";
        }

        std::cout << "\n";
    }

    return 0;
    
}


