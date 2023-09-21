#include "monty.h"
/**
 * Void_Pint - prints the top value
 * @Copy_Stack_Head: stack head
 * @Copy_U32_Counter: line number
*/
void Void_Pint(stack_t **Copy_Stack_Head, unsigned int Copy_U32_Counter)
{
	if (*Copy_Stack_Head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", Copy_U32_Counter);
		free(Global_Par.Global_U8_Value);
		Void_FreeStack(*Copy_Stack_Head);
		fclose(Global_Par.Global_File);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*Copy_Stack_Head)->n);
}
