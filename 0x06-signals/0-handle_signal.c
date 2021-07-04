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
 * handle_signal - sets a handler for the signal SIGINT
 *
 * Return: 0 on success, -1 on error
 */
int handle_signal(void)
{
	return (signal(SIGINT, sig_handler) == SIG_ERR ? -1 : 0);
}
