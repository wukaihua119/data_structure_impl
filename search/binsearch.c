#include "list.h"

static int __attribute__((used)) __binsearch(struct list *list, 
                            int front, int end, const uint8_t val) {
    int mid; 

    mid = (front + end) / 2;

    if (front <= end) { 
        if (list->val[mid] > val) 
            return __binsearch(list, front, mid-1, val);
        else if (list->val[mid] < val) 
            return __binsearch(list, mid+1, end, val);
        else if (list->val[mid] == val) {
            fprintf(stdout, "%u Found.\n", list->val[mid]);
            return 0;
        }
    }
    return -1;
}

int binarysearch(struct list *list, const uint8_t val) {
    return __binsearch(list, 0, list->top, val);;
}
