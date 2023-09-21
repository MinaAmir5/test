#include "monty.h"
Global_Struct_Par Global_Par = {NULL, NULL, NULL, 0};
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
	stack_t *Local_Stack = NULL;
	char *Local_U8_Data;
	size_t Local_Size = 0;
	ssize_t Local_Ssize_Line = 1;

	if (Copy_U32_ArgNo != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	Local_File = fopen(Copy_U32_Env[1], "r");
	Global_Par.Global_File = Local_File;
	if (!Local_File)
	{
		fprintf(stderr, "Error: Can't open file %s\n", Copy_U32_Env[1]);
		exit(EXIT_FAILURE);
	}
	Local_U8_Data = NULL;
	Local_Ssize_Line = getline(&Local_U8_Data, &Local_Size, Local_File);
	Global_Par.Global_U8_Value = Local_U8_Data;
	for (Local_U32_Counter = 1; Local_Ssize_Line > 0; Local_U32_Counter++)
	{
		Void_Execute(Local_U8_Data, &Local_Stack, Local_U32_Counter, Local_File);
		free(Local_U8_Data);
		Local_U8_Data = NULL;
		Local_Ssize_Line = getline(&Local_U8_Data, &Local_Size, Local_File);
		Global_Par.Global_U8_Value = Local_U8_Data;
	}
	fclose(Local_File);
	free(Local_U8_Data);
	Void_FreeStack(Local_Stack);
return (0);
}
