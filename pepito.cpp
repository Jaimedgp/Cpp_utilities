#include <iostream>
#include <stdio.h>
#include <ctime>

int main (){

	char juan[] = "pepe";
    std::cout << "juan\n";
    std::cout << juan << std::endl;

    const time_t timer = time(0);

    tm *ltm = localtime(&timer);

    std::cout << timer <<std::endl;
    std::cout << "Year" << 1900 + ltm->tm_year<<std::endl;
    
    int rst = (120 % 60);
    int dvd = 10 / 60;
    std::cout << rst << " yes\n";
    std::cout << dvd << " yes\n";
    return 0;
}

double pedro(double num){

	double sum;
	sum = num*2.0/3.0;
	return sum;
}
