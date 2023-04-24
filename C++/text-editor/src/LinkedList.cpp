#include <iostream>
#include <fstream>
#include <utility>
#include "LinkedList.h"

std::ostream & operator<<(std::ostream& output, LinkedList& list) {
//  overloads the << operator for outputting to the console
    auto node = list.m_start;

    while (node != nullptr) {
        output << node->m_data << std::endl;
        node = node->m_next;
    }
    return output;
}

std::ofstream & operator<<(std::ofstream& output, LinkedList& list) {
//  overloads the << operator for outputting to the file
    auto node = list.m_start;

    while (node != nullptr) {
        output << node->m_data << "\n";
        node = node->m_next;
    }
    return output;
}

void LinkedList::add(std::string input) {
    auto node = new LinkedListNode();

//  adds a new node with the input data to the linkedlist
    node->m_data = std::move(input);
    if (m_start == nullptr) {
        m_start = node;
    } else {
        LinkedListNode* curr = m_start;
        LinkedListNode* prev = nullptr;
        while (curr != nullptr) {
            prev = curr;
            curr = curr->m_next;
        }
        prev->m_next = node;
    }
    m_size++;
}

void LinkedList::deletelines(int start, int end, int index) {
    auto node = m_start;
    LinkedListNode* prev = nullptr;
    auto count{1};

//  if no start value is set or is invalid, use the start of the linked list
    if (start < 1) {
        start = index - 1;
    }
    while (node != nullptr) {
//      go through the list until you reach the index of the start
        if (count++ >= start) {
            break;
        }
        prev = node;
        node = node->m_next;
    }
//  delete the node at the index if it exists
    if (node != nullptr) {
        if (prev == nullptr) {
            m_start = node->m_next;
        } else {
            prev->m_next = node->m_next;
        }
        delete node;
        m_size--;
    }
    if (start < end) {
//      repeat the function until all lines required are deleted
        deletelines(start, end - 1, index);
    }
}

void LinkedList::listlines(int start, int end) {
    auto node = m_start;
    auto count{1};

//  lists all lines whose index is between the two set values or if the value is negative, to ignore it
    while (node != nullptr) {
        count++;
        if (start + 1 <= count) {
            if ((end < 1 && (start + 1 == count || start < 1)) || end + 1 >= count) {
                std::cout << count - 1 << ">" << node->m_data << std::endl;
            }
        }
        node = node->m_next;
    }
}

void LinkedList::insert(std::string data, int index) {
    auto curr = m_start;
    auto node = new LinkedListNode();
    LinkedListNode* prev = nullptr;
    auto count{1};

//  checks to see if you are inserting to the end of the current list
    if (index > m_size) {
        return add(data);
    }
    node->m_data = data;
//  go to the index of the insert
    while (curr != nullptr) {
        if (count == index) {
            break;
        }
        count++;
        prev = curr;
        curr = curr->m_next;
    }
//  check if the insert is happening at the start of the list
    if (prev == nullptr) {
        node->m_next = m_start;
        m_start = node;
    } else {
        node->m_next = prev->m_next;
        prev->m_next = node;
    }
    m_size++;
}

int LinkedList::movecursor(int start) {
//  returns the cursor position closest to the input value that is within the size of the linked list with an
//  extra position at the end
    if (start >= 1) {
        if (m_size < start){
            return m_size + 1;
        }
        return start;
    }
    return 1;
}
