#include <stdio.h>

int write_preferences(void) {
        char *filename = "preferences.txt";
        char username_password[80] = "whatever:whatever";
        FILE *fp = NULL;

        fp = fopen(filename, "w");
        if (fp == NULL) {
            perror("Cannot write to preferences file");
            return 1;
        }
        fputs(username_password, fp);
        fclose(fp);
        
        return 0;
    }
