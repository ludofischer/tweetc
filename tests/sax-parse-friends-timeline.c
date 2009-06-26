#include <stdio.h>
#include <string.h>
#include <libxml/parser.h>

typedef struct my_context_ {
    int state;
    char *status_info;
} my_context;

static void
my_start_document(void *ctx) {
    ctx = malloc(sizeof(my_context)); 
}

static void
my_start_element(void *ctx, const xmlChar *name, const xmlChar **attrs) {
    printf("Element started: %s\n", name);
}

static void
my_characters(void *ctx, const xmlChar *ch, int len) {
    if (ctx) {
    }
}

static void
my_end_element(void *ctx, const xmlChar *name) {
}

static void
my_end_document(void *ctx) {
    puts("Document ended");
    free(ctx);
}

int
main(void) {
    xmlSAXHandler handler = 
    { .characters = my_characters,
      .startDocument = my_start_document,
      .endDocument = my_end_document,
      .startElement = my_start_element,
      .endElement = my_end_element};
    xmlSAXUserParseFile(&handler, NULL, "test.xml");
    return 0;
}
