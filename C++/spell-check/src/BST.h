//
// Created by w0457048 on 2023-02-22.
//

#ifndef ASSIGNMENT_3_BST_H
#define ASSIGNMENT_3_BST_H


#include <ostream>
#include "Node.h"

class BST {
    Node *m_root{nullptr};

    void insert(const std::string &data, Node *&node);

    void print_tree(std::ostream &output, Node *&node, int indent);

    static void rotate_right(Node *&point);

    static void rotate_left(Node *&point);

    int balance(Node *&node);

    bool find(std::string word, Node *&node);

public:
    ~BST();

    void insert(const std::string &data);

    void remove(std::string data);

    bool find(std::string word);

    void balance();

    friend std::ostream &operator<<(std::ostream &output, BST &bst);
};


#endif //ASSIGNMENT_3_BST_H
