#include "monty.h"
/**
 * f_pchar - prints the char at the top of the stack
 * @Copy_Stack_Head: stack head
 * @Copy_U32_Counter: line number
*/
void f_pchar(stack_t **Copy_Stack_Head, unsigned int Copy_U32_Counter)
{
	stack_t *Local_Stack_Queue;

	Local_Stack_Queue = *Copy_Stack_Head;
	if (!Local_Stack_Queue)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", Copy_U32_Counter);
		free_stack(*Copy_Stack_Head);
		free(bus.content);
		fclose(bus.file);
		exit(EXIT_FAILURE);
	}
	else if (Local_Stack_Queue->n > 127 || Local_Stack_Queue->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", Copy_U32_Counter);
		free_stack(*Copy_Stack_Head);
		free(bus.content);
		fclose(bus.file);
		exit(EXIT_FAILURE);
	}
	else
		printf("%c\n", Local_Stack_Queue->n);
}
