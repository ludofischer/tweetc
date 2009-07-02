#include <curl/curl.h>
#include <stdio.h>
#include "access-url.h"
#include "xml.h"

static char *saved_data;

static int
init_update(CURL *curl, char *username_password, char *status_update) {
        CURLcode res;
    const char *status_update_url = "https://twitter.com/statuses/update.xml";
        res = curl_easy_setopt(curl, CURLOPT_URL, status_update_url);
        res = curl_easy_setopt(curl, CURLOPT_USERPWD, username_password);
        res = curl_easy_setopt(curl, CURLOPT_POST, 1);
        res =curl_easy_setopt(curl, CURLOPT_POSTFIELDS, status_update);
        return 0;
}

static int
init_friends_timeline(CURL *curl, char *username_password) {
    CURLcode res;
    const char *friends_timeline_url = "https://twitter.com/statuses/friends_timeline.xml";
    res = curl_easy_setopt(curl, CURLOPT_URL, friends_timeline_url);
    res = curl_easy_setopt(curl, CURLOPT_USERPWD, username_password);
    res = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
    res = curl_easy_setopt(curl, CURLOPT_WRITEDATA, saved_data); 
    return 0;
}
    
void
access_url(char *username_password, char* post_data, int operation) { 
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if (curl) {
        if (operation == UPDATE_STATUS) {
            init_update(curl, username_password, post_data);
        }
        if (operation == FRIENDS_TIMELINE) {
            init_friends_timeline(curl, username_password);
        }
        res = curl_easy_perform(curl);

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    if (res != CURLE_OK) {
        perror("Sorry! Could not connect to twitter.com");
    }
}

