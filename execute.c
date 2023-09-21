#include "monty.h"
/**
* Void_Execute - executes the opcode
* @Copy_Stack: linked liest to the stack
* @Copy_U32_Counter: line counter
* @file: monty file
* @Copy_U8_Data: line content
*/
void Void_Execute(char *Copy_U8_Data, stack_t **Copy_Stack,
	unsigned int Copy_U32_Counter, FILE *file)
{
	char *Local_U8_OpCode;
	unsigned char Local_U8_Counter = 0;
	instruction_t Local_Instruction_Command[] = {
				{"push", Void_Push}, {"swap", Void_Swap},
				{"pall", Void_Pall}, {"mod", Void_Mod},
				{"pint", Void_Pint}, {"stack", Void_Stack},
				{"pop", Void_Pop}, {"nop", Void_Nop},
				{"add", Void_Add}, {"rotl", Void_Rotl},
				{"sub", Void_Sub}, {"pchar", Void_Pchar},
				{"div", Void_Div}, {"mul", Void_Mul},
				{"rotr", Void_Rotr}, {"pstr", Void_Pstr},
				{"queue", Void_Queue}, {NULL, NULL}
				};

	Local_U8_OpCode = strtok(Copy_U8_Data, " \n\t");
	if (Local_U8_OpCode && Local_U8_OpCode[0] != '#')
	{
		Global_Par.Global_U8_Par = strtok(NULL, " \n\t");
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
			Void_FreeStack(*Copy_Stack);
			free(Copy_U8_Data);
			exit(EXIT_FAILURE);
		}
	}
}
