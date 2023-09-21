#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct Global_Struct_Par - parameters of stack
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: deines the parameters of the stack
 */
typedef struct Global_Struct_Par
{
	char *Global_U8_Par;
	FILE *Global_File;
	char *Global_U8_Value;
	int Global_U32_Queue;
}  Global_Struct_Par;
extern Global_Struct_Par Global_Par;
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
void Void_Sub(stack_t **head, unsigned int counter);
void Void_Mod(stack_t **head, unsigned int counter);
void Void_AddStack(stack_t **head, int n);
char  *clean_line(char *content);
void Void_Push(stack_t **head, unsigned int number);
void Void_FreeStack(stack_t *head);
void Void_Pall(stack_t **head, unsigned int number);
void Void_Pint(stack_t **head, unsigned int number);
void Void_Execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void Void_Pop(stack_t **head, unsigned int counter);
void Void_Swap(stack_t **head, unsigned int counter);
void Void_Add(stack_t **head, unsigned int counter);
void Void_Nop(stack_t **head, unsigned int counter);
void Void_Div(stack_t **head, unsigned int counter);
void Void_Mul(stack_t **head, unsigned int counter);
void Void_Pchar(stack_t **head, unsigned int counter);
void Void_Pstr(stack_t **head, unsigned int counter);
void Void_Rotl(stack_t **head, unsigned int counter);
void Void_Rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void Void_AddQueue(stack_t **head, int n);
void Void_Stack(stack_t **head, unsigned int counter);
void Void_Queue(stack_t **head, unsigned int counter);
#endif
