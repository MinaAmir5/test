#include "monty.h"
/**
  *f_rotl- rotates the stack to the top
  *@head: stack head
  *@counter: line_number
 */
void f_rotl(stack_t **head, unsigned int counter)
{
	stack_t *tmp, *aux;
	(void)counter;

	tmp = *head;
	if (tmp && tmp->next)
	{
		while (tmp->next)
			tmp = tmp->next;
		(*head)->next->prev = NULL;
		tmp->next = *head;
		aux = (*head)->next;
		(*head)->prev = tmp;
		(*head)->next = NULL;
		(*head) = aux;
	}
}
