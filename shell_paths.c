#include "shell.h"

/**
 *  array_rev - Reverse Array
 * @arr:Array To Reverse
 * @len:Length Of Array
 * Return: Void(Reverse Array)
 */
void array_rev(char *arr, int len)
{
	int i;
	char tmp;

	for (i = 0; i < (len / 2); i++)
	{
		tmp = arr[i];
		arr[i] = arr[(len - 1) - i];
		arr[(len - 1) - i] = tmp;
	}
}

/**
 * _strstr -  locates a substring.
 * @haystack: where the substring is located
 * @needle: the substring to be located
 * Return: Returns a pointer to the beginning of
 * the located substring, or NULL if the substring is not found.
 */

char *_strstr(char *haystack, char *needle)
{
	int count = 0, i, j;

	while (needle[count] != '\0')
	{
		count++;
	}

	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (j = 0; needle[j] != '\0'; j++)
		{
			if (haystack[i + j] != needle[j])
			{
				break;
			}
		}

		if (j == count)
			return (haystack + i);
	}
	return (NULL);
}

/**
 * create_path - locates the path variable.
 * @envp: array of environment variables
 * Return: the string of paths
 */

char *create_path(char **envp)
{
	int i;

	for (i = 0; envp[i] != NULL; i++)
	{
		if (_strstr(envp[i], "PATH"))
		{
			return (envp[i]);
		}
	}

	return (NULL);
}
