#include <stdio.h>
#include "../get_credentials.h"

int main(void) {
    char words[80];
    get_credentials(words, 81);
    puts(words);
    return 0;
}
