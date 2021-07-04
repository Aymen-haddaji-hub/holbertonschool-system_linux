#include "signals.h"

/**
 * sig_handler - print the sender's PID
 * @sig: sig number
 * @info: pointer to info about signal
 * @ptr: signal information
 */
static void sig_handler(int sig, siginfo_t *info, void *ptr)
{
	(void) sig;
	(void) ptr;
	if (info)
	{
		printf("SIGQUIT sent by %d\n", info->si_pid);
		fflush(stdout);
	}
}

/**
 * trace_signal_sender - modifies SIGQUIT's handler
 *
 * Return: 1 on success or -1 on error
 */
int trace_signal_sender(void)
{
	struct sigaction signal_action;

	signal_action.sa_sigaction = sig_handler;
	signal_action.sa_flags = SA_SIGINFO;

	if (sigaction(SIGQUIT, &signal_action, NULL) < 0)
		return (-1);
	return (0);
}
