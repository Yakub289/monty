#include "monty.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main- Entry point
 * @argc: args count
 * @argv: args vector
 *
 * Return: EXIT_SUCCESS
 */
int main(int argc, char **argv)
{

	init_montyStruct();
	show_correct_id(argc, argv[1]);
	print_line();
	access_the_gateway();
	return (EXIT_SUCCESS);
}

/**
 * op_choose - find & call the function that corresponds with the opcode
 * @stack: **pointer to stack
 * @opcode: opcode from this line of our monty file
 */
void op_choose(stack_t **stack, char *opcode)
{
	int i;
	char *op;
	instruction_t fncs[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_h},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack_control},
		{"queue", queue_control},
		{NULL, NULL}
	};

	op = strtok(opcode, "\n");
	for (i = 0; fncs[i].opcode; i++)
	{
		if (strcmp(op, fncs[i].opcode) == 0)
		{
			fncs[i].f(stack, monty.line_number);
			return;
		}
	}
	if (strcmp(opcode, "push"))
	{
		dprintf(STDERR_FILENO, "L%u: ", monty.line_number);
		dprintf(STDERR_FILENO, "unknown instruction %s\n", opcode);
	}
	else
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", monty.line_number);
	exit(EXIT_FAILURE);
}

/**
 * build_case - frees the stack
 * @h: the head of stack
 */
void build_case(stack_t *h)
{
	stack_t *temp;
	stack_t *build_sd = h;

	while (build_sd)
	{
		temp = build_sd;
		build_sd = build_sd->next;
		free(temp);
	}
}
