#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <signal.h>

/*
 * Stopping and continuing the execution of a process using SIGCONT and SIGSTOP
 *
 * The child is created, it tries to execute but then the parent process
 * comes in and sends the SIGSTOP command, it says okay you're going to
 * stop executing rigth here and it's not going to do anything, 
 * just going to stand here at the line of code that it was currently. 
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
		{
			printf("Child process\n");
			usleep(50000);
		}
	}
	else
	{
		kill(pid, SIGSTOP);
		sleep(1);
		kill(pid, SIGKILL);
		wait(NULL);
	}
	return (0);

}
