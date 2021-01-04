//
// Created by Riotoro on 1/4/2021.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <windows.h>

int main(int argv, char *args[]) {

    int mode = CREATE_NEW;
    if (argv < 2) {
        printf("Error: No files specified!");
        return -1;
    }

    for (int i = 0; i < argv; ++i) {

//        char *command = strcat((char *) "echo > ", args[i]);
//        printf("%s\n", command);
//        system(command);

        if (strcmp(args[i], "-f") == 0) {
            mode = CREATE_ALWAYS;
        } else if(strcmp(args[i], "-?") == 0 || strcmp(args[i], "-h") == 0 || strcmp(args[i], "--help") == 0){
            printf("Touch implementation for Windows by DrSmCraft");

        }


        HANDLE h = CreateFile(args[i],    // name of the file
                              GENERIC_WRITE, // open for writing
                              0,             // sharing mode, none in this case
                              0,             // use default security descriptor
                              mode,
                              FILE_ATTRIBUTE_NORMAL,
                              0);


        if (!h) {
            printf("ERROR: Failed to create %s\n", args[i]);
        }
    }

}