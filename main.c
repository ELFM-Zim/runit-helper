#include "file_creator/file_creator.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
int create_runit_service_directory(char* path){
	
	char temp[sizeof(path) + 11];

	strcpy(temp, path);

  int result;

  if((result = create_file(temp, DIRECTORY, 0000700))){
		return result;
  }

  if((result = create_file(strcat(temp, "/control"), FIFO, 0000600))){
		return result;
  }

	strcpy(temp, path);
	printf("%s\n" ,strcat(path, "/ok"));
	strcpy(temp, path);
  if((result = create_file(strcat(temp, "/ok"), FIFO, 0000600))){
	return result;
  }

	strcpy(temp, path);
  if((result = create_file(strcat(temp, "/lock"), NORMAL, 0000600))){
		return result;
  }

	strcpy(temp, path);
  if((result = create_file(strcat(temp, "/pid"), NORMAL, 0000644))){
		return result;
  }

	strcpy(temp, path);
  if((result = create_file(strcat(temp, "/stat"), NORMAL, 0000644))){
		return result;
  }

	strcpy(temp, path);
  if((result = create_file(strcat(temp, "/status"), NORMAL, 0000644))){
		return result;
  }

  return 0;
}

int main(int argc, char *argv[]) {
	if(argc == 1){
		printf("usage: configurit [-p <path to directory>]");
		return -1;
  }

	int opt;

	while((opt = getopt(argc, argv, "p:")) != -1){
		switch(opt){
			case 'p':
				printf("Result :%i\n", create_runit_service_directory(optarg));
				break;
			case '?':
				printf("Invalid option\nusage: configurit [-p <path to directory>]");
		}
	}

	return 0;
}


