SHELL := /bin/sh
CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra
EXEC = main
OBJS = character.o main.o
CFILE = character.c main.c

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -o $(EXEC) $(OBJS)

$(OBJS): $(CFILE)
	$(CC) $(CFLAGS) -c $(CFILE)

clean:
	rm -f $(EXEC) $(OBJS)

format:
	clang-format -i -style=file *.[ch]
