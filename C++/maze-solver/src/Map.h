#ifndef ASSIGNMENT_2_MAP_H
#define ASSIGNMENT_2_MAP_H


#include <fstream>
#include "Node.h"
#include "Stack.h"

class Map {
private:
    int m_length;
    int m_width;
    char **m_layout;
    std::ifstream m_map_file;
    Stack m_solution;
public:
    explicit Map(const std::string &file);

    static int check_length(const std::string &file);

    static int check_width(const std::string &file);

    Stack solve();

    Point find_entrance();

    Point find_exit();

    friend std::ostream &operator<<(std::ostream &output, Map &map);

    friend std::ofstream &operator<<(std::ofstream &output, Map &map);
};


#endif //ASSIGNMENT_2_MAP_H
