#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * execute_command - Execute a command in the shell
 *
 * @command: The command to execute
 *
 * Return: Always returns 0
 */
int execute_command(char *command)
{
	pid_t pid;
	int status;
	char **argv;

	pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		exit(1);
	}
	else if (pid == 0)
	{
		/* Child process */
		argv = malloc(2 * sizeof(char *));
		if (argv == NULL)
		{
			perror("Memory allocation failed");
			exit(1);
		}

		argv[0] = command;
		argv[1] = NULL;

		if (execvp(argv[0], argv) == -1)
		{
			perror("Command execution failed");
			exit(1);
		}
	}
	else
	{
		/* Parent process */
		wait(&status);
	}

	return 0;
}

/**
 * main - Entry point of the shell program
 *
 * Return: Always returns 0
 */
int main(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t characters_read;

	while (1)
	{
		printf("#josieShell$ ");
		characters_read = getline(&line, &bufsize, stdin);

		if (characters_read == -1)
		{
			printf("\n");
			break;
		 }

		line[characters_read - 1] = '\0'; /* Remove the newline character */

		if (strcmp(line, "exit") == 0)
			break;

		execute_command(line);
	}

	free(line);
	return 0;
}
