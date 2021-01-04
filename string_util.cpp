//
// Created by Riotoro on 1/2/2021.
//
#include <string>
#include <iostream>
#include "string_util.h"

const std::string WHITESPACE_CHARS = "\t\n\v\f\r  ";
const std::string EMPTY = "";

std::string replace_all(int pos, std::string original, const std::string &to_replace, const std::string &replacement) {
    int next = pos;
    next = original.find(to_replace, next);
    while (next != std::string::npos) {
        original.replace(next, to_replace.size(), replacement);
        next = original.find(to_replace, next + 1);

    }
    return original;
}

int count_occurances(int pos, const std::string original, const std::string substring) {
    int total = 0;
    int next = pos;
    next = original.find(substring, next);
    while (next != std::string::npos) {
        total++;
        next = original.find(substring, next + 1);

    }

    return total;
}

std::vector<std::string> split_by_substring(std::string original, std::string substring) {
    int count = count_occurances(0, original, substring);
    std::vector<std::string> list;


    int index = 0;
    int next = 0;
    std::string token;
    while ((next = original.find(substring)) != std::string::npos) {
        token = original.substr(0, next);
        list.push_back(token);
        original.erase(0, next + substring.length());
        index++;
    }
    list.push_back(original.substr(0));
    return list;
}

std::string ltrim(std::string str) {

    str.erase(0, str.find_first_not_of(WHITESPACE_CHARS));
    return str;
}


std::string rtrim(std::string str) {

    str.erase(0, str.find_first_not_of(WHITESPACE_CHARS));
    return str;
}

std::string trim(std::string str) {

    ltrim(str);
    rtrim(str);
    return str;
}