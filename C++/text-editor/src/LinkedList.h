#ifndef ASSIGNMENT1_LINKEDLIST_H
#define ASSIGNMENT1_LINKEDLIST_H

#include <string>
#include <ostream>
#include "LinkedListNode.h"

class LinkedList {
private:
    LinkedListNode* m_start{nullptr};
    int m_size{0};
public:
    LinkedList() = default;

    void add(std::string input);
    int movecursor(int start);
    void insert(std::string data, int index);
    void deletelines(int start, int end, int index);
    void listlines(int start, int end);

    friend std::ostream& operator<<(std::ostream& output, LinkedList& list);
    friend std::ofstream& operator<<(std::ofstream& output, LinkedList& list);
};


#endif
