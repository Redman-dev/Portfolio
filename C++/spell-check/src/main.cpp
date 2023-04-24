#include <iostream>
#include <algorithm>
#include "Dictionary.h"

using namespace std;

int main(int argc, char *argv[]) {
    //check if program was given 2 arguments
    if (argc > 2) {
        auto *dictionary = new Dictionary(argv[2]);
        //Dictionary dictionary {argv[2]};
        dictionary->spell_check(argv[1]);
        if (argc > 3) {
            //print out sorted binary search tree to file if file specified
            std::ofstream tree;
            tree.open(argv[3]);
            tree << *dictionary;
            tree.close();
        }
    } else {
        std::cout << "Program requires 2 arguments at least, file to search and dictionary file" << std::endl;
    }
    return 0;
}