#include <stdio.h>
#include <stdlib.h>
#include "heaptree.h" 

#define SIZE 9

static void show_heap(struct list *root) {
    for (int i = 1; i <= root->top; i++) {
        fprintf(stdout, "%u ->", root->val[i]);
    }
    fprintf(stdout, "NULL\n");
}

static void show_msg(void) { 
    fprintf(stdout, "\nMenu: \n");
    fprintf(stdout, "  1. add element to min heap tree\n");
    fprintf(stdout, "  2. delete min element to min heap tree\n");
    fprintf(stdout, "  3. find the min value of the min heap tree\n");
    fprintf(stdout, "  0. quit\n");
}

int main(void) {
    struct list *heap = NULL;
    int choose, ret; 
    uint8_t input; 
    heap = init(SIZE);

    show_msg();
    scanf("%d", &choose);
    while (choose != 0) {
        switch (choose) {
            case 1:  
#ifdef TOP_DOWN
                fprintf(stdout, "Add element to min heap tree from 0 to 255 >> ");
                scanf("%u", &input);
                ret = insert_heap(heap, &input);
                show_heap(heap);
#else
                fprintf(stdout, "Add 9 elements to min heap tree from 0 to 255:\n");
                for (int i = 1; i < heap->capable-1; i++) {
                    fprintf(stdout, ">> ");
                    /* Also can use the index 0 in array to store the real-time size of the heap */
                    scanf("%u", &(heap->val[++heap->top]));
                }
                ret = insert_heap(heap, NULL);
                show_heap(heap);
#endif
                break;
            case 2:
                fprintf(stdout, "delete the min element from min heap tree\n");
                ret = del_heap(heap);
                show_heap(heap);
                break;
            case 3:
                fprintf(stdout, "find the min element from min heap tree: ");
                ret = print_min(heap);
                fprintf(stdout, "%u\n", ret);
                break;
            default:
                fprintf(stderr, "Error choice\n");
                break;
        }
        show_msg();
        scanf("%d", &choose);
        fprintf(stdout, "\n");
    }
    fprintf(stdout, "quit\n");
    destroy(heap);
    return 0;
}
