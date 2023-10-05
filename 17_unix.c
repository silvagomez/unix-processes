#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

/*
 * Two way communication bbetween processes using pipes in C.
 */
int	main(int ac, char *av[])
{
	int	p1[2];
	int	id;

	(void)ac;
	(void)av;
	if (pipe(p1) == -1)
		return (1);
	id = fork();
	if (id == -1)
		return (2);
	if (id == 0)
	{
		//Child process
		int	x;

		if (read(p1[0], &x, sizeof(x)) == -1)
			return (3);
		printf("Received %d\n", x);
		x *= 4;
		if (write(p1[1], &x, sizeof(x)) == -1)
			return (4);
		printf("Wrote %d\n", x);
	}
	else
	{
		//Parent process
		int y;

		srand(time(NULL));
		y = rand() % 10;
		if (write(p1[1], &y, sizeof(y)) == -1)
			return (5);
		printf("Wrote %d\n", y);
		if (read(p1[0], &y, sizeof(y)) == -1)
			return (6);
		printf("Result %d\n", y);
	}
	return (0);
}
