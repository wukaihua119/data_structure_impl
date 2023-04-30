#include "sort.h"

#ifdef ARRAY_LIST 
static void _merge(struct list *list, int front, int mid, int end) {
    int k, j; 
    int start1 = front, end1 = mid;
    int start2 = mid + 1, end2 = end; 

    /* record the merged sorted list by new tmp array */
    uint8_t *tmp = (uint8_t *) malloc(sizeof(uint8_t) * (end - front + 1));

    for (k = 0; start1 <= end1 && start2 <= end2; k++) {
        if (list->val[start1] < list->val[start2]) {
            tmp[k] = list->val[start1];
            ++start1; 
        } else {
            tmp[k] = list->val[start2];
            ++start2; 
        }
    }

    /* deal with the remaining unsorted elements in the divided list */
    while (start1 <= end1) {
        tmp[k] = list->val[start1];
        start1++;
        k++;
    }

    /* deal with the remaining unsorted elements in the divided list */
    while (start2 <= end2) {
        tmp[k] = list->val[start2];
        start2++;
        k++;
    }

    /* copy the value from merged list to origin list */
    for (j = 0; j < end - front + 1; ++j) {
        list->val[front + j] = tmp[j]; 
    }

    free(tmp);
}

static void _merge_sort(struct list *list, int front, int end) {
    int mid = (front + end) / 2;            /* Divide */ 

    if (front < end) {
        _merge_sort(list, front, mid);      /* Conquer */ 
        _merge_sort(list, mid+1, end);      /* Conquer */ 
        _merge(list, front, mid, end);      /* Combine */
    }
}

int merge_sort(struct list *list, int order){ 
    _merge_sort(list, 0, list->top);
    return 0;
}
#else

#endif
