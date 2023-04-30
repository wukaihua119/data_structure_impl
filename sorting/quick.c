#include "sort.h"

#ifdef ARRAY_LIST 
static int _partition(struct list *list, int front, int end) {
    /* this case, we choose the last one as pivot value */
    int pivot_val = list->val[end]; 
    /* i is the current position that has been compared and smaller than pivot value */
    int i = front - 1; 

    /* the last one does not need to compare, due to pivot value */
    for (int j = front; j < end; j++) { 
        /* if the current elemnt value is smaller than pivot value */ 
        if (pivot_val > list->val[j]) { 
            /* The currently position at the list of the elements that are all smaller than pivot value. */ 
            i++;               
            /* swap it */
            swap(list, i, j);  
        }
    }
    i++; 
    swap(list, i, end);  /* swap the pivot to the compared list */
    return i;
}

static void _quick_sort(struct list *list, int front, int end) {
    if (front < end) { 
        /* partition: 
         * each call of this function is sorted with the pivot and return the position of the pivot 
         * so that there is no need to combine at the end. */ 
        int pivot = _partition(list, front, end); 
        /* sorting the left of the pivot */
        _quick_sort(list, front, pivot - 1); 
        /* sorting the right of the pivot */
        _quick_sort(list, pivot + 1, end); 
    }
}

int quick_sort(struct list *list, int order){ 
    _quick_sort(list, 0, list->top);
    return 0;
}
#else

#endif
