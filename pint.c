#include "monty.h"
/**
 * f_pint - prints the top value
 * @Copy_Stack_Head: stack head
 * @Copy_U32_Counter: line number
*/
void f_pint(stack_t **Copy_Stack_Head, unsigned int Copy_U32_Counter)
{
	if (*Copy_Stack_Head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", Copy_U32_Counter);
		free(bus.content);
		free_stack(*Copy_Stack_Head);
		fclose(bus.file);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*Copy_Stack_Head)->n);
}
