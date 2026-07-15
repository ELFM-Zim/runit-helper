all: configurit
	./configurit

configurit: main.c file_creator/file_creator.c file_creator/file_creator.h
	gcc main.c file_creator/file_creator.c -o configurit





