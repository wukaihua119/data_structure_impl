#include "avltree.h"

static bintree_node __attribute__((used)) *rotate_left(bintree_node *tree) { /* RR */
    bintree_node *ret;

    ret = tree->right;
    if (ret->left == NULL) { 
        ret->left = tree;
        tree->right = NULL;
    } else {
        tree->right = ret->left;
        ret->left = tree;
    }
    return ret; 
}

static bintree_node __attribute__((used)) *rotate_right(bintree_node *tree) { /* LL */ 
    bintree_node *ret;

    ret = tree->left;
    if (ret->right == NULL) {
        ret->right = tree;
        tree->left = NULL;
    } else {
        tree->left = ret->right;
        ret->right = tree;
    }
    return ret; 
}

static bintree_node __attribute__((used)) *rotate_right_left(bintree_node *tree) { /* LR */ 
    bintree_node *tmp, *tmp_left, *tmp_right;

    tmp = tree->left->right;
    tmp_right = tmp->right;
    tmp_left = tmp->left; 

    tmp->right = tree;
    tmp->left = tree->left;

    tmp->right->left = tmp_right;
    tmp->left->right = tmp_left; 

    return tmp; 
}

static bintree_node __attribute__((used)) *rotate_left_right(bintree_node *tree) { /* RL */
    bintree_node *tmp, *tmp_left, *tmp_right;

    tmp = tree->right->left;
    tmp_right = tmp->right;
    tmp_left = tmp->left; 

    tmp->left = tree;
    tmp->right = tree->right;

    tmp->right->left = tmp_right;
    tmp->left->right = tmp_left; 
    return tmp; 
}

static int __attribute__((used)) _check_unbalance(bintree_node *tree) {
    int unbalance = 1;
    int height_l, height_r; 

    height_l = _get_height(tree->left);
    height_r = _get_height(tree->right);
    unbalance = height_l - height_r; 
    return unbalance;
}

static int __attribute__((used)) _check_sub_unbal(bintree_node *tree) {
    int sub_level_l = _get_height(tree->left);
    int sub_level_r = _get_height(tree->right);
    return sub_level_l - sub_level_r; 
}

static bintree_node __attribute__((used)) *__check_rotation(bintree_node *tree) {
    int unbalance_level = _check_unbalance(tree); 
    if (unbalance_level >= 2) { /* LL LR */ 
        int sub_level = _check_sub_unbal(tree->left); 
        if (sub_level >= 1) { /* LL */
            tree = rotate_right(tree);
        } else if (sub_level <= -1) { /* LR */
            tree = rotate_right_left(tree);
        }
    } else if (unbalance_level <= -2) { /* RR RL */
        int sub_level = _check_sub_unbal(tree->right); 
        if (sub_level <= -1) { /* RR */
            tree = rotate_left(tree);
        } else if (sub_level >= 1) { /* RL */
            tree = rotate_left_right(tree);
        }
    }
    return tree; 
}

static bintree_node __attribute__((used)) *__insert(bintree_node *tree, uint8_t val) {
    if (tree == NULL) {
        tree = (bintree_node *) malloc(sizeof(bintree_node)); 
        if (!tree) {
            fprintf(stderr, "Error in allocating space for structure.\n");
            return NULL;
        }
        tree->val = val;
        tree->right = NULL;
        tree->left = NULL;
    } else if (tree->val > val) {
        tree->left = __insert(tree->left, val);
    } else if (tree->val < val) {
        tree->right = __insert(tree->right, val);
    }

    // rotation 
    tree = __check_rotation(tree); 
    return tree; 
}

static bintree_node __attribute__((used)) *__delete(bintree_node *tree, uint8_t val) {

    if (tree == NULL) {
        fprintf(stderr, "The target node not found!\n");
        return NULL;
    } else if (val < tree->val) 
        tree->left = __delete(tree->left, val);
    else if (val > tree->val) 
        tree->right = __delete(tree->right, val);
    else {
        bintree_node *del;
        if (tree->left == NULL && tree->right == NULL) {/* the deleted node has no child */
            del = tree;
            tree = NULL;
            free(del);
        } else if (tree->left == NULL) { /* the delete node has only right child */ 
            del = tree; 
            tree = tree->right;
            free(del);
        } else if (tree->right == NULL) { /* the delete node has only left child */ 
            del = tree; 
            tree = tree->left;
            free(del);
        } else { /* the delete node has 2 children */ 
            bintree_node *tmp = _find_min(tree->right);
            tree->val = tmp->val; 
            tree->right = __delete(tree->right, tmp->val);
        }
    }

    // rotation 
    if (tree) 
        tree = __check_rotation(tree); 
    return tree;
}

int get_height(bintree_node *tree) {
    return _get_height(tree); 
}

int insert_node(bintree_node **tree, uint8_t val) {
    *tree = __insert(*tree, val); 
    return 0;
}

int delete_node(bintree_node **tree, uint8_t val) {
    *tree = __delete(*tree, val); 
    return 0;
}

int destroy(bintree_node *tree) {
    if (tree != NULL) {
        destroy(tree->left);
        destroy(tree->right);
        free(tree);
    }
    return 0;
}
