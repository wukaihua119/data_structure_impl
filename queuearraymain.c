#include <stdio.h>
#include "include/queue.h"
#include <signal.h>

#define SIZE 4

static sig_atomic_t sig_recv; 

void sig_handle(int signum) {
    sig_recv = 1;
}

int main(void) {
    uint8_t input;
    int choose;
    struct list *array = init(SIZE);

    signal(SIGINT, sig_handle);

    if(!array) 
        goto term;

    fprintf(stdout, "\n1 for enqueue, 2 for dequeue, 3 for quit: \n");
    scanf("%d", &choose);
    while(!sig_recv && choose != 3) {
        switch(choose) {
            case 1:
                fprintf(stdout, "Input a number from 0 to 255:\n");
                scanf("%u", &input);
                enqueue(array, input);
                break;
            case 2:
                dequeue(array);
                break;
            default:
                fprintf(stderr, "Error: wrong choose\n");
        }
        fprintf(stdout, "\n1 for push, 2 for pop, 3 for quit: \n");
        scanf("%d", &choose);
        fprintf(stdout, "\n");
    }

    fprintf(stderr, "quit\n");
    destroy(array);
term:
    return 0;
}
