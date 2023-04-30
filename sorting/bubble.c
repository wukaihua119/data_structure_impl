#include "sort.h"

#ifdef ARRAY_LIST 
int bubble_sort(struct list *list, int order){ 
    int i, j;

    for (i = 0; i <= list->top - 1; i++) {
        for (j = 0; j <= list->top - i - 1; j++) {
            if (list->val[j] > list->val[j+1])
                swap(list, j, j+1);
        }
    }
    return 0;
}

#else

#endif
