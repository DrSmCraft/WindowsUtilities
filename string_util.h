//
// Created by Riotoro on 1/2/2021.
//
#include <vector>

#ifndef WINDOWSUTILITIES_STRING_UTIL_H
#define WINDOWSUTILITIES_STRING_UTIL_H


extern std::string
replace_all(int pos, std::string original, const std::string &to_replace, const std::string &replacement);

extern int count_occurances(int pos, const std::string original, const std::string substring);

extern std::vector<std::string> split_by_substring(std::string original, std::string substring);

extern std::string ltrim(std::string str);

extern std::string rtrim(std::string str);

extern std::string trim(std::string str);

#endif //WINDOWSUTILITIES_STRING_UTIL_H
