#include "sort.h"

#ifdef ARRAY_LIST 
int insertion_sort(struct list *list, int order){ 
    int tmp, i, j; 

    for (i = 1; i <= list->top; ++i) {
        tmp = list->val[i]; 
        j = i - 1;
        while (j > -1 && list->val[j] > tmp) {
            list->val[j+1] = list->val[j]; 
            j--;
        }
        list->val[j+1] = tmp; 
    }

    return 0;
}
#else

#endif

