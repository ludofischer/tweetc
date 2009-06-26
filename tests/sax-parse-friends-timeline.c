#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libxml/parser.h>

typedef struct MyContext_ {
    int state;
    char *info;
} MyContext;

static void
my_start_element(void *ctx, const xmlChar *name, const xmlChar **attrs) {
    MyContext *con = ctx;
    char *my_name = (char *)name;
    if (!strcmp(my_name, "fruit") || !strcmp(my_name, "dessert")) {
    con->state = 1;
    }
}

static void
my_characters(void *ctx, const xmlChar *ch, int len) {
    MyContext *con =  ctx;
    char *my_ch = (char *) ch; 
    if (con->state == 1) { 
        con->info = malloc(strlen(my_ch) + 1);
        strncpy(con->info, my_ch, strlen(my_ch));
    } 
}

static void
my_end_element(void *ctx, const xmlChar *name) {
    MyContext *con = ctx;
    if (con->state == 1) {
        puts(con->info);
    }
    con->state = 2;
}

int
main(void) {
    MyContext con;
    xmlSAXHandler handler = 
    { .characters = my_characters,
      .startElement = my_start_element,
      .endElement = my_end_element};
    xmlSAXUserParseFile(&handler, &con, "test.xml");
    return 0;
}
