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
	char *Local_U8_OpCode;
	unsigned char Local_U8_Counter = 0;
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

	Local_U8_OpCode = strtok(content, " \n\t");
	if (Local_U8_OpCode && Local_U8_OpCode[0] != '#')
	{
		bus.arg = strtok(NULL, " \n\t");
		for (Local_U8_Counter = 0; opst[Local_U8_Counter].opcode &&
			Local_U8_OpCode; Local_U8_Counter++)
		{
			if (strcmp(Local_U8_OpCode, opst[Local_U8_Counter].opcode) == 0)
			{	opst[Local_U8_Counter].f(stack, counter);
				break;
			}
		}
		if (opst[Local_U8_Counter].opcode == NULL)
		{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, Local_U8_OpCode);
			fclose(file);
			free_stack(*stack);
			free(content);
			exit(EXIT_FAILURE); }
	}
}
