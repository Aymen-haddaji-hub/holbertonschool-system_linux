#include "hls.h"
/**
 * _ls - function that list files and diractories and take args from user.
 * @dir: pointer to directory.
 * @op_a: implementation of -a argument.
 * @op_1: list the contents in a single line.
 * Return :void.
 **/
void _ls(const char *dir, int op_a, int op_1)
{
	/*Here we will list the directory*/
	struct dirent *d;
	DIR *dh = opendir(dir);

	if (!dh)
	{
		if (errno == ENOENT)
		{
			/*If the directory is not found*/
			perror("No such file or directory");
		}
		else
		{
			/*If the directory is not readable then throw error and exit*/
			perror("Unable to read directory");
		}
		exit(EXIT_FAILURE);
	}
	/*While the next entry is not readable we will print directory files*/
	while ((d = readdir(dh)) != NULL)
	{
		/*If hidden files are found we continue*/
		if (!op_a && d->d_name[0] == '.')
			continue;
		printf("%s  ", d->d_name);
		if (op_1)
		printf("\n");
	}
	if (!op_1)
	printf("\n");
}
/**
 * main - entry point
 * @argc: the size of the argument vector
 * @argv: the argument vector
 *
 * Return: 0 on success, non-zero otherwise
 */
int main(int argc, const char *argv[])
{
	if (argc == 1)
	{
		_ls(".", 0, 0);
	}
	else if (argc == 2)
	{
		if (argv[1][0] == '-')
		{
			/*Checking if option is passed*/
			/*Options supporting: a, l*/
			int op_a = 0, op_1 = 0;
			char *p = (char *)(argv[1] + 1);

			while (*p)
			{
				if (*p == 'a')
				op_a = 1;
				else if (*p == '1')
				op_1 = 1;
				else
				{
					perror("Option not available");
					exit(EXIT_FAILURE);
				}
				p++;
			}
			_ls(".", op_a, op_1);
		}
	}
	return (0);
}
