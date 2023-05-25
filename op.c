#include "monty.h"

/**
 * push - adds item to start of stack
 * @stack: list
 * @n: integer
 * Return: node added
*/
stack_t *push(stack_t **stack, int n)
{
	stack_t *node = malloc(sizeof(stack_t));

	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = n;
	node->next = (*stack);

	if ((*stack) != NULL)
		(*stack)->prev = node;
	(*stack) = node;

	return (node);
}

/**
 * pall - prints data items in stack
 * @stack: list
 * Return: number of items printed
*/

int pall(stack_t **stack)
{
	stack_t *list;
	int i = 0;

	if ((*stack) == NULL)
		return (0);

	list = *stack;

	while (list != NULL)
	{
		printf("%d\n", list->n);
		list = list->next;
		i += 1;
	}
	return (i);
}

/**
 * pint - prints the value at the top of the stack
 * @stack: the stack
 * Return: node at the top
*/

stack_t *pint(stack_t **stack)
{
	stack_t *node;

	if ((*stack) == NULL)
		return (NULL);

	node = *stack;

	printf("%d\n", node->n);
	return (node);
}
