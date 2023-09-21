#include "monty.h"
/**
 * f_queue - select LIFI
 * @Copy_Stack_Head: stack head
 * @Copy_U32_Counter: line number
*/
void f_queue(stack_t **Copy_Stack_Head, unsigned int Copy_U32_Counter)
{
	(void)Copy_Stack_Head;
	(void)Copy_U32_Counter;
	bus.lifi = 1;
}

/**
 * addqueue - add node to the tail stack
 * @n: new value
 * @head: head of the stack
*/
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		printf("Error\n");
	aux = *head;
	while ((*head) && aux->next)
		aux = aux->next;
	new_node->next = NULL;
	new_node->n = n;
	if (!aux)
	{
		new_node->prev = NULL;
		*head = new_node;
	}
	else
	{
		new_node->prev = aux;
		aux->next = new_node;
	}
}
