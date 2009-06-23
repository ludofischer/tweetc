#include <stdio.h>
#include "update_status.h"
#include "access_url.h"
#include "get_credentials.h"
#include "constants.h"

int update_status(char *message) {
    char username_password[80];
    get_credentials(username_password, 81);
    access_url(username_password, "http://twitter.com/statuses/update.xml", message, DO_POST);
    printf("Updating status...\n");
    
    return 0;
}
