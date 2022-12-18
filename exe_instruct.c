#include "monty.h"

/**
 * execute - execute the appropriate function martching the opcode
 * @h: head pointer
 * @line: command line
 * @line_number: line number of the command line
 */

void execute(stack_t **h, char *line, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"pall", pall}, {NULL, NULL}

	};
	int i = 0;
	char *s;

	s = skip_spaces(line);
	if (s == NULL)
		return;
	if (strncmp(s, "push", strlen("push")) == 0)
	{
		push(h, line, line_number);
		return;
	}

	while (instruct[i].opcode)
	{
		if (strncmp(s, instruct[i].opcode, strlen(instruct[i].opcode)) == 0)
		{
			free(line);
			(instruct[i].f)(h, line_number);
			return;
		}
		i++;
	}
	printf("L%d: unknown instruction ", line_number);
	while (*s && (*s != ' ' && *s != '\t'))
		putchar(*s++);
	putchar('\n');
	free(line);
	free_stack(*h);
	*h = NULL;
	exit(EXIT_FAILURE);
}
