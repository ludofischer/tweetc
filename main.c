#include <stdio.h>
#include "check_auth.h"
#include "get_friends_timeline.h"
#include "update_status.h"

int main(int argc, char *argv[]) {
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
