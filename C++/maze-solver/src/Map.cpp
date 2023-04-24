#include <cstring>
#include <iostream>
#include "Map.h"
#include "Stack.h"

Map::Map(const std::string &file) {
    //find the size of the map
    m_length = check_length(file);
    m_width = check_width(file);
    m_layout = new char *[m_length];
    //creates an empty character array that is the size of the map
    for (int count = 0; count < m_length; count++) {
        m_layout[count] = new char[m_width];
        std::memset(m_layout[count], ' ', m_width * sizeof(char));
    }
    //loads the map into the array from the file
    m_map_file.open(file);
    for (int i = 0; i < m_length; i++) {
        for (int j = 0; j <= m_width; j++) {
            m_layout[i][j] = (char) m_map_file.get();
        }
    }
    m_solution = solve();
    //places the found solution into the character array
    while (m_solution.peek() != Point()) {
        auto test = m_solution.peek();
        m_layout[test.m_y_position][test.m_x_position] = '#';
        m_solution.pop();
    }
}

std::ostream &operator<<(std::ostream &output, Map &map) {
    //iterates through the character array to output each character
    for (int i = 0; i < map.m_length; i++) {
        for (int j = 0; j < map.m_width; j++) {
            //replaces tested routes with blank spaces
            if (map.m_layout[i][j] == '*') {
                output << ' ';
            } else {
                output << map.m_layout[i][j];
            }
        }
        output << std::endl;
    }
    return output;
}

std::ofstream &operator<<(std::ofstream &output, Map &map) {
    //iterates through the character array to output each character
    for (int i = 0; i < map.m_length; i++) {
        for (int j = 0; j < map.m_width; j++) {
            //replaces tested routes with blank spaces
            if (map.m_layout[i][j] == '*') {
                output << ' ';
            } else {
                output << map.m_layout[i][j];
            }
        }
        output << '\n';
    }
    return output;
}

int Map::check_length(const std::string &file) {
    int max_length = 0;
    std::string test;
    std::ifstream read;
    read.open(file);
    //finds the longest line in the text file
    if (read.is_open()) {
        while (std::getline(read, test)) {
            //check if the current line is longer than the current longest
            if (test.length() > max_length) {
                max_length = (int) test.length();
            }
        }
        read.close();
        return max_length;
    } else {
        return 0;
    }
}

int Map::check_width(const std::string &file) {
    std::string test;
    std::ifstream read;
    int count = 0;
    read.open(file);
    //finds how many lines the file has
    if (read.is_open()) {
        while (std::getline(read, test)) {
            count++;
        }
        read.close();
        return count;
    } else {
        return 0;
    }
}

Stack Map::solve() {
    Point entrance = find_entrance();
    Point exit = find_exit();
    m_solution.push(entrance);
    //place a star at every point the solution goes to
    m_layout[entrance.m_y_position][entrance.m_x_position] = '*';
    //loops until maze is solved
    while (exit != m_solution.peek()) {
        Point CPosition = m_solution.peek();
        //check the position to the right of the current point to see if it is a blank space
        if (m_layout[CPosition.m_y_position][CPosition.m_x_position + 1] == ' ') {
            Point next;
            next.m_x_position = CPosition.m_x_position + 1;
            next.m_y_position = CPosition.m_y_position;
            //adds the space to the solution stack and fills it with a star
            m_solution.push(next);
            m_layout[next.m_y_position][next.m_x_position] = '*';
        //check the position to the bottom of the current point to see if it is a blank space
        } else if (m_layout[CPosition.m_y_position + 1][CPosition.m_x_position] == ' ') {
            Point next;
            next.m_x_position = CPosition.m_x_position;
            next.m_y_position = CPosition.m_y_position + 1;
            //adds the space to the solution stack and fills it with a star
            m_solution.push(next);
            m_layout[next.m_y_position][next.m_x_position] = '*';
        //check the position to the left of the current point to see if it is a blank space
        } else if (m_layout[CPosition.m_y_position][CPosition.m_x_position - 1] == ' ') {
            Point next;
            next.m_x_position = CPosition.m_x_position - 1;
            next.m_y_position = CPosition.m_y_position;
            //adds the space to the solution stack and fills it with a star
            m_solution.push(next);
            m_layout[next.m_y_position][next.m_x_position] = '*';
        //check the position to the top of the current point to see if it is a blank space
        } else if (m_layout[CPosition.m_y_position - 1][CPosition.m_x_position] == ' ') {
            Point next;
            next.m_x_position = CPosition.m_x_position;
            next.m_y_position = CPosition.m_y_position - 1;
            //adds the space to the solution stack and fills it with a star
            m_solution.push(next);
            m_layout[next.m_y_position][next.m_x_position] = '*';
        } else {
            //if there is no way to go, remove the point from the list
            m_solution.pop();
        }
    }
    return m_solution;
}

Point Map::find_entrance() {
    //finds the first blank space on the outside of the array
    for (int i = 0; i < m_length; i++) {
        for (int j = 0; j < m_width; j++) {
            if ((i == 0 || i == m_length - 1) || (j == 0 || j == m_width - 1)) {
                if (m_layout[i][j] == ' ') {
                    return {j, i};
                }
            }
        }
    }
    return {};
}

Point Map::find_exit() {
    //finds the last blank space on the outside of the array
    int x_position = 0, y_position = 0;
    for (int i = 0; i < m_length; i++) {
        for (int j = 0; j < m_width; j++) {
            if ((i == 0 || i == m_length - 1) || (j == 0 || j == m_width - 1)) {
                if (m_layout[i][j] == ' ') {
                    x_position = j;
                    y_position = i;
                }
            }
        }
    }
    return {x_position, y_position};
}