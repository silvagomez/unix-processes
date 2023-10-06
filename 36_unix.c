#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

/*
 * How to send an array through a pipe.
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
		return (2);
	}
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		int arr[10];
		int n, i;

		close(fd[0]);
		srand(time(NULL));
		n = rand() % 10 + 1;
		printf("Generated: ");
		for (i = 0; i < n; i++)
		{
			arr[i] = rand() % 11;
			printf("%d ", arr[i]);
		}
		printf("\n");
		if (write(fd[1], &n, sizeof(int)) < 0)
			return (3);
		printf("Send n = %d\n", n);
		if (write(fd[1], arr, sizeof(int) * n) < 0)
			return (3);
		close(fd[1]);
	}
	else
	{
		int arr[10];
		int n, i, sum;

		close(fd[1]);
		if (read(fd[0], &n, sizeof(int)) < 0)
			return (4);
		if (read(fd[0], arr, sizeof(int) * n) < 0)
			return (4);
		close(fd[0]);
		for (i = 0; i < n; i++)
			sum += arr[i];
		printf("Result is: %d\n", sum);
		wait(NULL);
	}
	return (0);
}

