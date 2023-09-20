#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
*/
void execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	char *op;
	unsigned int i = 0;
	instruction_t opst[] = {
				{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
				{"pop", f_pop},
				{"swap", f_swap},
				{"add", f_add},
				{"nop", f_nop},
				{"sub", f_sub},
				{"div", f_div},
				{"mul", f_mul},
				{"mod", f_mod},
				{"pchar", f_pchar},
				{"pstr", f_pstr},
				{"rotl", f_rotl},
				{"rotr", f_rotr},
				{"queue", f_queue},
				{"stack", f_stack},
				{NULL, NULL}
				};

	op = strtok(content, " \n\t");
	if (op && op[0] != '#')
	{
		bus.arg = strtok(NULL, " \n\t");
		for (i = 0; opst[i].opcode && op; i++)
		{
			if (strcmp(op, opst[i].opcode) == 0)
			{	opst[i].f(stack, counter);
				break;
			}
		}
		if (opst[i].opcode == NULL)
		{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
			fclose(file);
			free_stack(*stack);
			free(content);
			exit(EXIT_FAILURE); }
	}
}
