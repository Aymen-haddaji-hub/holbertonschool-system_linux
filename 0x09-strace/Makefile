
C= gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu99 -g

SRC0 = 0-strace.c
OBJ0 = $(SRC0:.c=.o)
NAME0 = strace_0

SRC1 = 1-strace.c
OBJ1 = $(SRC1:.c=.o)
NAME1 = strace_1

SRC2 = 2-strace.c
OBJ2 = $(SRC2:.c=.o)
NAME2 = strace_2

SRC3 = 3-strace.c
OBJ3 = $(SRC3:.c=.o)
NAME3 = strace_3

SRC4 = 4-strace.c
OBJ4 = $(SRC4:.c=.o)
NAME4 = strace_4

SRC5 = 5-strace.c
OBJ5 = $(SRC5:.c=.o)
NAME5 = strace_5

strace_0: strace.h $(OBJ0)
	$(CC) $(OBJ0) -o $(NAME0)

strace_1: strace.h $(OBJ1) $(OBJ5)
	$(CC) $(OBJ1) -o $(NAME1)

strace_2: strace.h $(OBJ2)
	$(CC) $(OBJ2) -o $(NAME2)

strace_3: strace.h $(OBJ3)
	$(CC) $(OBJ3) -o $(NAME3)

strace_4: strace.h $(OBJ4)
	$(CC) $(OBJ4) -o $(NAME4)

strace_5: strace.h $(OBJ5)
	$(CC) $(OBJ5) -o $(NAME5)

