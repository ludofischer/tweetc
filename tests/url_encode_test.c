#include <stdio.h>
#include <stdlib.h>
#include "../url_encode.h"

int main(void) {
    char *test_thingy = "Hello, Senõrita.";
    char *result = url_encode(test_thingy);
    puts(result);
    free(result); 
    return 0;
}

