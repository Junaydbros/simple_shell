#include "clish.h"

/**
 * get_dir - a function that fetches the current working directory for the
 * prompt
 * @form: the state of the cwd
 *
 * Return: a void type
 */
void get_dir(char *form)
{
	char cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		if (strcmp(form, "loop") == 0)
		{
			printf("[	%s	]\n", cwd);
		}
		else if (strcmp(form, "pwd") == 0)
		{
			printf("%s\n", cwd);
		}
	}
	else
	{
		printf("Error processing getcwd()\n");
	}
}

/**
 * ctrl_handle - the function handles the Ctrl-C such that the clish terminal
 * is not exited until prompted by the user with the exit command
 *
 * Return: a void type
 */

void ctrl_handle()
{
	signal(SIGINT, ctrl_handle);
	getchar();
}

int cli_handler(char **args)
{
	char *line, *token, *argv, *csh;
	int a = 0;

	argv = line;

	cmd = csh_strtok(line, "\n\t\r ");

	args[a] = csh;

	do {
		a++;
		token = csh_strtok(NULL, "\n\t\r");
		argv = token;
		args[a] = token;
	} while (argv != NULL)
	args[a] = NULL;

	return (a);
}
