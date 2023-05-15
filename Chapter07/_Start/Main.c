#include <assert.h>
#include <stdio.h>

#include "BinarySearchTree.h"

int main(void)
{
    node_t *root = createBST(42.0f);
    node_t *node2 = createBST(22.0f);
    node_t *node3 = createBST(52.0f);
    node_t *node4 = createBST(60.0f);

    insertNode(root, node2);
    insertNode(root, node3);
    insertNode(root, node4);

    printf("Start print!\n");
    printBST(root);

    (void)removeNode(root, 60.0f);

    printf("Start print!\n");
    printBST(root);

    (void)removeNode(root, 42.0f);

    printf("Start print!\n");
    printBST(root);

    node4 = freeBST(node4);
    node3 = freeBST(node3);
    node2 = freeBST(node2);
    root = freeBST(root);
    assert(NULL == root);
    assert(NULL == node2);
    assert(NULL == node3);
    assert(NULL == node4);
}
