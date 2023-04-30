#include "list.h"
#include "queue.h"

struct list_info *init(const int size) {
    struct list_info *ini =
        (struct list_info *) malloc(size * sizeof(struct list_info));
    if (!ini) {
        ERROR_MSG("CANNOT ALLOCATE MEMORY FOR list_info");
        return NULL;
    }
    
    struct list *h = 
        (struct list *) malloc(sizeof(struct list));
    if (!h) {
        ERROR_MSG("CANNOT ALLOCATE MEMORY FOR list");
        return NULL;
    }
    ini->head = h;
    ini->tail = h;
    ini->size = size;
    ini->cur_size = 1;
    
    return ini;
}
int enqueue(struct list_info *list_f, uint8_t val){
}

int dequeue(struct list_info *list_f){ 
}

int destroy(struct list_info *list_f){
}
