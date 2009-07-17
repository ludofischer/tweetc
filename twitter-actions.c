#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "authorization-password.h"
#include "access-url.h"
#include "url-encode.h"
#include "twitter-actions.h"

static int
message_extra_length(char *message) {
    return strlen(message) - MAX_TWEET_LENGTH;
}

static char *
prepare_message(char *message) {
    const char *status_prefix = STATUS_PREFIX;
    char *status_string = NULL;
    message = url_encode(message);
    status_string = calloc(strlen(message) + strlen(status_prefix) + 1, sizeof(char));

    strncat(status_string, status_prefix, STATUS_PREFIX_LENGTH);
    strncat(status_string, message, strlen(status_string) - STATUS_PREFIX_LENGTH);
    free(message);
    return status_string;
}

int
get_friends_timeline(void) {
    char username_password[USER_PASSWORD_SIZE]; 

    get_credentials(username_password);
    
    access_url(username_password, NULL, FRIENDS_TIMELINE);

    return 0;
}

int
update_status(char *message) {
    char username_password[USER_PASSWORD_SIZE];
    int message_excess = message_extra_length(message);
    if (message_excess > 0) {
        fprintf(stderr,"Your message is %d characters too long\n.", message_excess);
        return 1;
    } else { 
        get_credentials(username_password);
        message = prepare_message(message); 
        access_url(username_password, message, UPDATE_STATUS);
        free(message);

        printf("Updating status...\n");
    
        return 0;
    }
}
