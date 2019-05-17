CC = gcc
SRC = src/
FNOSP = -fno-stack-protector

all: af ff o1 o1n so wf
af: $(SRC)af.c
	$(CC) -o $@ $< 
ff: $(SRC)ff.c
	$(CC) -o $@ $<
o1: $(SRC)o1.c
	$(CC) -o $@ $<
o1n: $(SRC)o1n.c
	$(CC) -o $@ $<
so: $(SRC)so.c
	$(CC) -o $@ $< $(FNOSP)
wf: $(SRC)wf.c
	$(CC) -o $@ $<
