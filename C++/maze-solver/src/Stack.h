#ifndef ASSIGNMENT_2_STACK_H
#define ASSIGNMENT_2_STACK_H

#include <ostream>
#include "Node.h"

class Stack {
private:
    Node *m_first{nullptr};
public:
    ~Stack();

    void push(Point data);

    void pop();

    Point peek();
};


#endif //ASSIGNMENT_2_STACK_H