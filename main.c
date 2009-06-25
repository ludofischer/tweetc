#include <stdio.h>
#include "authorization-password.h"
#include "twitter-actions.h"

int
main(int argc, char *argv[]) {
    switch(argc) {
        case 1:
            check_auth();
            get_friends_timeline(); 
            break;

        case 2:
            check_auth();
            update_status(argv[1]);
            break;

        default:
            printf("Not a valid number of arguments\n");
            return 1;
    }

    return 0;
}
