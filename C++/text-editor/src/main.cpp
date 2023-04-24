#include <iostream>
#include <sstream>
#include <fstream>
#include "LinkedList.h"

int main(int argc, char* argv[]) {
    std::ifstream read;
    std::ofstream file;
    std::string input;
    std::stringstream ss;
    char command;
    int start = -1, end = -1, cursor = 1;
    LinkedList File;

    if (argc <= 1) {
        //if no argument is specified, return that no file was specified before closing
        std::cout << "No file specified" << std::endl;
        return 0;
    }
    //open the file if the file already exists
    read.open(argv[1]);
    if (read.is_open()) {
        while (std::getline(read, input)) {
            //get the text saved in the file
            File.insert(input, cursor);
            cursor = File.movecursor(cursor + 1);
        }
        read.close();
        File.listlines(start, end);
        //close the file once the reading is done and list the text
    } else {
        std::cout << "Could not find the file, creating the file..." << std::endl;
    }
    while (true) {
        //writes the current line in the console
        std::cout << cursor << ">";
        std::getline(std::cin, input);
        ss.str("");
        ss.clear();
        ss << input;
        //checks if the line input has a character followed by two numbers
        ss >> command >> start >> end;
        if (!ss) {
            command = '\0';
            start = -1;
            end = -1;
            ss.str("");
            ss.clear();
            ss << input;
            //checks if the line input has a character followed by one number
            ss >> command >> start;
            if (!ss) {
                command = '\0';
                start = -1;
                end = -1;
                ss.str("");
                ss.clear();
                ss << input;
                //checks if the input is only one character
                if (input.length() == 1) {
                    ss >> command;
                } else {
                    command = '\0';
                }
            }
        }
        switch (command) {
            case 'I':
                //moves the cursor to the specified line of start of file
                cursor = File.movecursor(start);
                break;
            case 'D':
                //deletes the current line, the line at the specified number or the specified range of lines
                File.deletelines(start, end, cursor);
                cursor = File.movecursor(cursor);
                break;
            case 'L':
                //Lists the entire file, the line at the specified number or the specified range of lines
                File.listlines(start, end);
                break;
            case 'E':
                //saves the file to the specified file, creating the file if needed, then exiting the program
                file.open(argv[1]);
                file << File;
                file.close();
                return 0;
            default:
                //inserts what the user input if the input was not one of the above commands
                File.insert(input, cursor);
                cursor = File.movecursor(cursor + 1);
                break;
        }
    }
}