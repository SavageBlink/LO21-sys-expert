OBJS	= rules.o
SOURCE	= rules.c
HEADER	= bools.h rules.h
OUT	= a.out
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

rules.o: rules.c
	$(CC) $(FLAGS) rules.c 


clean:
	rm -f $(OBJS) $(OUT)

