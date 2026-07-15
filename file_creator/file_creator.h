#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <fcntl.h>

enum FILE_TYPE { FIFO, NORMAL, DIRECTORY };

struct file {
  char *path;
  enum FILE_TYPE type;
  mode_t permission;
};

int create_file(char *path, enum FILE_TYPE type, mode_t permission);
#endif
