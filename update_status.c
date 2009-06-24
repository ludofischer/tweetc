#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "update_status.h"
#include "access_url.h"
#include "get_credentials.h"
#include "constants.h"

int update_status(char *message) {
    char *status_string;
    char *status_prefix = "status=";
    status_string = (char*) calloc(strlen(message) + strlen(status_prefix), sizeof(char));
    strncat(status_string, status_prefix, 7);
    strncat(status_string, message, 300);
    char username_password[USER_PASSWORD_SIZE];
    get_credentials(username_password, USER_PASSWORD_SIZE + 1);
    access_url(username_password, "http://twitter.com/statuses/update.xml", status_string, DO_POST);
    free(status_string);
    printf("Updating status...\n");
    
    return 0;
}
