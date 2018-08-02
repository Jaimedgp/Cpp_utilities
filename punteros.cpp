#include <iostream>
#include <stdio.h>

void changeNumber (int *punt) {

	int *events;
	events = punt;
    for (int i = 0; i<4; ++i) {
        int yyy = *(events+i);
        std::cout << yyy << std::endl;
    }
}
int main () {
 
    int numero[4] = {1,2,3,4};
    std::cout << numero[1] << std::endl;

    int *puntero;

    puntero = numero;

    changeNumber(numero);

    std::cout << "El numero es: " << numero[1] << std::endl;
    
    return 0;
}
