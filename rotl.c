#include "monty.h"
/**
  *f_rotl- rotates the stack to the top
  *@head: stack head
  *@counter: line_number
 */
void f_rotl(stack_t **head, unsigned int counter)
{
	stack_t *tmp = *head, *aux;
	(void)counter;

	if (tmp && tmp->next)
	{
		aux = (*head)->next;
		aux->prev = NULL;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = *head;
		(*head)->next = NULL;
		(*head)->prev = tmp;
		(*head) = aux;
	}
}
