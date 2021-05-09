#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


void TerminationHandler(int sig);

int main(void)
{
    if (signal(SIGTERM, TerminationHandler) == SIG_ERR)
    {
        printf("Nem sikerult handlert állítani a SIGTERM jelre!\n");
        return 0;
    }

    while(1)
    {
        printf("Varakozas\n");
        sleep(3);
    }

    return 0;
}

void TerminationHandler(int sig)
{
    signal(sig, SIG_IGN);
    printf("SIGTERM jel: %d\n", sig);
}
