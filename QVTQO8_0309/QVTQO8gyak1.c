#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    int		status;
    if (!system("dir"))
    {
        for (int i = 0; i < 5; i++)
        {
            printf("%i\n", i);
        }
    }

    system("repa");

    if (WIFEXITED(status))
		printf("Hibas befejezodes, visszaadott ertek = %d\n", WEXITSTATUS(status));

	exit(0);

    return 0;
}
