#include "monty.h"
/**
* execute - executes the opcode
* @Copy_Stack: linked liest to the stack
* @Copy_U32_Counter: line counter
* @file: monty file
* @Copy_U8_Data: line content
*/
void execute(char *Copy_U8_Data, stack_t **Copy_Stack,
	unsigned int Copy_U32_Counter, FILE *file)
{
	char *Local_U8_OpCode;
	unsigned char Local_U8_Counter = 0;
	instruction_t Local_Instruction_Command[] = {
				{"push", f_push}, {"swap", f_swap},
				{"pall", f_pall}, {"mod", f_mod},
				{"pint", f_pint}, {"stack", f_stack},
				{"pop", f_pop}, {"nop", f_nop},
				{"add", f_add}, {"rotl", f_rotl},
				{"sub", f_sub}, {"pchar", f_pchar},
				{"div", f_div}, {"mul", f_mul},
				{"rotr", f_rotr}, {"pstr", f_pstr},
				{"queue", f_queue}, {NULL, NULL}
				};

	Local_U8_OpCode = strtok(Copy_U8_Data, " \n\t");
	if (Local_U8_OpCode && Local_U8_OpCode[0] != '#')
	{
		bus.arg = strtok(NULL, " \n\t");
		for (Local_U8_Counter = 0; Local_Instruction_Command[Local_U8_Counter].opcode
			&& Local_U8_OpCode; Local_U8_Counter++)
		{
			if (strcmp(Local_U8_OpCode, Local_Instruction_Command[
				Local_U8_Counter].opcode) == 0)
			{	Local_Instruction_Command[Local_U8_Counter].f(Copy_Stack,
				Copy_U32_Counter);
				break;
			}
		}
		if (Local_Instruction_Command[Local_U8_Counter].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", Copy_U32_Counter,
			Local_U8_OpCode);
			fclose(file);
			free_stack(*Copy_Stack);
			free(Copy_U8_Data);
			exit(EXIT_FAILURE);
		}
	}
}
