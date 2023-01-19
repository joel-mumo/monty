#include "monty.h"

/**
 * _push - adds node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: Nothing
 */
void _push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (func.arg)
	{
		if (func.arg[0] == '-')
			j++;
		for (; func.arg[j] != '\0'; j++)
		{
			if (func.arg[j] > 57 || func.arg[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(func.file);
			free(func.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(func.file);
		free(func.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(func.arg);
	if (func.push == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
