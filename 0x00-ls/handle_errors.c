#include "hls.h"
/**
 * error_handler - handles errors for hls
 * @directory: directory to search in
 * Return: 2 for failure
 */
void error_handler(char *directory)
{

	if (errno == ENOENT)
		fprintf(stderr, "hls: cannot access %s", directory);
	else if (errno == EACCES)
		fprintf(stderr, "hls: cannot open directory %s", directory);
	perror("");
}
