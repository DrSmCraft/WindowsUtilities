#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include "string_util.h"


std::vector<std::string> get_wifi_profile_names();

std::string get_password_for_wifi_profile(std::string name);

int main(int argv, char *args[]) {
    bool batch_mode = false;
    if (argv > 1) {

        for (int i = 1; i < argv; i++) {
            if (strcmp(args[i], "-h") == 0 || strcmp(args[i], "-?") == 0 || strcmp(args[i], "--help") == 0) {
                printf("Netsh Password Utility\nDeveloped by DrSmCraft");
                printf("This utility loops through the profiles in \"netsh wlan show profiles\" and displays the password, if there is any\n");
                printf("-?, --help  : Show this help message\n");
                printf("-b, --batch : Show batch parsable output\n");
                return 0;
            }
            else if (strcmp(args[i], "-b") == 0 | strcmp(args[i], "--batch") == 0) {
                batch_mode = true;
            } else{
                printf("ERROR: Unknown argument \"%s\"\nUse -? to see help",
                       args[i]);
                return -1;
            }

        }
    }


    std::vector<std::string> profiles_array = get_wifi_profile_names();

    if(!batch_mode) {
        printf("Netsh Password Utility\nDeveloped by DrSmCraft\n\n");

        printf("%-20s | %-20s\n", "SSID", "Password");
        printf("---------------------|---------------------\n");

        for (auto profile_name:profiles_array) {
            std::string password = get_password_for_wifi_profile(profile_name);

            printf("%-20s | %-20s\n", profile_name.c_str(), password.c_str());
        }
    } else{
        int count = 0;
        for (auto profile_name:profiles_array) {
            std::string password = get_password_for_wifi_profile(profile_name);

            printf("%s:%s", profile_name.c_str(), password.c_str());

            if(count < profiles_array.size() -1){
                printf(",");
            }
            count++;
        }
    }
    return 0;
}


std::vector<std::string> get_wifi_profile_names() {
    FILE *pPipe;
    pPipe = _popen("netsh wlan show profiles", "r");
    if (pPipe == NULL) {
        std::printf("ERROR: Could Not execute \"netsh wlan show profile\"\nExiting");
        exit(-1);
    }

    std::string result = "";
    char buffer[128];
    fgets(buffer, 128, pPipe);

    while (!feof(pPipe)) {
        if (fgets(buffer, 128, pPipe) != NULL)
            result += buffer;

    }

    std::vector<std::string> profile_names;

    std::vector<std::string> lines = split_by_substring(result, "\n");

    for (auto line:lines) {
        int user_profile_found = line.find("All User Profile");
        if (user_profile_found > -1) {
            std::vector<std::string> parts = split_by_substring(line, ": ");
            if (parts.size() != 2) {
                continue;
            }
            profile_names.push_back(parts.back());

        }
    }



//    std::string profiles_string = result.substr(result.find("User profiles"));
//
//    profiles_string = profiles_string.replace(0, 14, "");
//    profiles_string = profiles_string.replace(0, 13, "");
//    printf("\n");
//
//    profiles_string = replace_all(0, profiles_string, "All User Profile", "");
//    profiles_string = replace_all(0, profiles_string, "         :", "");
//
//
//    return split_by_substring(profiles_string, "\n ");
    return profile_names;

}

std::string get_password_for_wifi_profile(std::string name) {
    FILE *pPipe;
    std::string command = "netsh wlan show profile ";
    command += name;
    command += " key=clear";

    pPipe = _popen(command.c_str(), "r");

    if (pPipe == NULL) {
        std::printf("ERROR: Could Not execute \"netsh wlan show profile\"\nExiting");
        exit(-1);
    }
    std::string result = "";
    char buffer[128];
    fgets(buffer, 128, pPipe);

    while (!feof(pPipe)) {
        if (fgets(buffer, 128, pPipe) != NULL)
            result += buffer;

    }

    std::vector<std::string> lines = split_by_substring(result, "\n");
    for (auto line:lines) {
        int user_profile_found = line.find("Key Content");
        if (user_profile_found > -1) {
            std::vector<std::string> parts = split_by_substring(line, ": ");
            if (parts.size() != 2) {
                continue;
            }
            return parts.back().c_str();
        }
    }

    return "?";
}

