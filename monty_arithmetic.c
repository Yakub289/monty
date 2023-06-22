#include "monty.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * add - adds the top two elements of the stack.
 * @stack: double list
 * @linenumber: orderly arrangement and positioning.
 */
void add(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	stack_t *keys;

	if (*stack && (*stack)->next)
	{
		(*stack)->next->n += (*stack)->n;
		keys = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(keys);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n",
				monty.line_number);
		access_the_gateway();
		exit(EXIT_FAILURE);
	}
}
/**
 * sub - subtracts the top element of the stack from the second top element.
 * @stack: double list
 * @linenumber: orderly arrangement and positioning
 */
void sub(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	stack_t *keys;

	if (*stack && (*stack)->next)
	{
		(*stack)->next->n -= (*stack)->n;
		keys = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(keys);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n",
				monty.line_number);
		access_the_gateway();
		exit(EXIT_FAILURE);
	}
}
/**
 * div_h - divides the second top element of the stack by the top of element.
 * @stack: double list
 * @linenumber: orderly arrangement and positioning
 */
void div_h(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	stack_t *keys;

	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n"
				, monty.line_number);
		access_the_gateway();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", monty.line_number);
		access_the_gateway();
		exit(EXIT_FAILURE);
	}

	if (*stack && (*stack)->next)
	{
		(*stack)->next->n /= (*stack)->n;
		keys = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(keys);
	}
}
/**
 * mul - multiplies the second top element of the stack with the top element.
 * @stack: double list
 * @linenumber: orderly arrangement and positioning.
 */
void mul(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	stack_t *keys;

	if (*stack && (*stack)->next)
	{
		(*stack)->next->n *= (*stack)->n;
		keys = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(keys);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n",
				monty.line_number);
		access_the_gateway();
		exit(EXIT_FAILURE);
	}
}
/**
 * mod - The opcode mod computes the rest of the division,
 * of the second top element of the stack by the top element of the stack.
 * @stack: double list
 * @linenumber: orderly arrangement and positioning.
 */
void mod(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	stack_t *keys;

	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n"
				, monty.line_number);
		access_the_gateway();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", monty.line_number);
		access_the_gateway();
		exit(EXIT_FAILURE);
	}

	if (*stack && (*stack)->next)
	{
		(*stack)->next->n %= (*stack)->n;
		keys = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(keys);
	}
}
