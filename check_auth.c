#include <stdio.h>
#include "check_auth.h"

int check_auth(void) {
    FILE *fp;
    puts("Checking authentication...");
    fp = fopen("preferences.txt", "r");
    if (fp == NULL) {
        perror("Unreadable preferences file");
        return 1;
    }
    return 0;
}
