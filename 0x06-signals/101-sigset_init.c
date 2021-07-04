#include "signals.h"

/**
 * sigset_init - function that initializes a sigset.
 * @set: a pointer to the signal set to initialize
 * @signals: array of int, each one being a signal number
 * Return: 0 on success, or -1 on error
 **/

int sigset_init(sigset_t *set, int *signals)
{
	int c;

	if (sigemptyset(set) == -1)
		return (-1);

	for (c = 0; signals[c]; c++)
	{
		if (sigaddset(set, signals[c]) == -1)
			return (-1);
	}
	return (0);
}
