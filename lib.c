#include "monty.h"

/**
 * exec_op - executes operations
 * @stack: stack
 * @opcode: string
 * @n: string
 *
 * Return: void
*/

void exec_op(stack_t **stack, command_t *cmd)
{
  char *opcode = cmd->opcode;

  if (strcmp(opcode, "push") == 0)
  {
    push(stack, cmd->arg);
  } else if (strcmp(opcode, "pall") == 0)
  {
    pall(stack);
  }
}

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
  int i = 0;
  while ((*stack) != NULL)
  {
    printf("%d\n", (*stack)->n);
    (*stack) = (*stack)->next;
    i += 1;
  }
  return (i);
}

/**
 * parse - converts input to valid command
 * @line: input string
 * @line_no: line number
 * Return: valid command with arg
*/

command_t *parse(char *opcode, char *arg, int line_no)
{
  command_t *cmd = malloc(sizeof(command_t));

  if (cmd == NULL)
  {
    fprintf(stderr, "Error: malloc failed\n");
    exit(EXIT_FAILURE);
  }

  if (strcmp(opcode, "push") != 0 && strcmp(opcode, "pall") != 0)
  {
    fprintf(stderr, "L%d: unknown instruction %s\n", line_no, opcode);
    exit(EXIT_FAILURE);
  }

  if (arg != NULL)
    cmd->arg = atoi(arg);
  cmd->opcode = opcode;

  return (cmd);
}


/**
 * monty - reads cmds from file and executes them
 * @filename: the name of the input file
 * @stack: the stack
 * Return: nothing
*/
void monty(char *filename, stack_t **stack)
{
  char line[MAX_LINE_SIZE], *op, *arg;
  int i = 1;
  FILE *file;
  command_t *cmd;

  file = fopen(filename, "r");

  if (file == NULL)
  {
    fprintf(stderr, "Error: Can't open file %s\n", filename);
    exit(EXIT_FAILURE);
  }

  while (1)
  {
    fgets(line, MAX_LINE_SIZE, file);
    op = strtok(line, " \n");
    arg = strtok(NULL, " \n");
    cmd = parse(op, arg, i);

    exec_op(stack, cmd);
    i += 1;
    if (feof(file))
      break;
  }
}
