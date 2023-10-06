#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

/*
 * How to execute another program in C using execl().
 *
 * Important the path of the command. 
 */
int	main(int ac, char *av[])
{
	(void)ac;
	(void)av;
	execl("/sbin/ping", "/sbin/ping", "google.com", NULL);
	return (0);
}
