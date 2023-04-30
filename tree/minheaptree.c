#include "heaptree.h"

static int __attribute__((used)) is_full(struct list *root) {
    return root->top+1 == root->capable;
}

struct list *init(const int size) {
    struct list *head;

    head = (struct list *) malloc(sizeof(struct list)); 
    if (!head) {
        fprintf(stderr, "Error allocating the space for struct.\n");
        return NULL;
    }

    head->top = 0;
    head->capable = size + 1; /* we waste the index 0 intentially to better manipulation */
    head->val = (uint8_t *) malloc(sizeof(uint8_t) * head->capable);
    if (!head->val) {
        fprintf(stderr, "Error allocating the space for list.\n");
        free(head);
        return NULL;
    }
    return head;
}

static void __attribute__((used)) __top_down_ins_adjust(struct list *root) {
    int pos;

    pos = root->top;
    while (pos >= 1) {
        if (root->val[pos] < root->val[pos / 2]) {
            swap(root, pos, pos / 2);
            pos /= 2;
        } else 
            break;
    }
}

static void __attribute__((used)) __top_down_del_adjust(struct list *root) {
    int pos;

    pos = 1;
    while ((pos * 2) <= root->top) {
        int min_pos;
        if ((pos * 2 + 1) <= root->top) 
            min_pos = (root->val[pos*2] > root->val[pos*2+1]) ? (pos*2+1) : (pos*2);
        else 
            min_pos = pos * 2;

        if (root->val[pos] > root->val[min_pos]) 
            swap(root, pos, min_pos);
        else 
            break;
        pos = min_pos;
    }
}

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

int insert_heap(struct list *root, uint8_t *val) { 
#ifdef TOP_DOWN
    if (is_full(root)) {
        fprintf(stderr, "Tree is full\n");
        return -1;
    }
    root->val[++root->top] = *val;
    __top_down_ins_adjust(root);
#else // BUTTON UP
    __button_up_ins_adjust(root, root->top / 2);
#endif
    return 0;
}

int del_heap(struct list *root) {
    root->val[1] = root->val[root->top];
    root->val[root->top--] = 0;
#ifdef TOP_DOWN
    __top_down_del_adjust(root);
#else // BUTTON UP
    __button_up_del_adjust(root, 1);
#endif
    return -1;
}

int print_min(struct list *root) {
    return root->val[1];
}

int destroy(struct list *root) {
    free(root->val);
    free(root);
    return 0;
}
