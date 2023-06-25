#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
extern char **environ;
/**
*_env - function that prints the current working environment
*Return: 0
**/
int _env(void)
{
char **env = environ;
while (*env != NULL)
{
printf("%s\n", *env);
env++;
}
return (0);
}
/**
*_getenv - provides value of environment variable
*@info: structure that maintains constant functions
*@name: provides the name of environment variable
*Return: the value of the environment variable or NULL
**/
char *_getenv(const char *name)
{
char **env = environ;
while (*env != NULL)
{
char *env_var = *env;
char *var_value = strtok(NULL, "=");
char *var_name = strtok(env_var, "=");
if (strcmp(var_name, name) == 0)
{
return (var_value);
}
env++;
}
return (NULL);
}
/**
*setenv_builtin - the function that sets a value of an env
*var or create a new one
*@args: contains arguments
*Return: 0
**/
int setenv_builtin(char **args)
{
if (args[1] == NULL || args[2] == NULL)
{
fprintf(stderr, "setenv VARIABLE VALUE\n");
return (1);
}
if (setenv(args[1], args[2], 1) == -1)
{
fprintf(stderr, "unable to set envir var\n");
return (1);
}
return (0);
}
/**
*unsetenv_builtin - a function that removes and env var
*@args: arguments
*Return: 0 on success
**/
int unsetenv_builtin(char **args)
{
if (args[1] == NULL)
{
fprintf(stderr, "unsetenv VARIABLE\n");
return (1);
}
if (unsetenv(args[1]) == -1)
{
fprintf(stderr, "programs fail to unset env  var\n");
return (1);
}
return (0);
}
