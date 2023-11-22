#include <stdlib.h>
#include "btree.h"

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

TreeNode *arr_to_search_tree(int *arr, int size)
{
    // sort array
    int array_size = sizeof(arr) / sizeof(arr[0]);
    qsort(arr, array_size, sizeof(int), compare);

    return insert_node_search(arr, 0, size - 1);
}

TreeNode *insert_node_search(int *arr, int start, int end)
{
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    TreeNode *root = malloc(sizeof(TreeNode));
    root->val = arr[mid];
    root->left = insert_node_search(arr, start, mid - 1);
    root->right = insert_node_search(arr, mid + 1, end);

    return root;
}
