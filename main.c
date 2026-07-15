#include "file_creator/file_creator.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int result;
  result = create_file("teste", DIRECTORY, 0000700);
  if (result) {
    return result;
  }
  result = create_file("teste/control", FIFO, 0000600);
  if (result) {
    return result;
  }
  result = create_file("teste/ok", FIFO, 0000600);
  if (result) {
    return result;
  }
  result = create_file("teste/lock", NORMAL, 0000600);
  if (result) {
    return result;
  }
  result = create_file("teste/pid", NORMAL, 0000644);
  if (result) {
    return result;
  }
  result = create_file("teste/stat", NORMAL, 0000644);
  if (result) {
    return result;
  }
  result = create_file("teste/status", NORMAL, 0000644);
  if (result) {
    return result;
  }
  return 0;
}
