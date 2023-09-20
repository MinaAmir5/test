#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
* main - main monty code
* @Copy_U32_ArgNo: number of arguments
* @Copy_U32_Env: current environemnt
* Return: 0 if success
*/
int main(int Copy_U32_ArgNo, char *Copy_U32_Env[])
{
	unsigned int Local_U32_Counter = 0;
	FILE *Local_File;
	stack_t *stack = NULL;
	char *content;
	size_t size = 0;
	ssize_t read_line = 1;

	if (Copy_U32_ArgNo != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	Local_File = fopen(Copy_U32_Env[1], "r");
	bus.file = Local_File;
	if (!Local_File)
	{
		fprintf(stderr, "Error: Can't open file %s\n", Copy_U32_Env[1]);
		exit(EXIT_FAILURE);
	}
	content = NULL;
	read_line = getline(&content, &size, Local_File);
	bus.content = content;
	Local_U32_Counter++;
	for (Local_U32_Counter = 1; read_line > 0; Local_U32_Counter++)
	{
		execute(content, &stack, Local_U32_Counter, Local_File);
		free(content);
		content = NULL;
		read_line = getline(&content, &size, Local_File);
		bus.content = content;
	}
	free(content);
	free_stack(stack);
	fclose(Local_File);
return (0);
}
