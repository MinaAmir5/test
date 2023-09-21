#include "monty.h"
/**
 * addnode - add node to the head stack
 * @head: head of the stack
 * @n: new_value
*/
void addnode(stack_t **head, int n)
{

	stack_t *new_node, *aux;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	aux = *head;
	if (aux)
		aux->prev = new_node;
	new_node->prev = NULL;
	new_node->n = n;
	new_node->next = *head;
	*head = new_node;
}
