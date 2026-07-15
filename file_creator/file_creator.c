#include "file_creator.h"
#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
int create_file(char *path, enum FILE_TYPE type, mode_t permission) {
  int fd;
  switch (type) {
  case FIFO:
    if (mkfifo(path, permission)) {
      int erro = errno;
      perror("Error");
      return errno;
    }
    break;
  case DIRECTORY:
    if (mkdir(path, permission)) {
      int erro = errno;
      perror("Error");
      return errno;
    }
    break;
  case NORMAL:
    fd = open(path, O_CREAT | O_RDONLY, permission);
    if (fd == -1) {
      int erro = errno;
      perror("Error");
      return errno;
    }
    close(fd);
    break;
  }

  return 0;
}
