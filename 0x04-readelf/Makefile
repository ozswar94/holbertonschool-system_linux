CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 -g 
SRC := $(wildcard *.c)
RM = rm -rf 
OBJ = $(SRC:%.c=%.o)

0-hreadelf: $(OBJ)
	$(CC) -D hreadelf_0 $(CFLAGS) $(OBJ) -o 0-hreadelf

1-hreadelf: $(OBJ)
	$(CC) -D hreadelf_1 $(CFLAGS) $(OBJ) -o 1-hreadelf

clean:
	$(RM) 0-hreadelf

oclean:
	$(RM) $(OBJ)

fclean: clean oclean

re: fclean 0-hreadelf

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<
