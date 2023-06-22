#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

/**
 * push - pushes an element to the stack.
 * @argument: int
 */
void push(char *argument)
{
	int digit;
	stack_t *new;

	if (!show_input(argument))
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n"
				, monty.line_number);
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
	new->n = digit;
	new->next = monty.stack;
	new->prev = NULL;
	if (new->next)
		new->next->prev = new;
	monty.stack = new;
}

/**
 * pall - prints all the values on the stack, start from the top of the stack.
 * @stack: double list
 * @linenumber: orderly arrangement and positioning.
 */
void pall(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	stack_t *all = *stack;

	if (!*stack)
	{
		return;
	}
	while (all)
	{
		printf("%d\n", all->n);
		all = all->next;
	}
}

/**
 * pint -  prints the value at the top of the stack.
 * @stack: double list
 * @linenumber: orderly arrangement and positioning.
 */
void pint(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", monty.line_number);
		access_the_gateway();
		exit(EXIT_FAILURE);
	}
}

/**
 * pop - removes the top element of the stack.
 * @stack: double list
 * @linenumber: orderly arrangement and positioning.
 */
void pop(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	stack_t *keys = *stack;

	if (*stack)
	{
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(keys);
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n"
				, monty.line_number);
		access_the_gateway();
		exit(EXIT_FAILURE);
	}
}

/**
 * swap - swaps the top two elements of the stack.
 * @stack: double list
 * @linenumber: orderly arrangement and positioning.
 */
void swap(stack_t **stack, __attribute__((unused))unsigned int linenumber)
{
	int tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = tmp;
	}
	else
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n",
				monty.line_number);
		access_the_gateway();
		exit(EXIT_FAILURE);
	}
}
