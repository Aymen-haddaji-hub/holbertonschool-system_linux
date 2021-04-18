#include "hls.h"
/**
 * add_node - Add node at the beginning of a linkedlist.
 * @head: A pointer to the head of the linkedlist.
 * @str: The string to be added to the linkedlist.
 * Return:  NULL if fail .
 *         Otherwise - the address of the new element.
 */
list_t *add_node(list_t **head, const char *str)
{
	char *c;
	int i;
	list_t *new;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	c = strdup(str);
	if (c == NULL)
	{
		free(new);
		return (NULL);
	}

	for (i = 0; str[i];)
		i++;

	new->str = c;
	new->len = i;
	new->next = *head;

	*head = new;

	return (new);
}
/**
 * free_list - free linkedlist.
 * @head: A pointer to the first element of linkedlist.
 * return: no return (void).
 */
void free_list(list_t *head)
{
	list_t *p;

	while (head)
	{
		p = head->next;
		free(head->str);
		free(head);
		head = p;
	}
}
