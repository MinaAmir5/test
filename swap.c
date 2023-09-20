#include "monty.h"
/**
 * f_swap - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
*/
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int aux;

	h = *head;
	if (h && h->next)
	{
		h = *head;
		aux = h->n;
		h->n = h->next->n;
		h->next->n = aux;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
}
