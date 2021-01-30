CC = g++
CFLAGS = -std=c++17 -Wpedantic -g

all:
	$(CC) $(CFLAGS) luolastori.cpp && ./a.out

clean:
	$(RM) gol
