//
// Created by Riotoro on 1/2/2021.
//
#include <string>
#include <iostream>
#include "string_util.h"


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

std::string *split_by_substring(std::string original, std::string substring) {
    int count = count_occurances(0, original, substring);
    std::string *array = new std::string[count + 1];

    int index = 0;
    int next = 0;
    std::string token;
    while ((next = original.find(substring)) != std::string::npos) {
        token = original.substr(0, next);
        array[index] = token;
        original.erase(0, next + substring.length());
        index++;
    }
    return array;
}