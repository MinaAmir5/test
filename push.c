#include "monty.h"
/**
 * f_push - push to the stack
 * @Copy_Stack_Head: stack head
 * @Copy_U32_Counter: line number
*/
void f_push(stack_t **Copy_Stack_Head, unsigned int Copy_U32_Counter)
{
	int Local_U32_Data, Local_U32_Counter = 0;

	if (!bus.arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", Copy_U32_Counter);
		free_stack(*Copy_Stack_Head);
		free(bus.content);
		fclose(bus.file);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (bus.arg[0] == '-')
			Local_U32_Counter++;
		while (bus.arg[Local_U32_Counter] != '\0')
		{
			if (bus.arg[Local_U32_Counter] > 57 || bus.arg[Local_U32_Counter] < 48)
			{
				fprintf(stderr, "L%d: usage: push integer\n", Copy_U32_Counter);
				free_stack(*Copy_Stack_Head);
				free(bus.content);
				fclose(bus.file);
				exit(EXIT_FAILURE);
			}
			Local_U32_Counter++;
		}
	}

	Local_U32_Data = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(Copy_Stack_Head, Local_U32_Data);
	else
		addqueue(Copy_Stack_Head, Local_U32_Data);
}
