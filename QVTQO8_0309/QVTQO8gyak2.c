#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main(void){

char command[100];
    printf("Enter a Unix command(date,pwd,who):");
    scanf("%s", command);

        system(command);

return 0;
}
