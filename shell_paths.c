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

/**
 * _isalpha - Check if Alphabtic
 *@c: Character
 * Return: 1 If True 0 If Not
 */
int _isalpha(int c)
{
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
		return (1);
	else
		return (0);
}


/**
 * _atoi - convert to a int
 * @s:string
 * Return:int
 */
int _atoi(char *s)
{
	int i, j, n, x;

	i = n = 0;
	x = 1;
	while ((s[i] < '0' || s[i] > '9') && (s[i] != '\0'))
	{
		if (s[i] == '-')
			x *= -1;
		i++;
	}
	j = i;
	while ((s[j] >= '0') && (s[j] <= '9'))
	{
		n = (n * 10) + x * ((s[j]) - '0');
		j++;
	}
	return (n);
}
