CPP = g++
CC  = gcc
AR  = ar -rc

CFLAGS = -g
INCS   = -I ../include

.cpp.o:
	$(CPP) $(CFLAGS) -o $@ $< $(INCS)

.c.o:
	$(CC) $(CFLAGS) -o $@ $< $(INCS)

targets = examples

all: $(targets)

clean:
	rm -f *.o $(targets)
