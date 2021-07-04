#include "signals.h"

/**
 * sig_handler - action to take on SIGINT delivery
 * @signal: signal value to print
 */
void sig_handler(int signal)
{
	printf("Caught %d\n", signal);
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
	sigaction(SIGINT, &sig_act, NULL);
	pause();
	puts("Signal received");
	return (EXIT_SUCCESS);
}
