#ifndef HEADER_H
#define HEADER_H

#define MAX_LINE_SIZE 1000

#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct command - command with argument
 * @opcode: opcode
 * @arg: argument
 * 
 * Description: command with its argument
*/
typedef struct command_s
{
	char *opcode;
	int arg;
} command_t;

void exec_op(stack_t **stack, command_t *cmd, int line_no);
stack_t *push(stack_t **stack, int n);
int pall(stack_t **stack);
stack_t *pint(stack_t **stack);
stack_t *pop(stack_t **stack);
void nop();
int count(stack_t **stack);
command_t *parse(char *opcode, char * arg, int line_no);
void monty(char *filename, stack_t **stack);

#endif
