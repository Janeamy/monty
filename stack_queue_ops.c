#include "monty.h"

/**
 * push - add element to a stack/queue
 * @h: header pointer
 * @line: line pointer
 * @l: line number
 */

void push(stack_t **h, char *line, unsigned int l)
{
	char *s;
	stack_t *node;

	s = reach_number(line);
	if (s == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", l);
		free(line);
		free(*h);
		*h = NULL;
		exit(EXIT_FAILURE);
	}
	node = add_node(h, atoi(s));
	free(line);
	if (node == NULL)
	{
		puts("Error: malloc failed");
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
}
