#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

/*
 * How to execute another program in C using execvle().
 *
 * Important the path of the command. 
 */
int	main(int ac, char *av[], char *env[])
{
	char *ev[] = {"TEST=environment variable", NULL};

	(void)ac;
	(void)av;
	(void)env;
	execle("/sbin/ping", "/sbin/ping", "google.com", NULL, ev);
	return (0);
}
