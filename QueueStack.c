#include "monty.h"

/**
 * createNode - function that create a node
 * @n: Num to go in node
 * Return: if true a pointer to the node or NULL
 */
stack_t *createNode(int n)
{
stack_t *node;
node = malloc(sizeof(stack_t));
if (node == NULL)
fErr(4);
node->next = NULL;
node->prev = NULL;
node->n = n;
return (node);
}

/**
 * addToQueue - function that add the node to the queue
 * @nnode: new node pointer
 */
void addToQueue(stack_t **nnode)
{
stack_t *tmpvar;
if (nnode == NULL || *nnode == NULL)
exit(EXIT_FAILURE);
if (head == NULL)
{
head = *nnode;
return;
}
tmpvar = head;
while (tmpvar->next != NULL)
tmpvar = tmpvar->next;
tmpvar->next = *nnode;
(*nnode)->prev = tmpvar;
}
