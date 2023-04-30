#include <stdio.h>
#include "stack.h"
#include "search.h"

void show_msg(void) {
    fprintf(stdout, "Menu: \n");
    fprintf(stdout, "  1. linear search\n");
    fprintf(stdout, "  2. binary search\n");
    fprintf(stdout, "  3. hash search\n");
    fprintf(stdout, "  0. ending\n");
}

void show_stack(struct list *list) {
    fprintf(stdout, "Stack: ");
    for(int i = 0; i <= list->top; i++) {
        fprintf(stdout, "%d -> ", list->val[i]);
    }
    fprintf(stdout, "NULL\n");
}

int main(void) {
    int ret, choice, target; 
    uint8_t input;
    struct list *list; 

    list = init(SIZE);
    fprintf(stdout, "Input %d values into list: \n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        fprintf(stdout, " Input val >> "); 
        scanf("%u", &input);
        push(list, input);
    }
    show_stack(list);

    show_msg();
    fprintf(stdout, "choose the search type: ");
    scanf("%d", &choice);
    fprintf(stdout, "input target to find >> ");
    scanf("%d", &target);
    while (choice != 0) {
        switch(choice) {
            case 1:
                ret = linearsearch(list, target);
                if (ret) fprintf(stderr, "Not found.\n");
                break;
            case 2:
                printf("DEBUG\n");
                ret = binarysearch(list, target);
                if (ret) fprintf(stderr, "Not found.\n");
                break;
            case 3:
                ret = hashsearch(list, target);
                if (ret) fprintf(stderr, "Not found.\n");
                break;
            default:
                break;
        }
        show_msg();
        fprintf(stdout, "choose the search type: ");
        scanf("%d", &choice);
        //if (choice == 0) break;
        fprintf(stdout, "input target to find >> ");
        scanf("%d", &target);
    }

    return 0;
}
