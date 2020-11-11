# Declaring the variables.

CC=g++

CFLAGS=-c

SFMLINCLUDES=-Lsfml-hpp/ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

ARCHIVESdotO=src/main.o src/jogo.o src/instrucoes.o src/menu.o src/recordes.o src/pecas.o

# Now executing the makefile.

all: executavel

executavel: $(ARCHIVESdotO)
	$(CC) $(ARCHIVESdotO) -o executavel $(SFMLINCLUDES)

main.o: src/main.cpp
	$(CC) $(CFLAGS) src/main.cpp $(SFMLINCLUDES)

jogo.o: src/jogo.cpp
	$(CC) $(CFLAGS) src/jogo.cpp $(SFMLINCLUDES)

menu.o: src/menu.cpp
	$(CC) $(CFLAGS) src/menu.cpp $(SFMLINCLUDES)

recordes.o: src/recordes.cpp
	$(CC) $(CFLAGS) src/recordes.cpp $(SFMLINCLUDES)

pecas.o: src/pecas.cpp
	$(CC) $(CFLAGS) src/pecas.cpp $(SFMLINCLUDES)

instrucoes.o: src/instrucoes.cpp
	$(CC) $(CFLAGS) src/instrucoes.cpp $(SFMLINCLUDES)

clean:
	rm -rf *o executavel


