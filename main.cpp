//
// Created by Riotoro on 1/2/2021.
//

#include <cstdio>
#include <string>
#include "string_util.h"

int main(){

    std::string orig = "Hello, World, And, All, People";

    int count = count_occurances(0, orig, ",");
    printf("Count: %i\n", count);

    std::string* array = split_by_substring(orig, ", ");

    for (int i = 0; i < array->size(); i++) {
        printf("%s\n", array[i].c_str());

    }


    return 0;

}