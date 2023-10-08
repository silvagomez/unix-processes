#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

/*
 * Simulating the pipe "|" operator in C.
 */
int	main(int ac, char *av[])
{
	int pid_1, pid_2;
	int	fd[2];

	(void)ac;
	(void)av;
	if (pipe(fd) == -1)
	{
		return (1);
	}
	pid_1 = fork();
	if (pid_1 < 0)
		return (2);
	if (pid_1 == 0)
	{
		//Child process 1.
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("ping", "ping", "-c", "5", "google.com", NULL);
		//execlp() kill the child process, thus there is no else.
	}
	pid_2 = fork();
	if (pid_2 < 0)
		return (3);
	if (pid_2 == 0)
	{
		//Child process 2.
		//grep is waiting for read.
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("grep", "grep", "rtt", NULL);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid_1, NULL, 0);
	waitpid(pid_2, NULL, 0);
	return (0);
}
