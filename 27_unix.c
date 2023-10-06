#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <signal.h>

/*
 * Short introduction to signals in C.
 *
 * To send the signal to another process use kill() function.
 * It doesn't kill the process, it just send a signal and then
 * the process that recieves that signal knows what to do with it, 
 * where is to terminate itself or positive solution or whatever else
 * it might to do.
 * First send the pid, then the signal.
 */
int	main(int ac, char *av[])
{
	int pid;

	(void)ac;
	(void)av;
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		while (1)
			printf("Child process\n");
		usleep(50000);
	}
	else
	{
		sleep(1);
		kill(pid, SIGKILL);
		wait(NULL);
		printf("Killed process\n");
	}
	return (0);
}
