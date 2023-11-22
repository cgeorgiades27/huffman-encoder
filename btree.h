#ifndef BTREE_H
#define BTREE_H

typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

} TreeNode;

TreeNode *insert_node_search(int *arr, int start, int end);
TreeNode *arr_to_search_tree(int *arr, int size);

#endif