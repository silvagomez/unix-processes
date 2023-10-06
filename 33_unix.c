#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

/*
 * Handling signal.
 *
 * For test the handle fucntion stop the process "ctrl + z" while execution.
 */
void	handle_sigtstp(int sig)
{
	printf("Stop not allowed\n");
}

int	main(int ac, char *av[])
{
	// No need to create struct;
	int					x;

	(void)ac;
	(void)av;
	signal(SIGTSTP, &handle_sigtstp);
	printf("Input number: ");
	scanf("%d", &x);
	printf("Result %d * 5 = %d\n", x, x * 5);
	// For portability in UNIX use sigaction(), is better.
	return (0);
}
