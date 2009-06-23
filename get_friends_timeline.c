#include <stdio.h>
#include <curl/curl.h>
#include "get_friends_timeline.h"

int get_friends_timeline(void) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://twitter.com/statuses/friends_timeline.rss");
        curl_easy_setopt(curl, CURLOPT_USERPWD, "whatever:whatever");

        res = curl_easy_perform(curl);

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0;
}
