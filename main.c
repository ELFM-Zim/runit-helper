#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    printf("%s\n", argv[0]);

    int fd = 0;

    if(mkdir("teste", 0100700) == -1){goto erro;}
    if(mkfifo("teste/control", 0000600) == -1){goto erro;}
    if(mkfifo("teste/ok", 0000600) == -1){goto erro;}

    printf("%i\n", fd);
    fd = open("teste/lock", O_CREAT | O_RDONLY, 0006000);
    if(fd == -1) {goto erro;}
    close(fd);

    printf("%i\n", fd);
    fd = open("teste/pid",    O_CREAT | O_RDONLY, 0000600);
    if(fd == -1){goto erro;}
    close(fd);


    printf("%i\n", fd);
    fd = open("teste/stat",   O_CREAT | O_RDONLY, 0000600); 
    if(fd == -1){goto erro;}
    close(fd);

    printf("%i\n", fd);
    fd = open("teste/status", O_CREAT | O_RDONLY, 0000600);
    if(fd == -1){goto erro;}
    close(fd);

    

    printf("%i\n", fd);

    return 0;

    erro:
        int erro = errno;
        
        printf("%s\n", strerror(erro));

        return erro;
}
