#include "list.h"
#include "stack.h"

int linearsearch(struct list *list, const uint8_t val) {
    for (int i = 0; i < list->capable; i++) {
        if (list->val[i] == val) {
            fprintf(stdout, "%u found\n", list->val[i]);
            return 0;
        }
    }
    return -1;
}
