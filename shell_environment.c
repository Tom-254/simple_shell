#include "shell.h"

/**
 * _setenv - make the shell environment from the environment passed to main
 * @env: environment passed to main
 * @args: arguments passed to the shell
 *
 * Return: pointer to the new environment
 */
char **_setenv(char ***env, char **args)
{
	char **newenv = NULL;
    char *newvariable = NULL;
	int i;
    char *temp_env = *env;

    if (!(args[1] && args[2]))
        return (*env);

    newvariable = strcat_dynamic(args[1], "=", args[2]);

	for (i = 0; temp_env[i] != NULL; i++)
		;

    printf("faulted %d\n", i);
	newenv = malloc(sizeof(char *) * (i + 1));
	if (newenv == NULL)
	{
		perror("Fatal Error");
		exit(1);
	}
	for (i = 0; temp_env[i] != NULL; i++)
		newenv[i] = _strdup(temp_env[i]);
    newenv[i] = newvariable;
	newenv[i + 1] = NULL;
    free(env);
	return (newenv);
}


/**
 * unsetenv - make the shell environment from the environment passed to main
 * @env: environment passed to main
 *
 * Return: pointer to the new environment
 */
char **_unsetenv(char **env)
{
	char **newenv = NULL;
	size_t i;

	for (i = 0; env[i] != NULL; i++)
		;
	newenv = malloc(sizeof(char *) * (i + 1));
	if (newenv == NULL)
	{
		perror("Fatal Error");
		exit(1);
	}
	for (i = 0; env[i] != NULL; i++)
		newenv[i] = _strdup(env[i]);
	newenv[i] = NULL;
	return (newenv);
}