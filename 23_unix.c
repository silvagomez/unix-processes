#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

/*
 * How to execute another program in C using execvp().
 */
int	main(int ac, char *av[])
{
	char *arr[] = {"ping", "google.com", NULL};

	(void)ac;
	(void)av;
	execvp("ping", arr);
	return (0);
}
