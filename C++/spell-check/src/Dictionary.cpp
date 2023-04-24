//
// Created by w0457048 on 2023-02-27.
//

#include <iostream>
#include "Dictionary.h"

Dictionary::Dictionary(const std::string &file) {
    std::string word;
    m_file.open(file);
    //read data from file object and put it into the BST
    while (getline(m_file, word)) {
        m_words.insert(word);
    }
    m_file.close();
}

std::ostream &operator<<(std::ostream &output, Dictionary &dictionary) {
    output << dictionary.m_words;
    return output;
}

void Dictionary::spell_check(const std::string &test_file) {
    std::string word;
    int current_character;
    std::ifstream file;
    file.open(test_file);
    while (!file.eof()) {
        current_character = file.get();
        //see if the current character is an uppercase/lowercase letter
        if ('A' <= current_character && current_character <= 'Z') {
            //convert uppercase characters to their lowercase versions
            word += (char) (current_character + 32);
        } else if ( 'a' <= current_character && current_character <= 'z') {
            word += (char) current_character;
        } else {
            //current character is not a letter
            //see if the current word is in the dictionary
            if (!m_words.find(word)) {
                //output words not in the dictionary to the console
                std::cout << word << std::endl;
            }
            //reset the word variable to empty after searching
            word = "";
        }
    }
    file.close();
}
