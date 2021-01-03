//
// Created by DrSmCraft on 1/3/2021.
//

#include <iostream>
#include <cstring>

int main(int argv, char *args[]) {
    printf("\n");

    if (argv > 1) {
        if (argv == 2) {
            if (strcmp(args[1], "-h") == 0 || strcmp(args[1], "--help") == 0) {
                printf("Microsoft Logo implement by DrSmCraft\n");
                printf("Ascii Art taken from https://ascii.co.uk/art/microsoft\n");
            }
        } else {
            printf("ERROR: This program does not accept any arguments other than -h");
        }
        printf("\n");
        return 0;
    }
    printf("           _                           __ _   \n"
           "          (_)                         / _| |  \n"
           " _ __ ___  _  ___ _ __ ___  ___  ___ | |_| |_ \n"
           "| '_ ` _ \\| |/ __| '__/ _ \\/ __|/ _ \\|  _| __|\n"
           "| | | | | | | (__| | | (_) \\__ \\ (_) | | | |_ \n"
           "|_| |_| |_|_|\\___|_|  \\___/|___/\\___/|_|  \\__|\n");
    printf("\n");

    return 0;
}

