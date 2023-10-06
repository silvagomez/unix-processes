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
	struct sigaction	sa;
	int					x;

	(void)ac;
	(void)av;
	// Pointer to a fucntion
	sa.sa_handler = &handle_sigtstp;
	/*
	 * This flag is for this special case os SIGSTP and scanf, due to the behave
	 * behind scence.
	 */
	sa.sa_flags = SA_RESTART;
	/*
	 * Hook SIG action.
	 * sigaction() def: get ant/or set the action for signal SIG.
	 */
	sigaction(SIGTSTP, &sa, NULL);
	printf("Input number: ");
	scanf("%d", &x);
	printf("Result %d * 5 = %d\n", x, x * 5);
	return (0);
}
