#include "sort.h"

#ifdef ARRAY_LIST 
int selection_sort(struct list *list, int order){ 
    int i, j, min;

    for (i = 0; i < list->top; i++) {
        /* assume the current position is the smallest */
        min = i;  
        /* find the smallest one from the remaining space */
        for (j = i; j <= list->top; j++) { 
            /* if the current value is smaller than the one from remaining space */
            if (list->val[min] > list->val[j]) { 
                /* assign to the min */ 
                min = j;   
            }
        }
        /* swap the smallest value from the unsorted list with the current value */
        swap(list, min, i); 
    }
    return 0;
}
#else

#endif
