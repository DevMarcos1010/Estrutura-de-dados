CC     = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

programa: main.o ponto.o
	$(CC) $(CFLAGS) -o programa main.o ponto.o -lm

main.o: main.c ponto.h
	$(CC) $(CFLAGS) -c main.c

ponto.o: ponto.c ponto.h
	$(CC) $(CFLAGS) -c ponto.c

clean:
	rm -f *.o programa
