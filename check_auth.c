#include <stdio.h>
#include "check_auth.h"
#include "write_preferences.h"

int check_auth(void) {
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
