#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "update_status.h"
#include "access_url.h"
#include "get_credentials.h"
#include "url_encode.h"
#include "constants.h"

int update_status(char *message) {
    const char *status_prefix = STATUS_PREFIX;
    char *encoded = url_encode(message);
    char *status_string = calloc(strlen(encoded) + strlen(status_prefix) + 1, sizeof(char));
    strncat(status_string, status_prefix, STATUS_PREFIX_LENGTH);
    strncat(status_string, encoded, 420 - STATUS_PREFIX_LENGTH);
    char username_password[USER_PASSWORD_SIZE];
    get_credentials(username_password, USER_PASSWORD_SIZE + 1);
    access_url(username_password, "http://twitter.com/statuses/update.xml", status_string, DO_POST);
    free(status_string);
    free (encoded);
    printf("Updating status...\n");
    
    return 0;
}
