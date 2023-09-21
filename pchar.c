#include "monty.h"
/**
 * f_pchar - prints the char at the top of the stack
 * @head: stack head
 * @counter: line_number
*/
void f_pchar(stack_t **head, unsigned int counter)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		free_stack(*head);
		free(bus.content);
		fclose(bus.file);
		exit(EXIT_FAILURE);
	}
	else if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		free_stack(*head);
		free(bus.content);
		fclose(bus.file);
		exit(EXIT_FAILURE);
	}
	else
		printf("%c\n", h->n);
}
