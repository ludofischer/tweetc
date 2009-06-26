#include <curl/curl.h>
#include <stdio.h>
#include "access-url.h"

void
access_url(char *username_password, char* url, char* post_data, int operation) { 
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_USERPWD, username_password);
        if (operation == DO_POST) {
            curl_easy_setopt(curl, CURLOPT_POST, 1);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data);
        }
        res = curl_easy_perform(curl);

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    if (res) {
        perror("Sorry! Could not connect to twitter.com");
    }
}

