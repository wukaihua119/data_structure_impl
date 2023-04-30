#ifndef QUEUEARRAY_H_
#define QUEUEARRAY_H_ 
#include "util.h"
#include "list.h"

#ifndef ARRAY_LIST 
struct list_info *init(const int size);
int enqueue(struct list_info *list_f, uint8_t val);
int dequeue(struct list_info *list_f); 
int destroy(struct list_info *list_f);
#else
struct list *init(const int size);
int enqueue(struct list *list, uint8_t val);
int dequeue(struct list *list); 
int destroy(struct list *list);
#endif

#endif 
