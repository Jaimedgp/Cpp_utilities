// just play with files
#include <iostream>
#include <fstream>


void write () {

    std::ofstream myfile;
    
    myfile.open("WHYNOT.txt");
    myfile << "hola que tal esta todo el mundo \n";

    myfile.close();
}

char read () {


    std::ifstream yourfile("WHYNOT.txt");
    char texto[1024];

    bool iniciador = true; // booleano para cortar la lectura del archivo
    int i = 0; // elementos del array de char

    yourfile >> texto;
    std::cout << texto;
    std::cout << "\n yes \n";
        
    yourfile.close();

    return *texto;
}

int main () {

    write();

    char outPut = read();

    std::cout << outPut << std::endl;

    return 0;
}
