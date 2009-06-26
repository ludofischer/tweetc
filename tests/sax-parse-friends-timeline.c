#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libxml/parser.h>

#define PRINT 1
#define NO_PRINT 2

static void
my_start_element(void *ctx, const xmlChar *name, const xmlChar **attrs) {
    int *state = ctx;
    if (xmlStrEqual(name, (const xmlChar *)"fruit") || xmlStrEqual(name, (const xmlChar *) "dessert")) {
    *state = PRINT;
    }
}

static void
my_characters(void *ctx, const xmlChar *ch, int len) {
    int *state =  ctx;
    if (*state == PRINT) { 
        xmlChar *sub = xmlStrsub(ch, 0, len);
        puts((char *) sub);
    } 
}

static void
my_end_element(void *ctx, const xmlChar *name) {
    int *state = ctx;
    *state = NO_PRINT;
}

int
main(void) {
    int state = NO_PRINT;
    xmlSAXHandler handler = 
    { .characters = my_characters,
      .startElement = my_start_element,
      .endElement = my_end_element};
    xmlSAXUserParseFile(&handler, &state, "test.xml");
    return 0;
}
