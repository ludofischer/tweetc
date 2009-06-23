#include <stdio.h>
#include "access_url.h"
#include "get_credentials.h"
#include "get_friends_timeline.h"
#include "constants.h"

int get_friends_timeline(void) {
    char username_password[USER_PASSWORD_SIZE]; 

    get_credentials(username_password, USER_PASSWORD_SIZE + 1);
    
    access_url(username_password, "http://twitter.com/statuses/friends_timeline.xml", NULL, DO_GET);

    return 0;
}
