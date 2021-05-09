#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define CHAR "/tmp/QVTQO8"

int main(void)
{
    mkfifo(CHAR, 0666);
    int pid = fork();
    if (pid < 0)
        exit(2);

    int fileDesc;
    if (pid == 0)
    {
        fileDesc = open(CHAR, O_WRONLY);

        char Inputchar[] = "Bele irtam a pipe-ba";
        write(fileDesc, Inputchar, sizeof(Inputchar));
    } else if (pid > 0 )
    {
        fileDesc = open(CHAR, O_RDONLY);

        char charArr[128];
        read(fileDesc, charArr, sizeof(charArr));
        printf("%s\n", charArr);
        close(fileDesc);
    }

    return 0;
}
