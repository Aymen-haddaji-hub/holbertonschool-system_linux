#include "hls.h"
/**
 * error_handler - handles errors for hls
 * @directory: directory to search in
 * Return: 2 for failure
 */
void error_handler(char *directory)
{
	char buf[8192];

	if (errno == ENOENT)
		sprintf(buf, "hls: cannot access %s", directory);
	else if (errno == EACCES)
		sprintf(buf, "hls: cannot open directory %s", directory);
	perror(buf);
}
