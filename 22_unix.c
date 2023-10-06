#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

/*
 * How to execute another program in C using execlp().
 */
int	main(int ac, char *av[])
{
	(void)ac;
	(void)av;
	execlp("ping", "ping", "google.com", NULL);
	return (0);
}
