#include <stdio.h>
#include "access_url.h"
#include "get_credentials.h"
#include "get_friends_timeline.h"

int get_friends_timeline(void) {
    char username_password[80]; 

    get_credentials(username_password, 81);
    
    access_url(username_password, "http://twitter.com/statuses/friends_timeline.xml");

    return 0;
}
