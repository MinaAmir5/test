#include "monty.h"
/**
 * Void_Pop - pop from stack
 * @Copy_Stack_Head: stack head
 * @Copy_U32_Counter: line number
*/
void Void_Pop(stack_t **Copy_Stack_Head, unsigned int Copy_U32_Counter)
{
	stack_t *Local_Stack_Queue;

	if (*Copy_Stack_Head != NULL)
	{
		Local_Stack_Queue = *Copy_Stack_Head;
		*Copy_Stack_Head = Local_Stack_Queue->next;
		free(Local_Stack_Queue);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", Copy_U32_Counter);
		free(Global_Par.Global_U8_Value);
		Void_FreeStack(*Copy_Stack_Head);
		fclose(Global_Par.Global_File);
		exit(EXIT_FAILURE);
	}
}
