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

    fd = mkdir("teste", 0100700);
    if(fd == -1)
    {
        goto erro;
    }

    close(fd);

    fd = mkfifo("teste/control",         0000600);
    if(fd == -1) {goto erro;}

    fd = mkfifo("teste/ok",              0000600);
    if(fd == -1) {goto erro;}

    fd = open("teste/lock", O_CLOEXEC | O_CREAT,   0000600);
    if(fd == -1) {goto erro;}

    fd = open("teste/pid", O_CLOEXEC | O_CREAT,    0000644);
    if(fd == -1) {goto erro;}
    
    fd = open("teste/stat", O_CLOEXEC | O_CREAT,   0000644);
    if(fd == -1) {goto erro;}

    fd = open("teste/status", O_CLOEXEC | O_CREAT, 0000644);
    if(fd == -1) {goto erro;}

    

    printf("%i\n", fd);

    return 0;

    erro:
        int erro = errno;
        
        printf("%s\n", strerror(erro));

        return erro;
}
