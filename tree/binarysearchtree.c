#include "bintree.h"

static bintree_node *search_insert_pos(bintree_node *tree, uint8_t val) {
    bintree_node *inser_node;

    if (!tree) return NULL;
    if (tree->val > val) 
        inser_node = search_insert_pos(tree->left, val); 
    else if (tree->val < val) 
        inser_node = search_insert_pos(tree->right, val); 

    return (inser_node == NULL) ? tree : inser_node;
}

#ifdef OPT_BST
static bintree_node *insert(bintree_node *root, uint8_t val) {
    if (root == NULL) {
        root = (bintree_node *) malloc(sizeof(bintree_node));
        if (root == NULL) {
            fprintf(stderr, "No space\n");
            return NULL;
        }
        root->val = val;
        root->left = NULL;
        root->right = NULL;
    } else {
        if (root->val < val) 
            root->right = insert(root->right, val); 
        else if (root->val > val) 
            root->left = insert(root->left, val); 
    }
    return root; 
}
#endif 

int insert_node(bintree_node **tree, uint8_t val){ 
#ifndef OPT_BST
    bintree_node *newnode; 
    bintree_node *insertnode;

    insertnode = find(*tree, val);
    if (insertnode) {
        fprintf(stderr, "The val exist\n");
        return -1;
    }

    newnode = (bintree_node *) malloc(sizeof(bintree_node));
    if (newnode == NULL) {
        fprintf(stderr, "No space\n");
        return -1;
    }

    newnode->val = val;
    newnode->left = NULL;
    newnode->right = NULL;

    if (*tree == NULL)
        *tree = newnode;
    else {
        insertnode = search_insert_pos(*tree, val); 
        if (insertnode->val < val) 
            insertnode->right = newnode;
        else 
            insertnode->left = newnode;
    }
#else
    bintree_node *root = *tree;
    *tree = insert(root, val); 
#endif
    return 0;
}

bintree_node *del_node(bintree_node **tree, uint8_t val) {
    bintree_node *cur = *tree;

    if (cur == NULL) {
        fprintf(stderr, "The target node not found!\n");
        return NULL;
    } else if (val < cur->val) 
        cur->left = del_node(&cur->left, val);
    else if (val > cur->val) 
        cur->right = del_node(&cur->right, val);
    else {
        bintree_node *del;
        if (cur->left == NULL && cur->right == NULL) {/* the deleted node has no child */
            del = cur;
            cur = NULL;
            free(del);
        } else if (cur->left == NULL) { /* the delete node has only right child */ 
            del = cur; 
            cur = cur->right;
            free(del);
        } else if (cur->right == NULL) { /* the delete node has only left child */ 
            del = cur; 
            cur = cur->left;
            free(del);
        } else { /* the delete node has 2 children */ 
            bintree_node *tmp = _find_min(cur->right);
            cur->val = tmp->val; 
            cur->right = del_node(&cur->right, tmp->val);
        }
    }
    return cur;
}

bintree_node *search(bintree_node *tree, uint8_t val) {
    return _find(tree, val);
}

bintree_node *find_max_node(bintree_node *tree) {
    return _find_max(tree);
}

bintree_node *find_min_node(bintree_node *tree) {
    return _find_min(tree);
}

int isequal(bintree_node *first, bintree_node *second) {
    return _isequal(first, second); 
}

int get_height(bintree_node *tree) {
    return _get_height(tree);
}

int get_counts(bintree_node *tree) {
    return _get_counts(tree); 
}

int get_leaf_counts(bintree_node *tree) {
    return _get_leaf_counts(tree); 
}

int destroy(bintree_node *tree) {
    if (tree != NULL) {
        destroy(tree->left);
        destroy(tree->right);
        free(tree);
    }
    return 0;
}
