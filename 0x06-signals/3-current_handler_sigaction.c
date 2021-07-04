#include "signals.h"

/**
 * current_handler_sigaction - retrieve the handler of the signal SIGINT
 *
 * Return: pointer to the current handler of SIGINT, or NULL on failure
 */

void (*current_handler_sigaction(void))(int)
{
	struct sigaction prev;

	if (sigaction(SIGINT, NULL, &prev) < 0)
		return (NULL);

	return (prev.sa_handler);
}
