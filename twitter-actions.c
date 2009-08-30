/*
* Copyright 2009 Ludovico Fischer

* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
    status_string = calloc(strlen(message) + STATUS_PREFIX_LENGTH + 1, sizeof(char));
    if (status_string == NULL) {
        exit(EXIT_FAILURE);
    }
    strcat(status_string, status_prefix);
    strcat(status_string, message);
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
