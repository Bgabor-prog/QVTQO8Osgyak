#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main()
{
    int fd = open("QVTQO8.txt", O_RDWR);

    if(fd == -1){

        printf("Fajl megnyitasa sikertelen!\n", "QVTQO8.txt");
        exit(1);

    } else printf("Fajl megnyitasa sikerer!\n", "QVTQO8.txt");

    char fajlTart[100];
    int beolv = read(fd, fajlTart, sizeof(fajlTart));

        fajlTart[beolv] = '\0';
        printf("Fajl tartalma:\"%s\" Osszesen:\"%i\" byte.\n", fajlTart, beolv);

        lseek(fd, 0, SEEK_SET);
        printf("Mutato a fajl elejen\n");

    char szoveg[] = "A fajl szovege at lett irva";
    int beleir = write(fd, szoveg, sizeof(szoveg));

        printf("Fajl modositasra kerult. Osszesen: \"%i\" byte.\n", beleir);


    close(fd);

    return 0;
}

