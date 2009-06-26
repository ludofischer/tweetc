#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "url-encode.h"

/* Should be correct by RFC 3986,
 * http://www.ietf.org/rfc/rfc3986.txt
 * section 2.3 and 2.4.
 */
static int needs_replace(char c) {
    if (
            ('a' <= c && c <= 'z')
            || ('A' <= c && c <= 'z')
            || ('0' <= c && c <= '9')
            || ( c == '-')
            || (c == '.')
            || (c == '_')
            || (c == '~')
        ) {
            return 0;
    }
    else {
            return 1;
    }
}

static char zero_to_f(char c) {
    const char *hex = "0123456789abcdef";
    return hex[c & 15]; /* Needed for safety */
}

char *url_encode(char *not_replaced) {
    char *replaced = malloc(strlen(not_replaced) * 3 + 1);
    char *working_buf = replaced;

    while (*not_replaced) {
        if (needs_replace(*not_replaced)) {
            *working_buf++ = '%';
            *working_buf++ = zero_to_f(*not_replaced >> 4);
            *working_buf++ = zero_to_f(*not_replaced & 15);
        }
        else {
            *working_buf++ = *not_replaced;
        }

        not_replaced++;
    }
    *working_buf++ = '\0';
    return replaced;
} 
