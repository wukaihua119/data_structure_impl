/* Queue is first-in, first out 
 *
 * linear queue may waste space 
 * using circular queue can put the value in queue circularly. 
 * 
 * using circular queue, it will waste a space when checking is full 
 * or not by `return (tail + 1) % list->capable == head;` 
 * using full to check it is actually full or not.
 */
#include "list.h"
#include "queue.h"

static int head = 0, tail = 0;
#if defined(CIRCULAR_Q) && defined(OPT_CIRCULAR_Q)
static int full = 0;
#endif

static int is_full(struct list *list) {
#ifndef CIRCULAR_Q
    return (tail == list->capable) ||
           ((tail - head) == list->capable);
#else
#ifdef OPT_CIRCULAR_Q
    /* below is adden due to optimizing the circular queue 
     * that wouldn't waste a space for checking empty */
    return tail == head && full == 1; 
#else
    /* this condition will cause waste one space, need to be improved */
    return (tail + 1) % list->capable == head; 
#endif
#endif
}

static int is_empty(struct list *list) {
#if defined(CIRCULAR_Q) && defined(OPT_CIRCULAR_Q)
    /* the `full` is adden due to optimizing the circular queue 
     * that wouldn't waste a space for checking empty */
    return head == tail && full == 0; 
#else
    return head == tail;
#endif
}

static void show_queue(struct list *list) {
#ifndef CIRCULAR_Q
    fprintf(stdout, "Queue: ");
    for(int i = head; i < tail; i++) {
        fprintf(stdout, "%u ", list->val[i]);
    }
    fprintf(stdout, "\n");
#else
    fprintf(stdout, "Circular Queue: ");
    // [WIP]
    int _head = head, _tail = tail - 1;
    if(_head <= _tail) {
        while(_head <= _tail) {
            fprintf(stdout, "%d ",list->val[_head]);
            _head++;
        }
    } else {
        while(_head <= list->capable - 1) {
            fprintf(stdout, "%d ", list->val[_head]);
            _head++;
        }
        _head = 0;
        while(_head <= _tail) {
            fprintf(stdout, "%d ", list->val[_head]);
            _head++;
        }
    }
#endif
}


struct list *init(const int size) {
    struct list *array = (struct list *) malloc(sizeof(struct list));
    if (!array) {
        ERROR_MSG("CANNOT ALLOCATE MEMORY FOR QUEUE list");
        return NULL;
    }
    
    array->capable = size;
    array->val = (uint8_t *) malloc(array->capable * sizeof(uint8_t));
    if (!array->val) {
        ERROR_MSG("CANNOT ALLOCATE MEMORY FOR QUEUE array");
        free(array);
        return NULL;
    }

    return array;
}

int destroy(struct list *list) {
    free(list->val);
    free(list);
    return 0;
}

int enqueue(struct list *list, uint8_t val) {
    if (is_full(list)) {
        ERROR_MSG("QUEUE IS FULL");
        return -1;
    }

#ifndef CIRCULAR_Q
    list->val[tail++] = val;
#else
    list->val[tail] = val;
    tail = (tail + 1) % list->capable;
#ifdef OPT_CIRCULAR_Q
    /* below is adden due to optimizing the circular queue 
     * that wouldn't waste a space for checking empty.
     * After enqueue, check the head == tail, if so, the queue is actually full, */
    if (head == tail) full = 1;  
#endif
#endif
    show_queue(list);
    return 0;
}

int dequeue(struct list *list) {
    int del;

    if (is_empty(list)) {
        ERROR_MSG("QUEUE IS EMPTY");
        return -1;
    }
#ifndef CIRCULAR_Q
    del = list->val[head++];
#else
    del = list->val[head];
    list->val[head] = 0;
    head = (head + 1) % list->capable;
#ifdef OPT_CIRCULAR_Q
    /* below is adden due to optimizing the circular queue 
     * that wouldn't waste a space for checking empty 
     * after dequeue, check the head == tail, if so, the queue is actually empty, */
    if (head == tail) full = 0;  
#endif
#endif
    show_queue(list);
    return del;
}
