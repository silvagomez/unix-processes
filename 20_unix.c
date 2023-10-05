
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

/*
 * Getting exit status code in C.
 *
 */
int	main(int ac, char *av[])
{
	int id;

	(void)ac;
	(void)av;
	id = fork();
	if (id == -1)
		return (1);
	if (id == 0)
	{
		int err;

		err = execlp("ping", "ping", "-c", "3", "google.con", NULL);
		if (err == -1)
		{
			printf("Could not find program to execute!\n");
			return (2);
		}
	}
	else
	{
		int	wait_status;
		int status_code;

		wait(&wait_status);
		if (WIFEXITED(wait_status))
		{
			status_code = WEXITSTATUS(wait_status);
			if (status_code == 0)
				printf("Success!\n");
			else
				printf("Failure! status code:%d\n", status_code);
		}
	}
	return (0);
}
