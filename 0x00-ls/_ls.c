#include "hls.h"
/**
*show_dir - 0
*@file_names: node of arguments
*@op: array of options
*/
void display_diractory(list_t *file_names, int *op)
{
	list_t *head = file_names;
	int mult = 0;

	if (head == NULL)
	{
		show_local(".", op);
		return;
	}

	if (head->next)
		mult = 1;

	while (head != NULL)
	{
		show_op(head, op, mult);
		head = head->next;
	}
}
/**
*show_op - 0
*@head: node of arguments
*@op: array of options
*@mult: multiple file_names
*/
void display_option(list_t *head, int *op, int mult)
{
	DIR *dir;
	struct dirent *read;

	dir = opendir(head->str);


	if (mult == 1 && errno == 0)
		printf("%s :\n", head->str);
	if (dir != NULL)
	{
		read = readdir(dir);
		while (read != NULL)
		{
			if (op[1] == 1)
			{
				print_long_format(read);
				op[0] = 1;
			}
			else
			{
				condition_overload(read, op);
			}
			read = readdir(dir);
		}
		if (head->next != NULL || errno != 0)
			printf("\n");
	}

	if (errno != 0)
	{
		error_handler(head->str);
	}

	if (op[0] != 1 && errno == 0)
		printf("\n");

	closedir(dir);
}
/**
*show_local - 0
*@head: node of arguments
*@op: array of options
*/
void show_local(char *head, int *op)
{
	DIR *dir;
	struct dirent *read;

	dir = opendir(head);
	if (dir != NULL)
	{
		read = readdir(dir);
		while (read != NULL)
		{
			if (op[1] == 1)
			{
				print_long_format(read);
				op[0] = 1;
			}
			else
			{
				condition_overload(read, op);
			}
			read = readdir(dir);
		}
	}
	if (op[0] != 1)
		printf("\n");

	closedir(dir);
}
/**
*condition_overload - 0
*@read: argument
*@op: array of options
*/
void condition_overload(struct dirent *read, int *op)
{
	if (op[2] == 1)
		print_one_by_line(read->d_name, op);
	else
		if (op[3] == 1 && strcmp(read->d_name, ".") && strcmp(read->d_name, ".."))
			print_one_by_line(read->d_name, op);
		else
			if (read->d_name[0] != '.')
				print_one_by_line(read->d_name, op);
}
