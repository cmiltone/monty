#include "monty.h"

/**
 * main - program entry point
 * @argc: number of arguments
 * @argv: arguments
 * Return: always 0
*/

int main(int argc, char **argv)
{
	stack_t *head;

	head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty(argv[1], &head);
	return (0);
}