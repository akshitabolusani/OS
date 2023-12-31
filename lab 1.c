#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{


    if (argc != 3)
    {
        printf("Insufficient Arguments\n");
        exit(1);
    }


    if ((sfd = open(argv[1], O_RDONLY)) == -1)
    {
        printf("File not found\n");
        exit(1);
    }


    close(sfd);

    exit(0);
}
