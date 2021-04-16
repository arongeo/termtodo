//
//  conversions.hpp
//  termtodo
//
//  Created by mrmalac on 2021. 03. 22..
//

#ifndef CONVERSIONS_H
#define CONVERSIONS_H

#include <iostream>
#include <string>
#include <sstream>

int strToInt(const std::string &n) {
    int strToInt_num;
    std::stringstream ss;
    ss << n;
    ss >> strToInt_num;
    return strToInt_num;
}

std::string intToStr(int n) {
    std::string intToStr_num;
    std::stringstream ss;
    ss << n;
    ss >> intToStr_num;
    return intToStr_num;
}

std::string convertCharToStr(char* a) {
    std::stringstream ss;
    std::string result;
    ss << a;
    ss >> result;
    return result;
}

#endif /* CONVERSIONS_H */
