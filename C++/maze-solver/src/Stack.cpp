#include "Stack.h"

Stack::~Stack() {
    while (m_first != nullptr) {
        pop();
    }
}

void Stack::push(Point data) {
    //add the input point to the current stack
    auto node = new Node();
    node->m_data = data;
    node->m_next = m_first;
    m_first = node;
}

void Stack::pop() {
    //checks if the stack is empty
    if (m_first == nullptr) {
        return;
    }
    //deletes the first element in the stack
    auto node = m_first;
    m_first = m_first->m_next;
    delete node;
}

Point Stack::peek() {
    //returns the data that is first in the stack
    if (m_first == nullptr) {
        return {};
    }
    return m_first->m_data;
}