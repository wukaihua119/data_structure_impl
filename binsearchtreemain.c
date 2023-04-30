#include <stdio.h>
#include <stdlib.h>
#include "bintree.h" 

static void show_msg(void) { 
    fprintf(stdout, "\nMenu: \n");
    fprintf(stdout, "  1. add element to binary search tree\n");
    fprintf(stdout, "  2. delete element to binary search tree\n");
    fprintf(stdout, "  3. find the max value of the binary search tree\n");
    fprintf(stdout, "  4. find the min value of the binary search tree\n");
    fprintf(stdout, "  5. find the value in the binary search tree\n");
    fprintf(stdout, "  6. get the height of the binary search tree\n");
    fprintf(stdout, "  7. get the number of the node of the binary search tree\n");
    fprintf(stdout, "  8. get the number of the leaf of the binary search tree\n");
    fprintf(stdout, "  0. quit\n");
}

int main(void) {
    bintree_node *root = NULL, *tmp;
    int choose, ret;
    uint8_t input; 
    int height, cnts, leaf_cnts; 

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
                root = del_node(&root, input);
                if (root) traverse(root, INORDER);
                break; 
            case 3:
                tmp = find_max_node(root);
                if (tmp) fprintf(stdout, "max value is %u\n", tmp->val);
                break;
            case 4:
                tmp = find_min_node(root);
                if (tmp) fprintf(stdout, "min value is %u\n", tmp->val);
                break;
            case 5:
                fprintf(stdout, "Input a number to search tree, 0 to 255:\n");
                scanf("%u", &input);
                tmp = search(root, input);
                if (tmp) 
                    fprintf(stdout, "Found\n");
                else 
                    fprintf(stdout, "Not found\n"); 
                break;
            case 6:
                height = get_height(root);
                fprintf(stdout, "The height of the tree is %d\n", height);
                break;
            case 7:
                cnts = get_counts(root);
                fprintf(stdout, "The number of nodes of the tree is %d\n", cnts);
                break;
            case 8:
                leaf_cnts = get_leaf_counts(root);
                fprintf(stdout, "The number of nodes of the tree is %d\n", leaf_cnts);
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
