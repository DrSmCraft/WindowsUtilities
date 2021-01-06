#include <iostream>
#include <cstring>
#include <Windows.h>


int main(int argv, char *args[]) {

    bool no_animation = false;

    printf("\n");

    if (argv > 1) {
        for (int i = 1; i < argv; i++) {
            if (strcmp(args[i], "-h") == 0 || strcmp(args[i], "-?") == 0 || strcmp(args[i], "--help") == 0) {
                printf("Microsoft Logo implement by DrSmCraft\n");
                printf("Ascii Art taken from https://ascii.co.uk/art/microsoft\n");
                return 0;
            } else if (strcmp(args[i], "-n") == 0 || strcmp(args[i], "--none") == 0) {
                no_animation = true;
            } else {

                printf("ERROR: Unknown argument \"%s\"\nThis program does not accept any arguments other than -? and -n",
                       args[i]);
                return -1;

            }
        }

    }
    printf("\n");


    if (!no_animation) {
        int slide_index = 0;

        while (slide_index < 10) {

            std::cout.flush();
            system("cls");

            for (int i = 0; i < slide_index; i++) {
                std::cout << "\t";

            }
            std::cout << "           _                           __ _   \n";

            for (int i = 0; i < slide_index; i++) {
                std::cout << "\t";
            }
            std::cout << "          (_)                         / _| |  \n";


            for (int i = 0; i < slide_index; i++) {
                std::cout << "\t";

            }
            std::cout << " _ __ ___  _  ___ _ __ ___  ___  ___ | |_| |_ \n";

            for (int i = 0; i < slide_index; i++) {
                std::cout << "\t";
            }
            std::cout << "| '_ ` _ \\| |/ __| '__/ _ \\/ __|/ _ \\|  _| __|\n";

            for (int i = 0; i < slide_index; i++) {
                std::cout << "\t";
            }
            std::cout << "| | | | | | | (__| | | (_) \\__ \\ (_) | | | |_ \n";

            for (int i = 0; i < slide_index; i++) {
                std::cout << "\t";
            }

            std::cout << "|_| |_| |_|_|\\___|_|  \\___/|___/\\___/|_|  \\__|";

            std::cout.flush();

            slide_index++;
            Sleep(250);
        }
        Sleep(1000);

    }

    system("cls");
    printf("           _                           __ _   \n"
           "          (_)                         / _| |  \n"
           " _ __ ___  _  ___ _ __ ___  ___  ___ | |_| |_ \n"
           "| '_ ` _ \\| |/ __| '__/ _ \\/ __|/ _ \\|  _| __|\n"
           "| | | | | | | (__| | | (_) \\__ \\ (_) | | | |_ \n"
           "|_| |_| |_|_|\\___|_|  \\___/|___/\\___/|_|  \\__|\n");


    printf("\n");
    std::cout.flush();

    return 0;
}



