#include <stdio.h>
#include <stdlib.h>
#include "avltree.h" 
#include "tree.h"

static void show_msg(void) { 
    fprintf(stdout, "\nMenu: \n");
    fprintf(stdout, "  1. add element to binary search tree\n");
    fprintf(stdout, "  2. delete element to binary search tree\n");
    fprintf(stdout, "  3. get the height of the tree\n"); 
    fprintf(stdout, "  0. quit\n");
}

int main(void) {
    bintree_node *root = NULL;
    int choose, ret;
    uint8_t input; 

    show_msg();
    scanf("%d", &choose);
    while(choose != 0) {
        switch(choose) {
            case 1:  
                fprintf(stdout, "Input a number to tree, 0 to 255:\n");
                scanf("%u", &input);
                ret = insert_node(&root, input);
                if (!ret) traverse(root, INORDER);
                break;
            case 2:
                fprintf(stdout, "Input a number to delete from tree, 0 to 255:\n");
                scanf("%u", &input);
                ret = delete_node(&root, input);
                if (!ret) traverse(root, INORDER);
                break; 
            case 3:
                fprintf(stdout, "Get the height of the tree: ");
                int height = get_height(root);
                fprintf(stdout, "%d.\n", height); 
                break;
            default:
                fprintf(stderr, "Error: wrong choose\n");
        }
        show_msg();
        scanf("%d", &choose);
        fprintf(stdout, "\n");
    }

    fprintf(stderr, "quit\n");
    destroy(root); 
    return 0;
}
