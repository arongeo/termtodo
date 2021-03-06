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
std::string appPath = "/Users/"+username+"/Library/ApplicationSupport/termtodo/";

int main(int argc, char** argv) {
    std::__fs::filesystem::create_directory(appPath);
    init(argc, argv, appPath);
}
