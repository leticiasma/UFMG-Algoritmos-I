CC=g++
CFLAGS=-Wall -Wextra -std=c++11 -g
EXEC=./tp1

$(EXEC): ./build/main.o ./build/jogo.o
	$(CC) $(CFLAGS) -o $(EXEC) ./build/*.o

./build/main.o: ./src/main.cpp ./build/jogo.o
	$(CC) $(CFLAGS) -c ./src/main.cpp -o ./build/main.o

./build/jogo.o: ./src/jogo.cpp ./includes/jogo.hpp ./build/grafo.o ./build/jogador.o
	$(CC) $(CFLAGS) -c ./src/jogo.cpp -o ./build/jogo.o

./build/grafo.o: ./src/grafo.cpp ./includes/grafo.hpp
	$(CC) $(CFLAGS) -c ./src/grafo.cpp -o ./build/grafo.o

./build/jogador.o: ./src/jogador.cpp ./includes/jogador.hpp
	$(CC) $(CFLAGS) -c ./src/jogador.cpp -o ./build/jogador.o

.PHONY: clean

clean:
	rm -f *.o

mem:
	valgrind --leak-check=full --show-leak-kinds=all $(EXEC) /mnt/c/Users/User/Desktop/tp1/testcases/EX5