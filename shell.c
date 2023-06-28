#include "main.h"

/**
 * displayShell - A function that displays the shell prompt
 *
 */

void displayShell(void)
{
	printf("shell> ");
	fflush(stdout);
}


/**
 * main - A function that returns our version of a simple shell
 * Return: Hopefully a well working shell
 */

int main(void)
{
	pid_t child_pid;
	int status;
	char *command = NULL;
	size_t n = 0;
	char *argv[] = {"/bin/sh", "-c", NULL, NULL};

	while (1)
	{
		displayShell();
	if (getline(&command, &n, stdin) == -1)
	{
		perror("Error: ");
		break;
	}
	command[strcspn(command, "\n")] = '\0';
	if (strcmp(command, "exit") == 0)
	{
		printf("You are leaving the shell...Sad to see you go...\n");
		break;
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error: ");
		exit(1);
	}
	if (child_pid == 0)
	{
		argv[2] = command;
		execve("/bin/sh", argv, NULL);
		perror("Error: ");
		exit(1);
	}
	else
	{
		wait(&status);
	}
	}
	free(command);
	return (0);
}
