#include "strace.h"

/**
* main - use ptrace for getting the syscall name
* @argc: number of arguments
* @av: list of arguments
* @en: list of environ variables
* Return: 0 on success, 1 otherwise
*/
int main(int argc, char **argv, char **en)
{
	pid_t child = 0;
	int status = 0;
	struct user_regs_struct registers;

	if (argc < 2)
	{
		printf("./strace_0 command [args...]\n");
		return (1);
	}
	setbuf(stdout, NULL);
	child = fork();
	if (child == 0)
	{
		ptrace(PTRACE_TRACEME, child, NULL, NULL);
		raise(SIGSTOP);
		execve(argv[1], &(argv[1]), en);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			return (0);
		ptrace(PTRACE_SYSCALL, child, NULL, NULL);
		while (wait(&status) && !WIFEXITED(status))
		{
			memset(&registers, 0, sizeof(registers));
			ptrace(PTRACE_GETREGS, child, NULL, &registers);
			if (WSTOPSIG(status) == SIGTRAP && (long) registers.rax == -38)
				printf("%lu\n", (unsigned long) registers.orig_rax);
			ptrace(PTRACE_SYSCALL, child, NULL, NULL);
		}
	}
	return (0);
}