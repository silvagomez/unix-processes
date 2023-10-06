#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

/*
 * Handling signal.
 *
 * For test the handle fucntion stop the process "ctrl + z" while execution.
 */
void	handle_sigcont(int sig)
{
	printf("Input number: ");
	fflush(stdout);
}
int	main(int ac, char *av[])
{
	struct sigaction	sa;
	int					x;

	(void)ac;
	(void)av;
	sa.sa_handler = &handle_sigcont;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGCONT, &sa, NULL);
	printf("Input number: ");
	scanf("%d", &x);
	printf("Result %d * 5 = %d\n", x, x * 5);
	return (0);
}
