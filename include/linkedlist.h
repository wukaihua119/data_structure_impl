#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include "list.h"

int insert_node(struct list **list, uint8_t val);
int insert_at(struct list **list, uint8_t val, int pos);
int delete_node(struct list **list, uint8_t val);
int reverse(struct list **list);
int find_mid(struct list **list);
int show(struct list **node);
int free_list(struct list **list);

#endif
