#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    const binary_tree_t *node1 = first, *node2 = second;
    size_t depth1 = 0, depth2 = 0;

    if (first == NULL || second == NULL)
        return (NULL);

    /* Compute depths of both nodes */
    while (node1->parent != NULL)
    {
        node1 = node1->parent;
        depth1++;
    }

    while (node2->parent != NULL)
    {
        node2 = node2->parent;
        depth2++;
    }

    /* Move the deeper node up until it's at the same depth as the other node */
    while (depth1 > depth2)
    {
        first = first->parent;
        depth1--;
    }

    while (depth2 > depth1)
    {
        second = second->parent;
        depth2--;
    }

    /* Move both nodes up until they have the same parent */
    while (first != second)
    {
        if (first == NULL || second == NULL)
            return (NULL);

        first = first->parent;
        second = second->parent;
    }

    return ((binary_tree_t *) first);
}

