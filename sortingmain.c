#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

#define SIZE 1024

typedef int (*sorting_fn)(struct list *, int); 

sorting_fn sortfn[SORT_FN_N] = {
    bubble_sort,
    selection_sort,
    insertion_sort,
    quick_sort,
    merge_sort,
    heap_sort,
};

static void show_msg(void) { 
    fprintf(stdout, "\nMenu: \n");
    fprintf(stdout, "  1. add element to list\n");
    fprintf(stdout, "  2. bubble sort\n");
    fprintf(stdout, "  3. selection sort\n");
    fprintf(stdout, "  4. insertion sort\n");
    fprintf(stdout, "  5. quick sort\n");
    fprintf(stdout, "  6. merge sort\n");
    fprintf(stdout, "  7. heap sort\n");
    fprintf(stdout, "  0. quit\n");
}

static int show(struct list *list) {
    for(int i = 0; i <= list->top; i++) {
        fprintf(stdout, "%d -> ", list->val[i]);
    }
    fprintf(stdout, "NULL\n");
    return 0;
}

int main(void) {

    struct list *head = NULL;
    int choose, ret, index; 
    uint8_t input; 
    head = init(SIZE);

    show_msg();
    scanf("%d", &choose);
    while(choose != 0) {
        switch(choose) {
            case 1:  
                fprintf(stdout, "Input a number from 0 to 255:\n");
                scanf("%u", &input);
                ret = push(head, input);
                if (!ret) {
                    show(head);
                }
                break;
            case 2:
                fprintf(stdout, "Bubble sort: \n");
                ret = sortfn[choose-2](head, SORT_MIN_FIRST);
                if (!ret) show(head);
                break;
            case 3:
                fprintf(stdout, "Selection sort: \n");
                ret = sortfn[choose-2](head, SORT_MIN_FIRST);
                if (!ret) show(head);
                break;
            case 4:
                fprintf(stdout, "Insertion sort: \n");
                ret = sortfn[choose-2](head, SORT_MIN_FIRST);
                if (!ret) show(head);
                break;
            case 5:
                fprintf(stdout, "Quick sort: \n");
                ret = sortfn[choose-2](head, SORT_MIN_FIRST);
                if (!ret) show(head);
                break;
            case 6:
                fprintf(stdout, "Merge sort: \n");
                ret = sortfn[choose-2](head, SORT_MIN_FIRST);
                if (!ret) show(head);
                break;
            case 7:
                fprintf(stdout, "Heap sort: \n");
                ret = sortfn[choose-2](head, SORT_MIN_FIRST);
                if (!ret) show(head);
                break;
            default:
                fprintf(stderr, "Error: wrong choose\n");
        }
        show_msg();
        scanf("%d", &choose);
        fprintf(stdout, "\n");
    }

    fprintf(stderr, "quit\n");
    destroy(head);
    return 0;
}
