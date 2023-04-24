//
// Created by w0457048 on 2023-02-22.
//

#include <iostream>
#include <iomanip>
#include <utility>
#include "BST.h"

void BST::insert(const std::string &data) {
    insert(data, m_root);
    balance();
}

void BST::insert(const std::string &data, Node *&node) {
    //check to see if the node is null
    if (node == nullptr) {
        node = new Node();
        node->m_data = data;
        //check to see on what side of the current node the data should be on
    } else if (data > node->m_data) {
        insert(data, node->m_right);
    } else if (data < node->m_data) {
        insert(data, node->m_left);
        //if it is equal then it is a duplicate value
    } else {
        std::cout << "Duplicate string: " << data << std::endl;
    }
}

std::ostream &operator<<(std::ostream &output, BST &bst) {
    bst.print_tree(output, bst.m_root, 0);
    return output;
}

void BST::print_tree(std::ostream &output, Node *&node, int indent) {
    if (node != nullptr) {
        //recursive loop for printing out the entire BST
        print_tree(output, node->m_right, indent + 16);
        output << std::setw(indent) << node->m_data << std::endl;
        print_tree(output, node->m_left, indent + 16);
    }
}

void BST::remove(std::string data) {
    auto node = m_root;
    Node *parent = nullptr;
    //loop to find the node that we are attempting to delete
    while (node != nullptr) {
        if (node->m_data > data) {
            parent = node;
            node = node->m_left;
        } else if (node->m_data < data) {
            parent = node;
            node = node->m_right;
        } else {
            break;
        }
    }
    //check to see if the node exists
    if (node == nullptr) {
        std::cout << "Couldn't find the node: " + data << std::endl;
        return;
    }
    //create a subtree from the nodes below the current node if there are any
    auto subtree = node->m_left;
    if (subtree == nullptr) {
        subtree = node->m_right;
    }
    //check if both sides of the node we are deleting are not null
    if (node->m_left != nullptr && node->m_right != nullptr) {
        auto successor = node->m_right;
        parent = node;
        //find the rightmost node of the left branch
        while (successor->m_right != nullptr) {
            parent = successor;
            successor = successor->m_right;
        }
        //replace the data in the node we are trying to delete with the found node
        node->m_data = successor->m_data;
        //node to delete is changed to the node we found
        node = successor;
        parent->m_right = nullptr;
        //if we are deleting the root point, just make the subtree the new root
    } else if (parent == nullptr) {
        m_root = subtree;
        //check if one side doesn't have nodes below it
    } else if (node->m_left == nullptr || node->m_right == nullptr) {
        //replace the node with its subtree
        if (node == parent->m_left) {
            parent->m_left = subtree;
        } else {
            parent->m_right = subtree;
        }
    }
    delete node;
    balance();
}

void BST::rotate_right(Node *&point) {
    //rotate around the point to the right
    auto node = point;
    point = point->m_left;
    node->m_left = point->m_right;
    point->m_right = node;
}

void BST::rotate_left(Node *&point) {
    //rotate around the point to the right
    auto node = point;
    point = point->m_right;
    node->m_right = point->m_left;
    point->m_left = node;
}

void BST::balance() {
    balance(m_root);
}

int BST::balance(Node *&node) {
    //check to see if we have reached a null pointer
    if (node == nullptr) {
        return 1;
    }
    int left = 1;
    int right = 1;
    //balance the child nodes on the left and right first if they exist
    if (node->m_left != nullptr) {
        //store the heights of the left branch from the bottom
        left = balance(node->m_left);
    }
    if (node->m_right != nullptr) {
        //store the heights of the right branch from the bottom
        right = balance(node->m_right);
    }
    //check if it needs to be right rotated
    if (left - 1 > right) {
        if (node->m_left->m_right != nullptr && node->m_left->m_left != nullptr) {
            //check if we need to do a left rotation before right rotating
            if (balance(node->m_left->m_right) > balance(node->m_left->m_left)) {
                rotate_left(node->m_left);
            }
        }
        rotate_right(node);
        //change the lengths of the branches to reflect the rotation
        left -= 1;
        right += 1;
        //check if it needs to be left rotated
    } else if (right - 1 > left) {
        if (node->m_right->m_right != nullptr && node->m_right->m_left != nullptr) {
            //check if a right rotation is needed on the child nodes
            if (balance(node->m_right->m_right) < balance(node->m_right->m_left)) {
                rotate_right(node->m_right);
            }
        }
        rotate_left(node);
        //change the lengths to reflect the rotation
        left += 1;
        right -= 1;
    }
    //return the longer branches height plus 1 for the current node
    if (right > left) {
        return right + 1;
    }
    return left + 1;
}

bool BST::find(std::string word) {
    return find(std::move(word), m_root);
}

bool BST::find(std::string word, Node *&node) {
    //check to see if the word we are looking for is blank
    if (word.empty()) {
        return true;
    }
    //check to see if we have reached the bottom of the tree
    if (node == nullptr) {
        return false;
        //check if the word is to the left or the right of the current node
    } else if (word < node->m_data) {
        return find(word, node->m_left);
    } else if (word > node->m_data) {
        return find(word, node->m_right);
    }
    //if the word shouldn't be to the left or to the right
    //then the current node must match the word we are looking for
    return true;
}

BST::~BST() {
    while (m_root != nullptr) {
        remove(m_root->m_data);
    }
}
