#include "signals.h"

/**
 * sig_handler - action to take on SIGINT delivery
 * @signal: signal value to print
 */
void sig_handler(int signal)
{
	printf("Gotcha! [%i]\n", signal);
	fflush(stdout);
}
/**
 * handle_sigaction - set handler for SIGINT
 *
 * Return: 1 on success or -1 on error
 */
int handle_sigaction(void)
{
	struct sigaction sig_action;

	sig_action.sa_handler = sig_handler;
	sig_action.sa_flags = 0;

	if (sigaction(SIGINT, &sig_action, NULL) < 0)
		return (-1);
	return (0);
}
