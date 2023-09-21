#include "monty.h"
/**
 * Void_Pstr - prints the string starting from the top of the stack
 * @Copy_Stack_Head: stack head
 * @Copy_U32_Counter: not used
*/
void Void_Pstr(stack_t **Copy_Stack_Head, unsigned int Copy_U32_Counter)
{
	stack_t *Local_Stack_Queue;
	(void)Copy_U32_Counter;

	Local_Stack_Queue = *Copy_Stack_Head;
	while (Local_Stack_Queue && (Local_Stack_Queue->n <= 127 &&
		Local_Stack_Queue->n > 0))
	{
		printf("%c", Local_Stack_Queue->n);
		Local_Stack_Queue = Local_Stack_Queue->next;
	}
	printf("\n");
}
