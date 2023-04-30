#pragma once
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "list.h"

#define SIZE 5

int binarytreesearch(struct list **list, const uint8_t val);
int linearsearch(struct list *list, const uint8_t val);
int binarysearch(struct list *list, const uint8_t val);
int hashsearch(struct list *list, const uint8_t val);
