#include "monty.h"

/**
 * add_node - push or queue an element at the begining of a stack
 * @head: head pointer
 * @n: value to be added
 * Return: pointer to new node or NULL
 */

stack_t *add_node(stack_t **head, const int n)
{
	stack_t *node;

	if (!head)
		return (NULL);

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		return (NULL);

	node->n = n;
	node->prev = NULL;
	node->next = *head;

	if (*head)
		(*head)->prev = node;
	*head = node;
	return (node);
}

/**
 * free_stack - free all memory in use
 * @head: head pointer
 */

void free_stack(stack_t *head)
{
	stack_t *cur;

	while (head != NULL)
	{
		cur = head;
		head = head->next;
		free(cur);
	}
}
