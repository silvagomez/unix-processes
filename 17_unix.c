#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

/*
 * Two way communication bbetween processes using pipes in C.
 *
 * We can not have a pipe that both sends data and recieves data on the same
 * process.
 * We need two pipes in order to achieve this behavior.
 * Comments printf, for production.
 */
int	main(int ac, char *av[])
{
	int	p1[2]; // Child to parent.
	int p2[2]; // Parent to child.
	int	id;

	(void)ac;
	(void)av;
	if (pipe(p1) == -1)
		return (1);
	if (pipe(p2) == -1)
		return (1);
	id = fork();
	if (id == -1)
		return (2);
	if (id == 0)
	{
		//Child process
		int	x;

		close(p1[0]);
		close(p2[1]);
		if (read(p2[0], &x, sizeof(x)) == -1)
			return (3);
		printf("Received %d\n", x);
		x *= 4;
		if (write(p1[1], &x, sizeof(x)) == -1)
			return (4);
		printf("Wrote %d\n", x);
		close(p1[1]);
		close(p2[0]);
	}
	else
	{
		//Parent process
		int y;

		close(p1[1]);
		close(p2[0]);
		srand(time(NULL));
		y = rand() % 10;
		if (write(p2[1], &y, sizeof(y)) == -1)
			return (5);
		printf("Wrote: %d\n", y);
		if (read(p1[0], &y, sizeof(y)) == -1)
			return (6);
		printf("Result: %d\n", y);
		close(p1[0]);
		close(p2[1]);
		wait(NULL);
	}
	return (0);
}
