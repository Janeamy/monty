#include "monty.h"

/**
 * pall - print all the elements in stack as int
 * @head: head pointer
 * @l: line number
 */

void pall(stack_t **head, unsigned int l)
{
	if (!head)
		return;
	while (*head != NULL)
	{
		printf("%d\n", (*head)->n);
		(*head) = (*head)->next;
	}
	(void) l;
}

