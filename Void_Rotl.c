#include "monty.h"
/**
  *Void_Rotl- rotates the stack to the top
  *@Copy_Stack_Head: stack head
  *@Copy_U32_Counter: line number
 */
void Void_Rotl(stack_t **Copy_Stack_Head, unsigned int Copy_U32_Counter)
{
	stack_t *Local_Stack_Temp, *Local_Stack_Copy;
	(void)Copy_U32_Counter;

	Local_Stack_Temp = *Copy_Stack_Head;
	if (Local_Stack_Temp && Local_Stack_Temp->next)
	{
		while (Local_Stack_Temp->next)
			Local_Stack_Temp = Local_Stack_Temp->next;
		(*Copy_Stack_Head)->next->prev = NULL;
		Local_Stack_Temp->next = *Copy_Stack_Head;
		Local_Stack_Copy = (*Copy_Stack_Head)->next;
		(*Copy_Stack_Head)->prev = Local_Stack_Temp;
		(*Copy_Stack_Head)->next = NULL;
		(*Copy_Stack_Head) = Local_Stack_Copy;
	}
}
