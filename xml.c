#include <stdlib.h>
#include <string.h>

static int
writer(char *data, size_t size, size_t nmemb, char *writer_data) {
    char *buffer = malloc(strlen(writer_data) + size * nmemb + 1);
    if (!buffer) {
        return 0;
    }
    strcpy(buffer, writer_data);
    strncat(buffer, data, size*nmemb);
    writer_data = buffer

    return size * nmemb;
}

