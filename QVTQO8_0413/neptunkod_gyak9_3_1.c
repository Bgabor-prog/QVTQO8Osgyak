#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <signal.h>

void Alarm(int sig);

int main(void)
{
    if (signal(SIGALRM, Alarm) == SIG_ERR)
    {
        printf("Nem sikerult handlert allitani a jelre!\n");
        return 1;
    }

    pause();
    return 0;
}

void Alarm(int sig)
{
    printf("QVTQO8\n Kibillentem!\n");
    exit(1);
}
