CC=g++
CFLAGS=-Wall -Wextra -std=c++11 -g
EXEC=./tp2

$(EXEC): ./build/main.o ./build/jogoDosDiamantes.o
	$(CC) $(CFLAGS) -o $(EXEC) ./build/*.o

./build/main.o: ./src/main.cpp ./build/jogoDosDiamantes.o
	$(CC) $(CFLAGS) -c ./src/main.cpp -o ./build/main.o

./build/jogoDosDiamantes.o: ./src/jogoDosDiamantes.cpp ./includes/jogoDosDiamantes.hpp
	$(CC) $(CFLAGS) -c ./src/jogoDosDiamantes.cpp -o ./build/jogoDosDiamantes.o

.PHONY: clean

clean:
	rm -f *.o

mem:
	valgrind --leak-check=full --show-leak-kinds=all $(EXEC) /mnt/c/Users/User/Desktop/TP2/testcases/EX5