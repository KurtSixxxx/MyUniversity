CC=gcc
CFLAGS=-Wall -std=c17 -g
DEBUGGER?=gdb

all: createFolders bin/MatriceNormalizzata

createFolders:
	mkdir -p bin obj

bin/MatriceNormalizzata: obj/MatriceNormalizzata.o
	$(CC) $(CFLAGS) $< -o $@

obj/MatriceNormalizzata.o: src/MatriceNormalizzata.c
	$(CC) $(CFLAGS) -c $< -o $@

rebuild: clean all

run: bin/MatriceNormalizzata
	bin/MatriceNormalizzata $(ARGS)

debug: bin/MatriceNormalizzata
	$(DEBUGGER) bin/MatriceNormalizzata

clean:
	rm -rf bin obj output.txt
