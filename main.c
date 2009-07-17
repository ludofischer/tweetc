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

    printf("WARNING: IN ITS CURRENT STATE, THIS PROGRAM IS UNSAFE \
\nFOR THE PRIVACY OF YOUR TWITTER ACCOUNT.\n");

    return 0;
}
