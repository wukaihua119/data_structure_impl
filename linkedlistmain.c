#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main (void) {
    struct list *head = NULL;
    int choose, ret, index;
    uint8_t input; 

    fprintf(stdout, "\n1 for add, 2 for del, 3 for add with given index, 4 for reverse, 5 for find middle, 6 for quit: \n");
    scanf("%d", &choose);
    while(choose != 6) {
        switch(choose) {
            case 1:
                fprintf(stdout, "Input a number from 0 to 255:\n");
                scanf("%u", &input);
                ret = insert_node(&head, input);
                if (!ret) show(&head);
                break;
            case 2:
                fprintf(stdout, "Input a number from 0 to 255 to delete from linked list:\n");
                scanf("%u", &input);
                ret = delete_node(&head, input);
                if (!ret) show(&head);
                break;
            case 3:
                fprintf(stdout, "Input a number from 0 to 255 at given index:\n");
                scanf("%u %d", &input, &index);
                ret = insert_at(&head, input, index);
                if (!ret) show(&head);
                break;
            case 4:
                fprintf(stdout, "Reverse the linked list\n");
                ret = reverse(&head);
                if (!ret) show(&head);
                break;
            case 5:
                fprintf(stdout, "Find the middle of the linked list\n");
                ret = find_mid(&head);
                break;
            default:
                fprintf(stderr, "Error: wrong choose\n");
        }
        fprintf(stdout, "\n1 for add, 2 for del, 3 for add with given index, 4 for reverse, 5 for find middle, 6 for quit: \n");
        scanf("%d", &choose);
        fprintf(stdout, "\n");
    }

    free_list(&head);

    return 0;
}
