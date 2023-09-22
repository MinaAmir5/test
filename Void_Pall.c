#include "monty.h"
/**
 * Void_Pall - prints the stack
 * @Copy_Stack_Head: stack head
 * @Copy_U32_Counter: not used
*/
void Void_Pall(stack_t **Copy_Stack_Head, unsigned int Copy_U32_Counter)
{
	stack_t *Local_Stack_Queue;
	(void)Copy_U32_Counter;

	Local_Stack_Queue = *Copy_Stack_Head;
	while (Local_Stack_Queue)
	{
		printf("%d\n", Local_Stack_Queue->n);
		Local_Stack_Queue = Local_Stack_Queue->next;
	}
}
