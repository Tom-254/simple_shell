#include "shell.h"

/**
 * _strlen - returns the length of a string
 *
 * @s: the string whose length to return
 *
 * Return: the length of the string
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}

/**
 * _strcmp - compares two strings
 *
 * @s1: one of the strings to compare
 * @s2: the other string to compare
 *
 * Return: difference in length
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (s1[i] - s2[i]);
		i++;
	}

	return (s1[i] - s2[i]);
}

/**
 * _strdup -  returns a pointer to a
 * newly allocated space
 * in memory, which contains a copy of the
 * string given as a parameter.
 * @str: string to copy
 * Return: character pointer
 */

char *_strdup(char *str)
{
	char *c;
	int count = 0, i;

	if (str == NULL)
		return (NULL);

	while (str[count] != '\0')
	{
		count++;
	}

	count++;

	c = malloc(sizeof(char) * (count + 1));

	if (c == NULL)
		return (NULL);

	for (i = 0; i <= count; i++)
	{
		c[i] = str[i];
	}

	return (c);

}

/**
 * _strcpy - copies a string including the null to a buffer
 *
 * @dest: buffer
 * @src: Points to string
 *
 * Return: pointer to @dest
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * strcat_dynamic - creates the path variable for the command
 *
 * @dest: the path directory to be joined
 * @path_sep: the path separator
 * @src: the command to be joined with
 * Return: the complete path string
 */

char *strcat_dynamic(char *dest, char *path_sep, char *src)
{
	int len1; /* string length for src */
	int len2; /* string length for dest */
	int len3;
	int i;

	char *create_dest;

	len1 = 0;
	len2 = 0;
	len3 = 0;

	len1 = _strlen(src);
	len2 = _strlen(dest);
	len3 = _strlen(path_sep);

	create_dest = malloc(sizeof(char) * (len1 + len2 + len3 + 1));

	if (create_dest == NULL)
		return (NULL);

	for (i = 0; i < len2; i++)
	{
		create_dest[i] = dest[i];
	}

	for (i = 0; i < len3; i++)
	{
		create_dest[len2++] = path_sep[i];
	}

	for (i = 0; i < len1; i++)
	{
		create_dest[len2++] = src[i];
	}

	create_dest[len2] = '\0';
	return (create_dest);
}
