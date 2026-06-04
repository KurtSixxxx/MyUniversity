
CC=gcc
CFLAGS=-Wall -std=c17 -g

all: createFolders bin/Cose

createFolders:
	mkdir -p bin obj

bin/Cose: obj/Cose.o
	$(CC) $(CFLAGS) $< -o $@

obj/Cose.o: src/Cose.c
	$(CC) $(CFLAGS) -c $< -o $@

run: bin/Cose
	bin/Cose $(ARGS)

debug: bin/Cose
	gdb bin/Cose

clean:
	rm -r bin obj