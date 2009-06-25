#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "authorization-password.h"
#include "access_url.h"
#include "url_encode.h"
#include "twitter-actions.h"

int
get_friends_timeline(void) {
    char username_password[USER_PASSWORD_SIZE]; 

    get_credentials(username_password, USER_PASSWORD_SIZE + 1);
    
    access_url(username_password, "http://twitter.com/statuses/friends_timeline.xml", NULL, DO_GET);

    return 0;
}

int
update_status(char *message) {
    char username_password[USER_PASSWORD_SIZE];
    const char *status_prefix = STATUS_PREFIX;
    char *encoded = url_encode(message);
    char *status_string = calloc(strlen(encoded) + strlen(status_prefix) + 1, sizeof(char));
    strncat(status_string, status_prefix, STATUS_PREFIX_LENGTH);
    strncat(status_string, encoded, 420 - STATUS_PREFIX_LENGTH);
    get_credentials(username_password, USER_PASSWORD_SIZE + 1);
    access_url(username_password, "http://twitter.com/statuses/update.xml", status_string, DO_POST);
    free(status_string);
    free (encoded);
    printf("Updating status...\n");
    
    return 0;
}
