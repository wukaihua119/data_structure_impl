#ifndef BTREE_H_
#define BTREE_H_
#include "tree.h"

int insert_node(bintree_node **tree, uint8_t val);
bintree_node *del_node(bintree_node **tree, uint8_t val);
bintree_node *search(bintree_node *tree, uint8_t val);
bintree_node *find_max_node(bintree_node *tree);
bintree_node *find_min_node(bintree_node *tree);
int get_height(bintree_node *tree);
int get_counts(bintree_node *tree);
int get_leaf_counts(bintree_node *tree);
int isequal(bintree_node *first, bintree_node *second);
int destroy(bintree_node *tree);

#endif 
