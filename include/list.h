#ifndef LIST_H
#define LIST_H 
#include "util.h"

struct list {
#ifdef ARRAY_LIST
    uint8_t *val;                 /* used as an array */
    size_t capable;
#else
    uint8_t val;
    struct list *next;     /* used as a linked list */
#ifdef BIDIRECTION
    struct list *prev;
#endif
#endif 
    int top;                      /* the top may be negative */
};

#ifndef ARRAY_LIST
struct list_info {
    struct list *head;
    struct list *tail;
    size_t size;
    int     cur_size;
};
#endif

#endif
