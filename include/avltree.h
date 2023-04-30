#pragma once
#include "tree.h"

int insert_node(bintree_node **tree, uint8_t val);
int delete_node(bintree_node **tree, uint8_t val);
int get_height(bintree_node *tree); 
int destroy(bintree_node *tree);
