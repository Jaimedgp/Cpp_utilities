#include <iostream>
#include <stdio.h>

int main () {

    int contador;
    char *texto;

    std::cin >> contador; 
    texto = "Hello world!!! \n";
    
    for (int i=0; i < contador; i++) {
        std::cout << texto;
    }
	return 0;
}


