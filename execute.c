#include "monty.h"
/**
* execute - executes the opcode
* @Copy_Stack: head linked list - stack
* @Copy_U32_Counter: line_counter
* @file: poiner to monty file
* @Copy_U8_Data: line content
*/
void execute(char *Copy_U8_Data, stack_t **Copy_Stack, unsigned int Copy_U32_Counter, FILE *file)
{
	char *Local_U8_OpCode;
	unsigned char Local_U8_Counter = 0;
	instruction_t Local_Instruction_Command[] = {
				{"push", f_push},
				{"pall", f_pall},
				{"pint", f_pint},
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

	Local_U8_OpCode = strtok(Copy_U8_Data, " \n\t");
	if (Local_U8_OpCode && Local_U8_OpCode[0] != '#')
	{
		bus.arg = strtok(NULL, " \n\t");
		for (Local_U8_Counter = 0; Local_Instruction_Command[Local_U8_Counter].opcode &&
			Local_U8_OpCode; Local_U8_Counter++)
		{
			if (strcmp(Local_U8_OpCode, Local_Instruction_Command[Local_U8_Counter].opcode) == 0)
			{	Local_Instruction_Command[Local_U8_Counter].f(Copy_Stack, Copy_U32_Counter);
				break;
			}
		}
		if (Local_Instruction_Command[Local_U8_Counter].opcode == NULL)
		{ fprintf(stderr, "L%d: unknown instruction %s\n", Copy_U32_Counter, Local_U8_OpCode);
			fclose(file);
			free_stack(*Copy_Stack);
			free(Copy_U8_Data);
			exit(EXIT_FAILURE); }
	}
}