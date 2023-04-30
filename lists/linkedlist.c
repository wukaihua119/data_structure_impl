#include "list.h"

static struct list *head, *tail;
static int size;

int insert_node(struct list **list, uint8_t val) {
    struct list *cur = NULL;
    struct list *new = (struct list *) malloc(sizeof(struct list));
    if (new == NULL) {
        fprintf(stderr, "CANNOT ALLOCATE SPACE FOR LINKED LIST NODE\n");
        return -1;
    }

    new->val = val;
    new->next = NULL;

    if (*list == NULL) {
        *list = new;
    } else { 
        cur = *list;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = new;
    }
    size++;
    return 0;
}

int insert_at(struct list **list, uint8_t val, int pos) {
    struct list *cur, *prev, *new;
    int cur_pos = 1;

    if (pos > size) {
        fprintf(stderr, "WRONG POSITION\n");
        return -1;
    }

    if (pos == 0 && *list == NULL)
        return insert_node(list, val);
    if (pos == size) 
        return insert_node(list, val);

    new = (struct list *) malloc(sizeof(struct list));
    if (!new) {
        fprintf(stderr, "CANNOT ALLOCATE SPACE FOR LINKED LIST NODE\n");
        return -1;
    }

    cur = *list;
    prev = NULL;
    while (cur != NULL) {
        if (cur_pos == pos) 
            break;
        prev = cur;
        cur = cur->next; 
        cur_pos++;
    }

    new->val = val;
    new->next = cur;
    if (prev != NULL)
        prev->next = new;
    else 
        *list = new;
    size++;
    return 0;
}

int delete_node(struct list **list, uint8_t val) {
    struct list *del, *prev, *cur;
    cur = *list; 
    prev = NULL;
    del = NULL;

    if (*list == NULL) {
        fprintf(stderr, "LINKED LIST IS EMPTY\n");
        return -1;
    }

    while (cur != NULL) {
        if (cur->val == val) {
            del = cur;
            break;
        }
        prev = cur;
        cur = cur->next; 
    }

    if (del == NULL) {
        fprintf(stderr, "CANNOT FIND THE VALUE TO DELETE\n");
        return -1;
    } 
    
    if (prev != NULL)
        prev->next = del->next;
    else 
        *list = del->next;
    free(del);

    size--;
    return 0;
}

int find_mid(struct list **list) {
    struct list *slow = *list, *fast = *list;

    if (*list == NULL) {
        fprintf(stderr, "The list is empty.\n");
        return -1;
    }
    while (slow != NULL && fast != NULL) {
        if (fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        } else break;
    }
    fprintf(stdout, "The middle is: %u\n", slow->val);
    return 0;
}

int reverse(struct list **list) {
    struct list *newlist = NULL, *tmp = NULL;
    struct list *cur = *list;

    if (cur == NULL) 
        return 0;

    while (cur != NULL) {
        tmp = cur;
        cur = cur->next;
        tmp->next = newlist;
        newlist = tmp;
    }

    *list = newlist;
    return 0;
}

int free_list(struct list **node) {
    struct list *free_node;
    for (struct list *traverse = *node; traverse != NULL; ) {
        free_node = traverse;
        traverse = traverse->next;
        free(free_node);
    }
    return 0;
}

void show(struct list **node) {
    fprintf(stdout, "Linked list: ");
    for (struct list *traverse = *node; traverse != NULL; traverse = traverse->next)
        fprintf(stdout, "%u -> ", traverse->val);
    fprintf(stdout, "NULL\n");
}
