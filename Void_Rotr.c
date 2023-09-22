#include "monty.h"
/**
  *Void_Rotr- rotates the stack to the bottom
  *@Copy_Stack_Head: stack head
  *@Copy_U32_Counter: line number
 */
void Void_Rotr(stack_t **Copy_Stack_Head, unsigned int Copy_U32_Counter)
{
	stack_t *Local_Stack_Copy;
	(void)Copy_U32_Counter;

	Local_Stack_Copy = *Copy_Stack_Head;
	if (Local_Stack_Copy && Local_Stack_Copy->next)
	{
		while (Local_Stack_Copy->next)
			Local_Stack_Copy = Local_Stack_Copy->next;
		Local_Stack_Copy->next = *Copy_Stack_Head;
		(*Copy_Stack_Head)->prev = Local_Stack_Copy;
		(*Copy_Stack_Head) = Local_Stack_Copy;
		Local_Stack_Copy->prev->next = NULL;
		Local_Stack_Copy->prev = NULL;
	}
}
