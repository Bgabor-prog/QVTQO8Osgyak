#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


main(int argc, char **argv)
{
	int pid;

	if (argc < 1)
	{
		perror(" Nincs kinek");
		exit(1);
	}

	pid = atoi(argv[1]);

	kill(pid, SIGALRM);
}
