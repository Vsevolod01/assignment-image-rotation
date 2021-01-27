CFLAGS=--std=c18 -Wall -pedantic -Isrc/ -ggdb -Wextra -Werror -DDEBUG
CC=gcc

all: image-rotation

file.o: file.c
	$(CC) -c $(CFLAGS) $< -o $@

header.o: bmp_header.c
	$(CC) -c $(CFLAGS) $< -o $@

image.o: image.c
	$(CC) -c $(CFLAGS) $< -o $@

proc.o: proc.c
	$(CC) -c $(CFLAGS) $< -o $@

util.o: util.c
	$(CC) -c $(CFLAGS) $< -o $@

main.o: main.c
	$(CC) -c $(CFLAGS) $< -o $@

image-rotation: main.o file.o header.o image.o proc.o util.o
	$(CC) -o image-rotation $^

clean:
	rm -f main.o file.o header.o image.o proc.o util.o image-rotation

