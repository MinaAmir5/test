#include "monty.h"
/**
 * f_swap - swaps the top two elements of the stack.
 * @Copy_Stack_Head: stack head
 * @Copy_U32_Counter: line number
*/
void f_swap(stack_t **Copy_Stack_Head, unsigned int Copy_U32_Counter)
{
	stack_t *Local_Stack_Queue;
	int Local_U32_Container;

	Local_Stack_Queue = *Copy_Stack_Head;
	if (Local_Stack_Queue && Local_Stack_Queue->next)
	{
		Local_U32_Container = Local_Stack_Queue->next->n;
		Local_Stack_Queue->next->n = Local_Stack_Queue->n;
		Local_Stack_Queue->n = Local_U32_Container;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", Copy_U32_Counter);
		free_stack(*Copy_Stack_Head);
		free(bus.content);
		fclose(bus.file);
		exit(EXIT_FAILURE);
	}
}
