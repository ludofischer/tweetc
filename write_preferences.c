#include <stdio.h>

int write_preferences(void) {
        char *filename = "preferences.txt";
        char username_password[80]; 
        FILE *fp = NULL;

        puts("Please enter your username and password, separated by a colon, like this: username:password");

        fgets(username_password, sizeof username_password, stdin);

        fp = fopen(filename, "w");
        if (fp == NULL) {
            perror("Cannot write to preferences file");
            return 1;
        }
        fputs(username_password, fp);
        fclose(fp);
        puts("Username and password saved.");  
        return 0;
    }
