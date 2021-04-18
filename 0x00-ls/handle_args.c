#include "hls.h"
/**
 * handle_args - get ls options
 * @argc: argument count
 * @argv: arguments
 * @op: table of options
 * Return: list object
 */
list_t *handle_args(int argc, char const *argv[], int *op)
{
	int i = 1, j = 1;
	list_t *file_names = NULL;

	while (i < argc)
	{
		if (argv[i][0] == '-' && _strlen(argv[i]) > 1)
		{
			j = 1;
			while (_strlen(argv[i]) > j)
			{
				switch (argv[i][j])
				{
				case '1':
					op[0] = 1;
					break;
				case 'l':
					op[1] = 1;
					break;
				case 'a':
					op[2] = 1;
					break;
				case 'A':
					op[3] = 1;
					break;
				default:
					break;
				}
				j++;
			}
		}
		else
		{
		   file_names = add_node(&file_names, argv[i]);
		}
		i++;
	}
	return (file_names);
}
