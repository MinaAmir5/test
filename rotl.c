#include "monty.h"
/**
  *f_rotl- rotates the stack to the top
  *@head: stack head
  *@counter: line number
 */
void f_rotl(stack_t **head, unsigned int counter)
{
	stack_t *tmp = *head, *aux;
	(void)counter;

	if (Local_Stack_Copy && Local_Stack_Copy->next)
	{
		while (tmp->next)
			tmp = tmp->next;
		aux = (*head)->next;
		(*head)->next->prev = NULL;
		tmp->next = *head;
		(*head)->next = NULL;
		(*head)->prev = tmp;
		(*head) = aux;
	}
}
