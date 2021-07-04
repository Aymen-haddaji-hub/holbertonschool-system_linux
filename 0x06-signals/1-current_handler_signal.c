#include "signals.h"

/**
 * current_handler_signal - task 1.
 * Return: pointer to SIGINT hander, NULL on failure.
 **/

void (*current_handler_signal(void))(int)
{
	void (*handler)(int);

	handler = signal(SIGINT, SIG_DFL);

	if (signal(SIGINT, handler) == SIG_ERR || handler == SIG_ERR)
		return (NULL);
	return (handler);
}
