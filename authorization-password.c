#include <stdio.h>
#include <string.h>
#include "authorization-password.h"

static int 
write_preferences(void) {
        char *filename = "preferences.txt";
        char username_password[USER_PASSWORD_SIZE]; 
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

int 
check_auth(void) {
    FILE *fp = NULL;
    int success = 0;

    puts("Checking authentication...");
    fp = fopen("preferences.txt", "r");
    if (fp == NULL) {
        perror("Unreadable preferences file");
        write_preferences();
    }
    
    return success;
}

int
get_credentials(char *buffer) {
    char *p;
    FILE *fp = NULL;

    fp = fopen("preferences.txt", "r");
    if (fp == NULL) {
        perror("Cannot open file");
        return 1;
    }

    fgets(buffer, USER_PASSWORD_SIZE + 1, fp);
    fclose(fp);

    if ((p = strchr(buffer, '\n')) != NULL) {
        *p = '\0';
    }
    return 0;
}
