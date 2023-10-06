#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/* 
 * Background & Foreground porcesses.
 *
 * While running the program, you press ctrl + z it will send a signal to 
 * stop de process sending to the background. To bring back type "fg" in the 
 * terminali, the process (job) will continue the execution.
 * ctrl + c send the signal to terminate.
 */
int	main(int ac, char *av[])
{
	int	x;

	(void)ac;
	(void)av;
	printf("Input number: ");
	scanf("%d", &x);
	printf("Result %d * 5 = %d\n", x, x * 5);
	return (0);
}
