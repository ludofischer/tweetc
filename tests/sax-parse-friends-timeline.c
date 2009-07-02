#include <stdio.h>
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
main(int argc, char **argv) {
    if (argc == 2) {
    int state = NO_PRINT;
    xmlSAXHandler handler = 
    { .characters = my_characters,
      .startElement = my_start_element,
      .endElement = my_end_element};
    xmlSAXUserParseFile(&handler, &state, argv[1]);
    return 0;
    } else {
        perror("Wrong number of arguments.");
        return 1;
    }
}
