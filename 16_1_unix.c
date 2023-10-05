#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>

/*
 * How to use FIFO files to communicae between process in C.
 *
 * To test this, create a fifo in the terminal.
 * Optimize of 15_1
 */
int	main(int ac, char *ag[])
{
	int arr[5];
	int	i;
	int	fd;

	(void)ac;
	(void)ag;
	srand(time(NULL));
	for (i = 0; i < 5; i++)
	{
		arr[i] = rand() % 100;
		printf("Generated %d\n", arr[i]);
	}
	fd = open("15_fifo", O_WRONLY);
	if (fd == -1)
		return (1);
	if (write(fd, arr, sizeof(int) * 5) == -1 )
		return (2);
	close(fd);
	return (0);
}
