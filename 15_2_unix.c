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
 */
int	main(int ac, char *ag[])
{
	int arr[5];
	int	i;
	int	fd;
	int	sum;

	(void)ac;
	(void)ag;
	fd = open("15_fifo", O_RDONLY);
	if (fd == -1)
		return (1);
	for (i = 0; i < 5; i++)
	{
		if (read(fd, &arr[i], sizeof(int)) == -1)
			return (2);
		printf("Recieved %d\n", arr[i]);
	}
	close(fd);
	sum = 0;
	for (i = 0; i < 5; i++)
		sum +=arr[i];
	printf("Sum of random numbers is: %d\n", sum);
	return (0);
}
