default: build

build: simple-enigma.c
	gcc -g -Wall -std=c99 simple-enigma.c -o simple-enigma

clean:
	rm -fr simple-enigma simple-enigma.dSYM

.PHONY: clean default
