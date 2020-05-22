CC=gcc
flags=-Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self

Full: main.o cartas.o interface.o
	$(CC) $(flags) -o Full main.o cartas.o interface.o

cartas.o: cartas.c cartas.h
	$(CC) $(flags) -o cartas.o cartas.c -c

interface.o: interface.c interface.h
	$(CC) $(flags) -o interface.o interface.c -c

main.o: main.c cartas.h interface.h
	$(CC) $(flags) -o main.o main.c -c

clean:
	rm -f Full *.o
