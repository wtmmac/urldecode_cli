LIBS = ""

CC = gcc

CFLAGS = -std=c99  -Wall

TARGETS = $(patsubst %.c, %, $(wildcard *.c))

SOURCES = $(wildcard *.c)

all: $(TARGETS)

%: %.c
		$(CC) $< $(CFLAGS) $(LIBS) -o $@


clean:
		-rm -f $(TARGETS)

install:
		cp ./urldecode /usr/bin/
