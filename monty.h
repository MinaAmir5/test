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
 * @Global_U8_Par: value
 * @Global_File: pointer to monty file
 * @Global_U8_Value: line content
 * @Global_U32_Queue: flag change stack <-> queue
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
void Void_Sub(stack_t **, unsigned int);
void Void_Mod(stack_t **, unsigned int);
void Void_AddStack(stack_t **, int);
void Void_Push(stack_t **, unsigned int);
void Void_FreeStack(stack_t *);
void Void_Pall(stack_t **, unsigned int);
void Void_Pint(stack_t **, unsigned int);
void Void_Execute(char *, stack_t **, unsigned int, FILE *);
void Void_Pop(stack_t **, unsigned int);
void Void_Swap(stack_t **, unsigned int);
void Void_Add(stack_t **, unsigned int);
void Void_Nop(stack_t **, unsigned int);
void Void_Div(stack_t **, unsigned int);
void Void_Mul(stack_t **, unsigned int);
void Void_Pchar(stack_t **, unsigned int);
void Void_Pstr(stack_t **, unsigned int);
void Void_Rotl(stack_t **, unsigned int);
void Void_Rotr(stack_t **, unsigned int);
void Void_AddQueue(stack_t **, int);
void Void_Stack(stack_t **, unsigned int);
void Void_Queue(stack_t **, unsigned int);
#endif
