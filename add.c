#include "monty.h"
/**
 * f_add - adds the top two elements of the stack.
 * @Copy_Stack_Head: stack head
 * @Copy_U32_Counter: line number
*/
void f_add(stack_t **Copy_Stack_Head, unsigned int Copy_U32_Counter)
{
	stack_t *Local_Stack_Queue;

	Local_Stack_Queue = *Copy_Stack_Head;
	if (Local_Stack_Queue && Local_Stack_Queue->next)
	{
		Local_Stack_Queue->next->n = Local_Stack_Queue->n +
			Local_Stack_Queue->next->n;
		*Copy_Stack_Head = Local_Stack_Queue->next;
		free(Local_Stack_Queue);
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", Copy_U32_Counter);
		free(bus.content);
		free_stack(*Copy_Stack_Head);
		fclose(bus.file);
		exit(EXIT_FAILURE);
	}
}
