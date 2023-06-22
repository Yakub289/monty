#include "monty.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * nop - doesn’t do anything.
 * @stack: stack idle
 * @linenumber: orderly arrangement and positioning.
 */
void nop(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	(void)stack;
}

/**
 * pchar- prints the char at the top of the stack (not ascii table).
 * @stack: points to head of stack
 * @linenumber: orderly arrangement and positioning.
 *
 */
void pchar(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	if (!(*stack))
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n"
				, monty.line_number);
		access_the_gateway();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, value out of range\n",
				monty.line_number);
		access_the_gateway();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr- prints the string starting at the top of the stack.
 * @stack: head of stack
 * @linenumber: orderly arrangement and positioning.
 *
 */
void pstr(stack_t **stack,  __attribute__((unused))unsigned int linenumber)
{
	stack_t *bench_sd = *stack;

	while (bench_sd && bench_sd->n > 0 && bench_sd->n <= 127)
	{
		putchar(bench_sd->n);
		bench_sd = bench_sd->next;
	}
	putchar('\n');
}

/**
 * rotl -  rotates the stack to the top.
 * @stack: stack flow
 * @linenumber: orderly arrangement and positioning.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	stack_t *front, *rear;

	if (!*stack || !(*stack)->next)
	{
		return;
	}

	front = *stack;
	rear = (*stack)->next;
	*stack = rear;
	rear->prev = NULL;

	while (rear->next)
	{
		rear = rear->next;
	}
	rear->next = front;
	front->next = NULL;
	front->prev = rear;
}

/**
 * rotr- rotates the stack to the bottom.
 * @stack: head of stack
 * @linenumber: orderly arrangement and positioning.
 *
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	stack_t *front, *rear;

	if (!(*stack) || !(*stack)->next)
	{
		return;
	}

	front = *stack;

	while (front->next->next)
	{
		front = front->next;
	}
	rear = front->next;
	front->next = NULL;
	(*stack)->prev = rear;
	rear->next = *stack;
	rear->prev = NULL;
	*stack = rear;
}
