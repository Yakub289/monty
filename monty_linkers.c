#include "monty.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

/**
 *  init_montyStruct - initialise and build the struct
 */
void init_montyStruct(void)
{

	monty.file = NULL;
	monty.line = NULL;
	monty.stack = NULL;
	monty.line_number = 1;
	monty.is_queue = false;
}

/**
 * show_correct_id - open a monty and validate input
 * @argc: args count
 * @filename: path to monty
 */
void show_correct_id(int argc, char *filename)
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty.file = fopen(filename, "r");
	if (!monty.file)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}

/**
 * print_line - reads and executes each line of input from monty file
 */
void print_line(void)
{
	size_t len = 0;
	ssize_t read;
	char *opcode, *digit;

	while ((read = getline(&monty.line, &len, monty.file) != -1))
	{
		opcode = strtok(monty.line, " ");
		if (*opcode == '#' || *opcode == '\n')
		{
			monty.line_number++;
			continue;
		}
		else if (strcmp(opcode, "push") == 0)
		{
			digit = strtok(NULL, " \n");
			if (monty.is_queue)
			{
				push_queue(digit);
			}
			else
				push(digit);
		}
		else
			op_choose(&monty.stack, opcode);
		monty.line_number++;
	}
}

/**
 * access_the_gateway - open pathway to all files.
 */
void access_the_gateway(void)
{
	fclose(monty.file);
	free(monty.line);
	build_case(monty.stack);
}

/**
 * show_input- show the int for intness
 * @str: the string
 * Return: false (0) or else true(value).
 */
bool show_input(char *str)
{
	int di = 0;

	if (!str)
	{
		return (false);
	}

	if (str[0] != '-' && !isdigit(str[0]))
	{
		return (false);
	}

	for (di = 1; str[di]; di++)
	{
		if (!isdigit(str[di]))
		{
			return (false);
		}
	}
	return (true);
}
