#include "monty.h"
/**
* free_stack - frees the stack
* @Copy_Stack_Head: head of the stack
*/
void free_stack(stack_t *Copy_Stack_Head)
{
	stack_t *Local_Stack_Temp;

	while (Copy_Stack_Head)
	{
		Local_Stack_Temp = Copy_Stack_Head->next;
		free(Copy_Stack_Head);
		Copy_Stack_Head = Local_Stack_Temp;
	}
}
