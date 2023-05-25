#include "header.h"

/**
 * main - program entry point
 * @argc: number of arguments
 * @argv: arguments
 * Return: always 0
*/

int main(int argc, char **argv)
{
  stack_t *stack = malloc(sizeof(stack_t));
  stack_t hello = {8, NULL};
  stack_t *head;

  head = &hello;

  if (stack == NULL)
  {
    fprintf(stderr, "Error: malloc failed\n");
    exit(EXIT_FAILURE);
  }

  stack->n = 1;
  stack->next = head;

  head = stack;

  if (argc != 2)
  {
    fprintf(stderr, "USAGE: monty file\n");
    exit(EXIT_FAILURE);
  }
  monty(argv[1], head);
  print_stack(head);
  return (0);
}