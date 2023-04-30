#ifndef SORT_H_
#define SORT_H_ 

#include <stdio.h>
#include <stdint.h>
#include "util.h"
#include "stack.h"

#define SORT_MAX_FIRST 0
#define SORT_MIN_FIRST 1

#define SORT_FN_N      6

#ifndef ARRAY_LIST
int bubble_sort(struct list **list, int order); 
int selection_sort(struct list **list, int order); 
int insertion_sort(struct list **list, int order); 
int quick_sort(struct list **list, int order); 
int merge_sort(struct list **list, int order); 
int heap_sort(struct list **list, int order);
#else
static int __attribute__((used)) swap(struct list *list, int pos1, int pos2) {
    //int tmp; 
    //tmp = list->val[pos1]; 
    //list->val[pos1] = list->val[pos2];
    //list->val[pos2] = tmp;

    /* this condition is need, or both elements in pos1 and pos2 are become 0 */
    if (pos1 != pos2) {
        list->val[pos1] ^= list->val[pos2];
        list->val[pos2] ^= list->val[pos1];
        list->val[pos1] ^= list->val[pos2];
    }
    /* if pos1 equals to pos2, it means that they are two identical position
     * swapping them would induce the 0 */
    return 0;
}

int bubble_sort(struct list *list, int order); 
int selection_sort(struct list *list, int order); 
int insertion_sort(struct list *list, int order); 
int quick_sort(struct list *list, int order); 
int merge_sort(struct list *list, int order); 
int heap_sort(struct list *list, int order);
#endif

#endif 
