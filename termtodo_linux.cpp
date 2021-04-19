//
//  main.cpp
//  termtodo
//
//  Created by mrmalac on 2021. 03. 21..
//

#include <iostream>
#include <string>
#include "init.hpp"

std::string username = getenv("USER");
std::string appPath = "*INSERT DESIRED PATH HERE*";

int main(int argc, char** argv) {
    std::filesystem::create_directory(appPath);
    init(argc, argv, appPath);
}
