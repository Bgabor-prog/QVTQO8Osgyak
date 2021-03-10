#include <stdio.h>
#include <stdlib.h>

int main()
{
    int		status;

	if ( (status = system("hibas")) < 0)
		perror("system() error");

	if (WIFEXITED(status))
		printf("Hibas befejezodes, visszaadott ertek = %d\n", WEXITSTATUS(status));

	exit(0);
    return 0;
}
