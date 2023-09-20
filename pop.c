#include "monty.h"
/**
 * f_pop - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head != NULL)
	{
		h = *head;
		*head = h->next;
		free(h);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		free(bus.content);
		free_stack(*head);
		fclose(bus.file);
		exit(EXIT_FAILURE);
	}
}
