#include <iostream>
#include "Map.h"

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        //if 1 or fewer arguments are specified, return program argument requirements before closing
        std::cout << "Source file must be specified" << std::endl;
        return 0;
    }
    Map *test = new Map(argv[1]);
    std::ofstream solution;
    //check if a destination file was set and outputs to console if there wasn't
    if (argc > 2) {
        solution.open(argv[2]);
        solution << *test;
        solution.close();
    } else {
        std::cout << *test;
    }
    return 0;
}