#include "monty.h"
/**
* free_stack - frees the stack
* @head: head of the stack
*/
void free_stack(stack_t *head)
{
	stack_t *aux;

	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
