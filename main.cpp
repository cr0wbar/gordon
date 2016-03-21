/* 
 * File:   main.cpp
 * Author: G. De Concini
 *
 * Created on 08 February 2016, 23:46
 */

#include <cstdlib>
#include <iostream>

#include "Gordon.h"
#include <time.h>

using namespace std;

void die(){
    exit(1);
}

void usage(char *progName){
    std::cout << "Usage:\n" << progName << " input.txt output.txt depth numberOfWords" << std::endl;
    die();
}

int main(int argc, char** argv) {

    if(argc != 4)
        usage(argv[0]);
    
    srand(0);
    const int numberOfWords = atoi(argv[3]);
   
    Gordon gordon(argv[1],2);
    gordon.writeOnFile(argv[2],numberOfWords);
    
    return 0;
}

