#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/**
 * main - open IPV4 socket and
 * listen on port 12345
 * accept an entering connection,
 * print the IP address of the connected client,
 * and close the connection right after.
 * Return: 0 on success, -1 on error
 */
int main(void)
{
	int sockfd, new_fd;
	struct sockaddr_in my_addr, their_addr;
	socklen_t sin_size;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
	{
		perror("socket");
		exit(EXIT_FAILURE);
	}

	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(12345);
	my_addr.sin_addr.s_addr = INADDR_ANY;
	memset(&(my_addr.sin_zero), '\0', 8);
	if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof(my_addr)) == -1)
	{
		perror("bind");
		close(sockfd);
		exit(EXIT_FAILURE);
	}
	if (listen(sockfd, 10) == -1)
	{
		perror("listen");
		close(sockfd);
		exit(EXIT_FAILURE);
	}
	printf("Server listening on port 12345\n");
	sin_size = sizeof(their_addr);
	new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
	if (new_fd == -1)
	{
		perror("accept");
		close(sockfd);
		exit(EXIT_FAILURE);
	}
	printf("Client connected: %s\n", inet_ntoa(their_addr.sin_addr));
	close(new_fd);
	close(sockfd);
	return (0);
}
