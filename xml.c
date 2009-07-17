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
#include <string.h>
#include <libxml/parser.h>

#define TEXT 1
#define AUTHOR 3
#define NO_PRINT 2

static void
my_start_element(void *ctx, const xmlChar *name, const xmlChar **attrs) {
    int *state = ctx;
    if (xmlStrEqual(name, (const xmlChar *)"text"))  {
        *state = TEXT;       
}
    if (xmlStrEqual(name, (const xmlChar *)"screen_name")) {
        *state = AUTHOR;
    }
}

static void
my_characters(void *ctx, const xmlChar *ch, int len) {
    int *state =  ctx;
    xmlChar *good_text;
    if (*state != NO_PRINT) {
        good_text = xmlStrsub(ch, 0, len);
    }
    if (*state == TEXT) { 
        puts((char *) good_text);
    } 
    if (*state == AUTHOR) {
        puts((char *) good_text);
        printf("\n");
    }
}

static void
my_end_element(void *ctx, const xmlChar *name) {
    int *state = ctx;
    *state = NO_PRINT;
}

int
parse_friends_timeline(char *data, int size) {
    int state = NO_PRINT;
    xmlSAXHandler handler = 
    { .characters = my_characters,
      .startElement = my_start_element,
      .endElement = my_end_element};

    xmlSAXUserParseMemory(&handler, &state, data, size);
   
    return 0;
}


size_t
writer(char *data, size_t size, size_t nmemb, char *writer_data) {

    parse_friends_timeline(data, size * nmemb);

    return size * nmemb;
}
