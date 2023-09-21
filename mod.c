#include "monty.h"
/**
 * Void_Mod - computes the reminder of the division
 * @Copy_Stack_Head: stack head
 * @Copy_U32_Counter: line number
*/
void Void_Mod(stack_t **Copy_Stack_Head, unsigned int Copy_U32_Counter)
{
	stack_t *Local_Stack_Queue;

	Local_Stack_Queue = *Copy_Stack_Head;
	if (Local_Stack_Queue && Local_Stack_Queue->next)
	{
		if (Local_Stack_Queue->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", Copy_U32_Counter);
			Void_FreeStack(*Copy_Stack_Head);
			free(Global_Par.Global_U8_Value);
			fclose(Global_Par.Global_File);
			exit(EXIT_FAILURE);
		}
		Local_Stack_Queue->next->n = Local_Stack_Queue->next->n %
			Local_Stack_Queue->n;
		*Copy_Stack_Head = Local_Stack_Queue->next;
		free(Local_Stack_Queue);
	}
	else
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", Copy_U32_Counter);
		Void_FreeStack(*Copy_Stack_Head);
		free(Global_Par.Global_U8_Value);
		fclose(Global_Par.Global_File);
		exit(EXIT_FAILURE);
	}
}
