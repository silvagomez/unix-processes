#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <signal.h>

/*
 * Stopping and continuing the execution of a process using SIGCONT and SIGSTOP
 *
 * Now send the signal to the child process to continue.
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
		kill(pid, SIGSTOP);
		sleep(1);
		kill(pid, SIGCONT);
		sleep(1);
		kill(pid, SIGKILL);
		wait(NULL);
	}
	return (0);
}
