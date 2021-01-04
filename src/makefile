OBJS	= main.o knowledgeBase.o rules.o engine.o interface.o
SOURCE	= main.c knowledgeBase.c rules.c engine.c interface.c
HEADER	= bool.h knowledgeBase.h rules.h engine.h interface.h
OUT	= a.out
CC	 = gcc
FLAGS	 = -g -c -Wall -fpic -pedantic -Werror
LFLAGS	 = -Wall -fpic -pedantic -ANSI -Werror 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.c
	$(CC) $(FLAGS) main.c 

knowledgeBase.o: knowledgeBase.c
	$(CC) $(FLAGS) knowledgeBase.c 

rules.o: rules.c
	$(CC) $(FLAGS) rules.c 
engine.o: engine.c
	$(CC) $(FLAGS) engine.c
interface.o: interface.c
	$(CC) $(FLAGS) interface.c
clean:
	rm -f $(OBJS) $(OUT)
