// just play with files
#include <iostream>
#include <fstream>


void write () {

    std::ofstream myfile;
    
    myfile.open("WHYNOT.txt");
    myfile << "hola que tal esta todo el mundo \n";

    myfile.close();
}

char  read () {


    std::ifstream yourfile;
    char texto[1024];

    yourfile.open("WHYNOT.txt");
    yourfile >> texto;

    yourfile.close();

    static char cp = texto;

    return cp;
}

int main () {

    write();
    char outPut = read();

    std::cout << outPut;

    return 0;
}
