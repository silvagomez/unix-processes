#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

/*
 * Two way communication bbetween processes using pipes in C.
 *
 * You can not execute execlp in the parent process, the child process will be
 * a zombie.
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
		execlp("ping", "ping", "-c", "3", "google.com", NULL);
		printf("THIS SHOULD NOT PRINT ON THE TERMINAL!\n");
	}
	else
	{
		wait(NULL);
		printf("Success!\n");
	}
	return (0);
}
