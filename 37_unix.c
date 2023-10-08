#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

/*
 * How to send a string through a pipe.
 *
 */
int	main(int ac, char *av[])
{
	int pid;
	int	fd[2];

	(void)ac;
	(void)av;
	if (pipe(fd) == -1)
	{
		return (1);
	}
	pid = fork();
	if (pid < 0)
		return (2);
	if (pid == 0)
	{
		char str[200];
		int	 n;

		close(fd[0]);
		printf("Input string: ");
		fgets(str, 200, stdin);
		str[strlen(str) - 1] = '\0';
		n = strlen(str) + 1;
		/*
		 * We need to pass the number of number of character, but we cant pass
		 * strlen(str) + 1, so we can solve passing the reference
		 */
		if (write(fd[1],  &n, sizeof(int)) < 0)
			return (3);
		if (write(fd[1], str, sizeof(char) * (strlen(str) + 1)) < 0)
			return (3);
		close(fd[1]);
	}
	else
	{
		char str[200];
		int  n;

		close(fd[1]);
		if (read(fd[0], &n, sizeof(int)) < 0)
			return (4);
		if (read(fd[0], str, sizeof(char) * n) < 0)
			return (4);
		printf("Recieved: %s\n", str);
		close(fd[0]);
		wait(NULL);
	}
	return (0);
}

