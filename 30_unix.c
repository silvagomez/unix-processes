#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <signal.h>

/*
 * Stopping and continuing the execution of a process using SIGCONT and SIGSTOP
 */
int	main(int ac, char *av[])
{
	int pid;
	int	t;

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
		do 
		{
			printf("Time in seconds for execution: ");
			scanf("%d", &t);
			if (t > 0)
			{
				kill(pid, SIGCONT);
				sleep(1);
				kill(pid, SIGSTOP);
			}
		} while (t > 0);
		kill(pid, SIGKILL);
		wait(NULL);
	}
	return (0);
}
