#include "list.h" 
#include "stack.h"

/* using the compile macro ARRAY_LIST to make the structure like this.  
 *
 * struct list { 
 *     uint8_t *val;                 
 *     size_t capable;
 *     size_t top;
 * };
 *
 */ 

/**
 * is_empty()
 * 
 * @parameter list - the list to be checked
 * 
 * check the stack is empty or not.
 */
static int is_empty(struct list *list) {
    return (list->top == -1);
}

/**
 * is_full()
 * 
 * @parameter list - the list to be checked
 * 
 * check the stack is full or not.
 */
static int is_full(struct list *list) {
    return (list->top+1 == list->capable);
} 

/**
 * show_stack()
 * 
 * @parameter list - the list to be shown
 *
 * Show the stack elements
 */
static void show_stack(struct list *list) {
    fprintf(stdout, "Stack: ");
    for(int i = 0; i <= list->top; i++) {
        fprintf(stdout, "%d -> ", list->val[i]);
    }
    fprintf(stdout, "NULL\n");
}

struct list *init(const int size) { 
    struct list *array = (struct list *) malloc(sizeof(struct list));
    if (!array) {
        fprintf(stderr, "Error: cannot allocate space!\n");
        return NULL;
    }

    array->capable = size;
    array->val = (uint8_t *) malloc(array->capable * sizeof(uint8_t));
    if (!array->val) {
        fprintf(stderr, "Error: cannot allocate space for stack!\n");
        free(array);
        return NULL;
    }

    array->top = -1;
    return array;
}

int destroy(struct list *list) {
    free(list->val);
    free(list);
    return 0;
} 

/**
 * push() 
 *
 * @parameter list - the list to be used
 * @parameter val  - the value to be adden on the stack 
 *
 * Return 0 on success. 
 */
int push(struct list *list, uint8_t val) {
    if(is_full(list)) {
        fprintf(stderr, "Error: stack is full\n");
        return -1;
    }
    
    list->val[++list->top] = val;
#ifdef SHOWDBG
    show_stack(list);
#endif
    return 0;
}

/**
 * pop()
 * 
 * @parameter list - the list
 *
 * Delete the val on the top of the stack
 * and return the deleted val on success.
 */
int pop(struct list *list) {
    if(is_empty(list)) {
        fprintf(stderr, "Error: stack is empty\n");
        return -1;
    }
    uint8_t del = list->val[list->top--];
    if (list->top > -1) {
#ifdef SHOWDBG
        show_stack(list);
#endif
    }else 
        fprintf(stderr, "Error: stack is empty\n");
    return del;
}
