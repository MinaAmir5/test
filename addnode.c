#include "monty.h"
/**
 * Void_AddStack - add node to the stack
 * @Copy_Stack_Head: stack  head
 * @Copy_U32_Value: new value
*/
void Void_AddStack(stack_t **Copy_Stack_Head, int Copy_U32_Value)
{

	stack_t *Local_Stack_NewNode, *Local_Stack_Head;

	Local_Stack_NewNode = malloc(sizeof(stack_t));
	if (Local_Stack_NewNode == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	Local_Stack_Head = *Copy_Stack_Head;
	if (Local_Stack_Head)
		Local_Stack_Head->prev = Local_Stack_NewNode;
	Local_Stack_NewNode->prev = NULL;
	Local_Stack_NewNode->n = Copy_U32_Value;
	Local_Stack_NewNode->next = *Copy_Stack_Head;
	*Copy_Stack_Head = Local_Stack_NewNode;
}
