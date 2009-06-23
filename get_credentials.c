#include <stdio.h>
#include "get_credentials.h"

int get_credentials(char *buffer, int length) {
    FILE *fp = NULL;
    fp = fopen("preferences.txt", "r");
    if (fp == NULL) {
        perror("Cannot open file");
        return 1;
    }

    fgets(buffer, length, fp);

    fclose(fp);

    return 0;
}
