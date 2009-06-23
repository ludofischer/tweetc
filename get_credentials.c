#include <string.h>
#include <stdio.h>
#include "get_credentials.h"

int get_credentials(char *buffer, int length) {
    char *p;
    FILE *fp = NULL;

    fp = fopen("preferences.txt", "r");
    if (fp == NULL) {
        perror("Cannot open file");
        return 1;
    }

    fgets(buffer, length, fp);
    fclose(fp);

    if ((p = strchr(buffer, '\n')) != NULL) {
            *p = '\0';
    }
    return 0;
}
