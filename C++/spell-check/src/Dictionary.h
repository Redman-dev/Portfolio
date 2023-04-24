//
// Created by w0457048 on 2023-02-27.
//

#ifndef ASSIGNMENT_3_DICTIONARY_H
#define ASSIGNMENT_3_DICTIONARY_H


#include <fstream>
#include "BST.h"

class Dictionary {
    BST m_words;
    std::ifstream m_file;
public:
    explicit Dictionary(const std::string &file);

    void spell_check(const std::string &test_file);

    friend std::ostream &operator<<(std::ostream &output, Dictionary &dictionary);
};


#endif //ASSIGNMENT_3_DICTIONARY_H
