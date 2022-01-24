#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
/**
 * main - a program that connects to a listening server.
 * Usage: 2-client <host> <port>
 * port is the port (unsigned short).
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, -1 on error.
 */
int main(int argc, char *argv[])
{
	char host[256];
	struct addrinfo hints, *res;
	int sockfd;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	if (gethostname(host, sizeof(host)) == -1)
		return (EXIT_FAILURE);

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	if (getaddrinfo(argv[1], argv[2], &hints, &res) != 0)
		return (EXIT_FAILURE);

	sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	if (sockfd == -1)
		return (EXIT_FAILURE);

	if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1)
		return (EXIT_FAILURE);

	printf("Connected to %s:%s\n", argv[1], argv[2]);
	freeaddrinfo(res);
	close(sockfd);
	return (EXIT_SUCCESS);
}
