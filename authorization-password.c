/*
* Copyright 2009 Ludovico Fischer

* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
