//
//  init.hpp
//  termtodo
//
//  Created by mrmalac on 2021. 03. 23..
//

#ifndef INIT_H
#define INIT_H

#include <iostream>
#include <string>
#include "todo.hpp"
#include "conversions.hpp"

void init(int argc, char** argv, std::string path) {
    checkForDir(path);
    if (argc == 1) {
        printHelp();
    }
    load_todos(path);
    if (argc == 2) {
        if (std::string(argv[1]) == "list") {
            list_todos();
        }
        if (std::string(argv[1]) == "-h" | std::string(argv[1]) == "help") {
            printHelp();
        }
        if (std::string(argv[1]) != "list" && std::string(argv[1]) != "-h" && std::string(argv[1]) != "help") {
            std::cout << "Invalid third argument. Please look at the help page with -h." << std::endl;
        }
    }
    if (argc == 3) {
        if (std::string(argv[1]) == "del") {
            delTodo(std::string(argv[2]));
            save_todos(path);
            std::cout << "Deleted." << std::endl;
        }
    }
    if (argc == 4) {
        if (std::string(argv[1]) == "add") {
            addTodo(std::string(argv[2]), findStat(std::string(argv[3])));
            save_todos(path);
            std::cout << "Added." << std::endl;
        }
        if (std::string(argv[1]) == "set") {
            set(strToInt(std::string(argv[2])), std::string(argv[3]), path);
        }
        if (std::string(argv[1]) == "setstat") {
            setstat(strToInt(std::string(argv[2])), std::string(argv[3]), path);
        }
    }
}

#endif /* INIT_H */
