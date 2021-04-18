#include "hls.h"
/**
*_strcmp - 0
*@s1: string
*@s2: string
*Return: int
*/
int _strcmp(char const *s1, char *s2)
{
	int j = 0, i = 0;

	while (s1[i] != '\0')
	{
		i++;
	}

	while (s1[j] == s2[j] && j < i)
	{
		j++;
	}

	return (s1[j] - s2[j]);
}
/**
*_strcpy - 0
*@src: src
*@dest: dest
*Return: dest
*/
char *_strcpy(char *dest, char const *src)
{
	int i = 0, j;

	while (src[i] != '\0')
	{
		i++;
	}

	j = 0;
	while (j <= i)
	{
		dest[j] = src[j];
		j++;
	}
	return (dest);
}
/**
*_strlen - 0
*@s: char
*Return:: i
*/
int _strlen(char const *s)
{
	int i = 0;

	if (s != NULL)
	{
		while (*s != '\0')
		{
			s++;
			i++;
		}
	}

	return (i);
}
/**
*_strncpy - 0
*@dest: string
*@src: string
*@n: int
*Return: dest
*/
char *_strncpy(char *dest, char const *src, int n)
{
	int i = 0;

	for (i = 0; i < n && src[i] != '\0'; ++i)
	{
		dest[i] = src[i];
	}

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
