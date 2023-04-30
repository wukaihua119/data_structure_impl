#ifndef BTREE_H_
#define BTREE_H_
#include "list.h"
#include "sort.h"
#include <stdio.h> 
#include <stdint.h>

#ifdef ARRAY_LIST 
struct list *init(const int size);
int insert_heap(struct list *root, uint8_t *val); /* add */ 
int del_heap(struct list *root); 
int print_min(struct list *root);
int destroy(struct list *root); 
#endif

#endif 
