#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

/*
 * Two way communication bbetween processes using pipes in C.
 *
 * In this case printf will not execute, execlp end the program.
 */
int	main(int ac, char *av[])
{
	(void)ac;
	(void)av;
	execlp("ping", "ping", "-c", "3", "google.com", NULL);
	printf("Success!\n");
	return (0);
}
