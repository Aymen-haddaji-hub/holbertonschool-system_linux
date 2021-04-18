#include "hls.h"
/**
*main - entry point.
*@argc: argument count.
*@argv: arguments vector.
*Return: 0 on success, otherwise non-zéro
*/
int main(int argc, char const *argv[])
{
	int op[4] = {0, 0, 0, 0};
	list_t *file_names = NULL, *head = NULL;

	file_names = handle_args(argc, argv, op);
	head = file_names;

	display_diractory(head, op);

	free_list(head);
	return (0);
}
