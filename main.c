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
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (Copy_U32_ArgNo != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(Copy_U32_Env[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", Copy_U32_Env[1]);
		exit(EXIT_FAILURE);
	}
	content = NULL;
	read_line = getline(&content, &size, file);
	bus.content = content;
	counter++;
	while (read_line > 0)
	{
		execute(content, &stack, counter, file);
		free(content);
		content = NULL;
		read_line = getline(&content, &size, file);
		bus.content = content;
		counter++;
	}
	free(content);
	free_stack(stack);
	fclose(file);
return (0);
}
