CC=gcc -g -Wall -Wextra
CFILES=$(wildcard src/*/*.c)
HFILES=$(wildcard src/*/include/*.h)
OBJFILES=$(CFILES:.c=.o)
OBJPATH=src/objects/
EXEFILE=bin/main

all:$(OBJFILES)
	$(CC) $(OBJFILES) -o $(EXEFILE) -lm

%.o: %.c $(HFILES)%.h
	$(CC) -c $(CFILES) $< -o $@ -lm

vim:
	nvim $(CFILES) 

vimh:
	nvim $(HFILES) 

run:
	$(EXEFILE)

debug:
	gdb -q $(EXEFILE)

memcheck:
	valgrind $(EXEFILE) --leak-check=full --read-var-info

feh:
	feh docs/uml.png&

plant:
	plantuml docs/uml.txt
	convert docs/uml.png -channel RGB -negate docs/uml.png

git-update:
	git add Makefile README.md src/ docs/ bin/

clean:
	rm $(OBJFILES)
	rm $(EXEFILE)
