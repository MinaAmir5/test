#include "monty.h"
/**
 * f_pop - pop from stack
 * @Copy_Stack_Head: stack head
 * @Copy_U32_Counter: line number
*/
void f_pop(stack_t **Copy_Stack_Head, unsigned int Copy_U32_Counter)
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
		free(bus.content);
		free_stack(*Copy_Stack_Head);
		fclose(bus.file);
		exit(EXIT_FAILURE);
	}
}
