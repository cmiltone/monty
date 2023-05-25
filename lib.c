#include "monty.h"

/**
 * exec_op - executes operations
 * @stack: stack
 * @cmd: command,
 * @line_no: integer
 *
 * Return: void
*/

void exec_op(stack_t **stack, command_t *cmd, int line_no)
{
	char *opcode = cmd->opcode;
	stack_t *node;

	if (strcmp(opcode, "push") == 0)
	{
		push(stack, cmd->arg);
	} else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack);
	} else if (strcmp(opcode, "pint") == 0)
	{
		node = pint(stack);
		if (node == NULL)
		{
			fprintf(stderr, "L%d: can't pop an empty stack\n", line_no);
			exit(EXIT_FAILURE);
		}
	} else if (strcmp(opcode, "pop") == 0)
	{
		node = pop(stack);
		if (node == NULL)
		{
			fprintf(stderr, "L%d: can't pop an empty stack\n", line_no);
			exit(EXIT_FAILURE);
		}
	} else if (strcmp(opcode, "nop") == 0)
	{
		nop(stack);
	} 
}

/**
 * parse - converts input to valid command
 * @opcode: input string
 * @arg: argument
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

	if (strcmp(opcode, "push") != 0 &&
		strcmp(opcode, "pall") != 0 &&
		strcmp(opcode, "pint") != 0 &&
		strcmp(opcode, "pop") != 0 &&
		strcmp(opcode, "nop") != 0)
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

		exec_op(stack, cmd, i);
		i += 1;
		if (feof(file))
			break;
	}
}


/**
 * nop - does nothing
 * Return: nuthing
*/

void nop() {
	return;
}
