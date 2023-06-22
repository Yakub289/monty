#include "monty.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * stack_control - sets the format of the data to a stack (LIFO).
 * @stack: head of stack
 * @linenumber: orderly arrangement and positioning.
 */
void stack_control(stack_t **stack, unsigned int linenumber)
{
	(void)stack;
	(void)linenumber;
	monty.is_queue = false;
}

/**
 * queue_control - sets the format of the data to a queue (FIFO).
 * @stack: head of stack
 * @linenumber: orderly arrangement and positioning.
 */
void queue_control(stack_t **stack, unsigned int linenumber)
{
	(void)stack;
	(void)linenumber;
	monty.is_queue = true;
}

/**
 * push_queue - add node to end list
 * @argument: int
 */
void push_queue(char *argument)
{
	int digit;
	stack_t *new, *bench_sd;

	if (!show_input(argument))
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n",
				monty.line_number);
		access_the_gateway();
		exit(EXIT_FAILURE);
	}

	digit = atoi(argument);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		access_the_gateway();
		exit(EXIT_FAILURE);
	}
	bench_sd = monty.stack;
	new->n = digit;
	new->next = NULL;
	if (!bench_sd)
	{
		new->prev = NULL;
		monty.stack = new;
		return;
	}
	while (bench_sd->next)
	{
		bench_sd = bench_sd->next;
	}
	bench_sd->next = new;
	new->prev = bench_sd;
}
