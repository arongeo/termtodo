//
//  todo.hpp
//  termtodo
//
//  Created by mrmalac on 2021. 03. 21..
//

#ifndef TODO_H
#define TODO_H

// Define the Maximum of number of todos, and the maximum number of characters in a string
#define MAX_ARR_SIZE 256
#define SPACE_SIZE 35

// Include filestream
#include <iostream>
#include <fstream>
#include <string>
#include "conversions.hpp"

// Define an todosay of the todos
std::string todos[MAX_ARR_SIZE] = {};
int status[MAX_ARR_SIZE] = {}; // Statuses: 0="-no-status-" 1="pending" 2="done"
int num;

void printHelp() {
    std::cout << "Argument        \tExplanation" << std::endl;
    std::cout << "-h / help       \tHelp Command: Brings out this menu." << std::endl;
    std::cout << "list            \tShows all of the To-Do's, their ID and Status." << std::endl;
    std::cout << "add             \tAdds a To-Do to the To-Do list. Correct use: termtodo add '<To-Do>' '<status>'" << std::endl;
    std::cout << "                \tStatus can be: none, pending and done" << std::endl;
    std::cout << "del             \tDeletes a To-Do from the To-Do list. Correct use: termtodo del <ID of To-Do>" << std::endl;
    std::cout << "set             \tSet a To-Do. Correct use: termtodo set <ID of To-Do> '<Set to>'" << std::endl;
    std::cout << "setstat         \tSet a To-Do's status. Correct use: termtodo setstat <ID of To-Do> <Status to set>" << std::endl;
    std::cout << "<indev>set      \tSet a To-Do. Correct use: termtodo set <ID of To-Do> '<Set to>'" << std::endl;
    std::cout << "<indev>setstat  \tSet a To-Do's status. Correct use: termtodo setstat <ID of To-Do> <Status to set>" << std::endl;
    std::cout << "                \tStatus can be: none, pending and done" << std::endl;
}

void list_todos() {
    std::cout << "ID\tTo-Do                                   Status" << std::endl;
    for (int i = 0; i<num; i++) {
        int currTodoLen = todos[i].length() - 5;
        std::string spaces = "";
        for (int j = 0; j<SPACE_SIZE-currTodoLen; j++) {
            spaces = spaces + " ";
        }
        switch (status[i]) {
            case 0: {
                std::cout << i << "\t" << todos[i] << spaces << "-no-status-" << std::endl;
                break;
            }
            case 1: {
                std::cout << i << "\t" << todos[i] << spaces << "--pending--" << std::endl;
                break;
            }
            case 2: {
                std::cout << i << "\t" << todos[i] << spaces << "---done---" << std::endl;
                break;
            }
        }
        spaces = "";
    }
}

int findStat(std::string str_stat) {
    if (str_stat == "none" | str_stat == "None" | str_stat == "0" | str_stat == "NONE") {
        return 0;
    }
    if (str_stat == "pending" | str_stat == "Pending" | str_stat == "1" | str_stat == "PENDING") {
        return 1;
    }
    if (str_stat == "done" | str_stat == "Done" | str_stat == "2" | str_stat == "DONE") {
        return 2;
    }
    return 3;
}

void save_todos(std::string path);

void setstat(int id, std::string str_stat, std::string path) {
    int stat = findStat(str_stat);
    status[id] = stat;
    save_todos(path);
}

void set(int id, std::string todo, std::string path) {
    todos[id] = todo;
    save_todos(path);
}

void addTodo(std::string todo, int stat) {
    if (stat == 3) {
        std::cout << "Invalid Status." << std::endl;
        exit(1);
    }
    todos[num] = todo;
    status[num] = stat;
    num = num + 1;
}

void delTodo(std::string str_id) {
    int int_id = strToInt(str_id);
    for (int i = int_id; i<num; i++) {
        todos[i] = todos[i+1];
        status[i] = status[i+1];
    }
    if (num != 0) {
        num = num - 1;
    }
}

void load_todos(std::string path) {
    std::ifstream todoFile (path+"todos.todo");
    std::ifstream numFile (path+"todo_num.todo");
    std::ifstream statFile (path+"statuses.todo");
    
    std::string n;
    getline(numFile, n);
    if (n == "") {
        n = "0";
    }
    num = strToInt(n);
    
    std::string todo;
    std::string stat;
    for (int i = 0; i<num; i++) {
        getline(todoFile, todo);
        todos[i] = todo;
        getline(statFile, stat);
        status[i] = strToInt(stat);
    }
    todoFile.close();
    numFile.close();
}

void save_todos(std::string appPath) {
    std::ofstream todoFile;
    std::ofstream todoNumFile;
    std::ofstream todoStatFile;
    todoFile.open(appPath+"todos.todo", std::ofstream::out | std::ofstream::trunc);
    todoNumFile.open(appPath+"todo_num.todo", std::ofstream::out | std::ofstream::trunc);
    todoStatFile.open(appPath+"statuses.todo", std::ofstream::out | std::ofstream::trunc);
    std::string todoRes;
    std::string statRes;
    for (int i = 0; i<num; i++) {
        todoRes = todoRes + todos[i] + "\n";
        statRes = statRes + intToStr(status[i]) + "\n";
    }
    todoNumFile << intToStr(num);
    todoFile << todoRes;
    todoStatFile << statRes;
    todoStatFile.close();
    todoNumFile.close();
    todoFile.close();
}

#endif /* TODO_H */
