#include "monty.h"
/**
 * Void_Push - push to the stack
 * @Copy_Stack_Head: stack head
 * @Copy_U32_Counter: line number
*/
void Void_Push(stack_t **Copy_Stack_Head, unsigned int Copy_U32_Counter)
{
	int Local_U32_Data, Local_U32_Counter = 0;

	if (!Global_Par.Global_U8_Par)
	{
		fprintf(stderr, "L%d: usage: push integer\n", Copy_U32_Counter);
		Void_FreeStack(*Copy_Stack_Head);
		free(Global_Par.Global_U8_Value);
		fclose(Global_Par.Global_File);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (Global_Par.Global_U8_Par[0] == '-')
			Local_U32_Counter++;
		while (Global_Par.Global_U8_Par[Local_U32_Counter] != '\0')
		{
			if (Global_Par.Global_U8_Par[Local_U32_Counter] > 57 ||
				Global_Par.Global_U8_Par[Local_U32_Counter] < 48)
			{
				fprintf(stderr, "L%d: usage: push integer\n", Copy_U32_Counter);
				Void_FreeStack(*Copy_Stack_Head);
				free(Global_Par.Global_U8_Value);
				fclose(Global_Par.Global_File);
				exit(EXIT_FAILURE);
			}
			Local_U32_Counter++;
		}
	}

	Local_U32_Data = atoi(Global_Par.Global_U8_Par);
	if (Global_Par.Global_U32_Queue == 0)
		Void_AddStack(Copy_Stack_Head, Local_U32_Data);
	else
		Void_AddQueue(Copy_Stack_Head, Local_U32_Data);
}
