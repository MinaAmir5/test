#include "monty.h"
/**
 * f_queue - select LIFI
 * @Copy_Stack_Head: stack head
 * @Copy_U32_Counter: line number
*/
void f_queue(stack_t **Copy_Stack_Head, unsigned int Copy_U32_Counter)
{
	(void)Copy_Stack_Head;
	(void)Copy_U32_Counter;
	bus.lifi = 1;
}

/**
 * addqueue - add node to the stack tail
 * @Copy_U32_Value: new value
 * @Copy_Stack_Head: stack head
*/
void addqueue(stack_t **Copy_Stack_Head, int Copy_U32_Value)
{
	stack_t *Local_Stack_NewNode, *Local_Stack_Tail;

	Local_Stack_NewNode = malloc(sizeof(stack_t));
	if (Local_Stack_NewNode == NULL)
		printf("Error\n");
	Local_Stack_Tail = *Copy_Stack_Head;
	while ((*Copy_Stack_Head) && Local_Stack_Tail->next)
		Local_Stack_Tail = Local_Stack_Tail->next;
	Local_Stack_NewNode->next = NULL;
	Local_Stack_NewNode->n = Copy_U32_Value;
	if (!Local_Stack_Tail)
	{
		Local_Stack_NewNode->prev = NULL;
		*Copy_Stack_Head = Local_Stack_NewNode;
	}
	else
	{
		Local_Stack_NewNode->prev = Local_Stack_Tail;
		Local_Stack_Tail->next = Local_Stack_NewNode;
	}
}
