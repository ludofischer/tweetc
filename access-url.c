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
#include <curl/curl.h>
#include <stdio.h>
#include "access-url.h"
#include "xml.h"


static int
init_update(CURL *curl, char *username_password, char *status_update) {
  CURLcode res;
  const char *status_update_url = "https://twitter.com/statuses/update.xml";
  res = curl_easy_setopt(curl, CURLOPT_URL, status_update_url);
  if ( res != CURLE_OK) {
    perror("Could not set url");
    return 1;
  }
  res = curl_easy_setopt(curl, CURLOPT_USERPWD, username_password);
  if (res != CURLE_OK) {
    perror("Could not set password.");
    return 1;
  }
  res = curl_easy_setopt(curl, CURLOPT_POST, 1);
  if (res != CURLE_OK) {
    perror("Could not set post options.");
    return 1;
  }
  res = curl_easy_setopt(curl, CURLOPT_POSTFIELDS, status_update);
  if (res != CURLE_OK) {
    perror("Could not set status update field.");
    return 1;
  }
  return 0;
}

static int
init_friends_timeline(CURL *curl, char *username_password) {
    CURLcode res;
    const char *friends_timeline_url = "https://twitter.com/statuses/friends_timeline.xml";
    res = curl_easy_setopt(curl, CURLOPT_URL, friends_timeline_url);
    res = curl_easy_setopt(curl, CURLOPT_USERPWD, username_password);
    res = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
    if (res != CURLE_OK) {
      perror("Could not set write callback");
    }
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
