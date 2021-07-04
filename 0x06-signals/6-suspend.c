#include "signals.h"

/**
 * sig_handler - action to take on SIGINT delivery
 * @signal: signal value to print
 */
void sig_handler(int signal)
{
	printf("Caught! [%i]\n", signal);
	fflush(stdout);
}

/**
 * main - entry point.
 *
 * Return: EXIT_SUCCESS, or EXIT_FAILURE
 */
int main(void)
{
	struct sigaction sig_act;

	sig_act.sa_handler = sig_handler;
	sig_act.sa_flags = 0;

	if (sigaction(SIGINT, &sig_act, NULL) < 0)
		return (EXIT_FAILURE);
	pause();
	puts("Signal received");
	return (EXIT_SUCCESS);
}
