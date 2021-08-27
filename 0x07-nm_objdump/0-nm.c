#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - list symbols from object files
 * @argc: the count of args
 * @argv: the args
 * @env:  the environment
 * Return: 0 on succes 1 in failure.
 */
int main(int argc, char **argv, char **env)
{
	char *args[] = {"/usr/bin/nm", "-p", "", NULL};

	(void)argc;
	args[2] = argv[1];
	if (execve("/usr/bin/nm", args, env) == -1)
	{
		perror("execv");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
