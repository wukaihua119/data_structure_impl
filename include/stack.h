#ifndef STACKARRAY_H_
#define STACKARRAY_H_ 
#include "list.h"

#ifdef ARRAY_LIST 
struct list *init(const int size);
int push(struct list *list, uint8_t val);
int pop(struct list *list);
int destroy(struct list *list);
#else
struct list_info *init(const int size);
int push(struct list_info *info, uint8_t val);
int pop(struct list_info *info);
int destroy(struct list_info *info);
#endif


#endif 
