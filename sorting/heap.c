#include "sort.h"

#ifdef ARRAY_LIST 
static void __attribute__((used)) __button_up_adjust(struct list *root, int pos) {
    if (pos < 1) return;

    int cur_pos = pos;
    while ((cur_pos * 2) <= root->top) {
        int min_pos;
        if ((cur_pos * 2 + 1) <= root->top) 
            min_pos = (root->val[cur_pos*2] > root->val[cur_pos*2+1]) ? (cur_pos*2+1) : (cur_pos*2);
        else 
            min_pos = cur_pos * 2;

        if (root->val[cur_pos] > root->val[min_pos]) 
            swap(root, cur_pos, min_pos);
        else 
            break;
        cur_pos = min_pos;
    }
    __button_up_adjust(root, pos - 1);
}

static void __attribute__((used)) __button_up_ins_adjust(struct list *root, int pos) {
    __button_up_adjust(root, pos);
}

static void __attribute__((used)) __button_up_del_adjust(struct list *root, int pos) {
    __button_up_adjust(root, pos);
}

static void __attribute__((used)) show_heap(struct list *root) {
    for (int i = 1; i <= root->top; i++) {
        fprintf(stdout, "%u ->", root->val[i]);
    }
    fprintf(stdout, "NULL\n");
}

int heap_sort(struct list *list, int order) { /* use button up method */
    struct list *heap; 

    heap = (struct list *) malloc(sizeof(struct list)); 
    if (!heap) {
        fprintf(stderr, "Error: cannot allocate space for structure.\n");
        return -1;
    }

    heap->val = (uint8_t *) malloc(sizeof(uint8_t) * 1025);
    if (!heap->val) {
        fprintf(stderr, "Error: cannot allocate space for array.\n");
        free(heap);
        return -1;
    }

    /* Also can use the index 0 in array to store the real-time size of the heap */
    heap->top = 0;
    for (int i = 0; i <= list->top; i++) 
        heap->val[++heap->top] = list->val[i];

    __button_up_ins_adjust(heap, heap->top / 2);
    //show_heap(heap);

    /* extract the elements from small to big */
    for (int i = 0; i <= list->top; i++) {
        list->val[i] = heap->val[1];
        heap->val[1] = heap->val[heap->top];
        heap->val[heap->top--] = 0;
        __button_up_del_adjust(heap, 1);
    }

    free(heap->val);
    free(heap);
    return 0;
}

#else 
#endif 
