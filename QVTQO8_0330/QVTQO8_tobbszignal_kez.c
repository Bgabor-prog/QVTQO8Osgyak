#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void Interrupt(int sig);
void Quit(int sig);

int sum = 0;

int main(void)
{
    if (signal(SIGINT, Interrupt) == SIG_ERR)
    {
        printf("Nem sikerult handlert allitani a SIGINT jelre!\n");
        return 0;
    }

    if (signal(SIGQUIT, Quit) == SIG_ERR)
    {
        printf("Nem sikerult handlert allitani a SIGQUIT jelre\n");
        return 0;
    }

    while(sum < 2)
    {
        printf("Varakozas\n");
        sleep(1);
    }

    printf("Masodik SIGINT jel a program befejezodott!");
    return 0;
}

void Interrupt(int sig)
{
    printf("SIGINT jel: %d\n", sig);
    sum++;
}

void Quit(int sig)
{
    printf("SIGQUIT jel: %d\n", sig);
}
