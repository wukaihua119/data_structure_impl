#ifndef TREE_H_
#define TREE_H_
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define INORDER   0
#define PREORDER  1
#define POSTORDER 2

struct _node {
    uint8_t val;
}; 

typedef struct _binary_node {
    uint8_t val;
    struct _binary_node *left;
    struct _binary_node *right;
}bintree_node;

/* left -> node -> right */
static void inorder(bintree_node *node) { 
    if (node != NULL) {
        inorder(node->left);
        fprintf(stdout, "%u ", node->val);
        inorder(node->right);
    }
}

/* node -> left -> right */
static void preorder(bintree_node *node) {
    if (node != NULL) {
        fprintf(stdout, "%u ", node->val);
        preorder(node->left);
        preorder(node->right);
    }
}

/* left -> right -> node */
static void postorder(bintree_node *node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        fprintf(stdout, "%u ", node->val);
    }
}

typedef void (*order_fn_p)(bintree_node *);
static order_fn_p order_fn[3] = {
    inorder,
    preorder,
    postorder
};

static void traverse(bintree_node *node, int order) {
    order_fn[order](node);
    fprintf(stdout, "\n");
}

/* util functions */ 
static bintree_node __attribute__((used)) *_find_min(bintree_node *tree) {
    if (!tree) return NULL;
    if (tree->left == NULL) return tree;
    return _find_min(tree->left);
}

static bintree_node __attribute__((used)) *_find_max(bintree_node *tree) {
    if (!tree) return NULL;
    if (tree->right == NULL) return tree;
    return _find_max(tree->right);
}

static bintree_node __attribute__((used)) *_find(bintree_node *tree, uint8_t val) {
    if (!tree) return NULL;
    if (tree->val == val) 
        return tree;
    else if (tree->val > val) 
        return _find(tree->left, val); 
    else if (tree->val < val) 
        return _find(tree->right, val); 
    return NULL;
}

static int __attribute__((used)) _isequal(bintree_node *first, bintree_node *second) {
    if (!first && !second) return 1;
    if (!first || !second) return 0;
    return (first->val == second->val) && 
           _isequal(first->left, second->left) && 
           _isequal(first->right, second->right);
}

static int __attribute((used)) _get_height(bintree_node *tree) {
    if (tree == NULL) return 0; 

    int height_l = _get_height(tree->left);
    int height_r = _get_height(tree->right);
    int ret = (height_r >= height_l)? height_r : height_l;
    return ret + 1;
}

static int __attribute((used)) _get_counts(bintree_node *tree) {
    if (tree == NULL) return 0;

    int _count_l = _get_counts(tree->left);
    int _count_r = _get_counts(tree->right);
    return _count_l + _count_r +1;
}

static int __attribute__((used)) _get_leaf_counts(bintree_node *tree) {
    if (tree == NULL) return 0;
    int _leaf_l = _get_leaf_counts(tree->left);
    int _leaf_r = _get_leaf_counts(tree->right);
    if ((_leaf_l + _leaf_r) > 0) return _leaf_l + _leaf_r;
    else return 1;
    /* Another solution:
    if (tree == NULL) return 0;
    if (tree->left == NULL && tree->right == NULL) return 1;
    int left = get_leaf(tree->left);
    int right = get_leaf(tree->right);
    return (left + right);
    */
}

#ifdef BINARY_ARRAY
#define NODE_SIZE 1024
uint8_t binary_tree_arr[NODE_SIZE];
#endif
#endif 
