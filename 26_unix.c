#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <fcntl.h>

/*
 * Executing programs vs executing scripts in C.
 *
 * Permission has to be in octal, thats why 0777.
 * 
 * dup2();
 * File descriptor	File
 * 		0			STDIN
 * 		1			ping_result.txt
 * 		2			STDERR
 * 		3			ping_result.txt
 *
 * This program does not work because:
 * execlp() execute an executable not a command line.
 */
int	main(int ac, char *av[])
{
	int id;

	(void)ac;
	(void)av;
	id = fork();
	if (id == -1)
		return (1);
	if (id == 0)
	{
		int err;
		int	file = open("ping_result.txt", O_WRONLY | O_CREAT, 0777);
		if (file == -1)
			return (2);
		printf("The fd to ping_result: %d\n", file);
		dup2(file, STDOUT_FILENO); 
		err = execlp("ping", "ping", "-c", "3", "google.com", "|", "grep", "\"ttl\"", NULL);
		if (err == -1)
		{
			printf("Could not find program to execute!\n");
			return (2);
		}
	}
	else
	{
		int	wait_status;
		int status_code;

		wait(&wait_status);
		if (WIFEXITED(wait_status))
		{
			status_code = WEXITSTATUS(wait_status);
			if (status_code == 0)
				printf("Success!\n");
			else
				printf("Failure! status code:%d\n", status_code);
		}
	}
	return (0);
}
