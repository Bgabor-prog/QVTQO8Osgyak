#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



void do_nothing();


main ()
{


	signal(SIGALRM, do_nothing);
	printf("  %d varok de meddig?\n");

	pause();

    	printf("  Vegre, itt az alarm \n");
}
void do_nothing(){}
