# Declaring the variables.

CC=g++

CFLAGS=-c

SFMLINCLUDES=-Lsfml-hpp/ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

ARCHIVESdotO=Main.o Jogo.o Instrucoes.o Menu.o recordes.o Pecas.o

# Now executing the makefile.

all: executavel

executavel: $(ARCHIVESdotO)
	$(CC) $(ARCHIVESdotO) -o executavel $(SFMLINCLUDES)

Main.o: Main.cpp
	$(CC) $(CFLAGS) Main.cpp $(SFMLINCLUDES)

Jogo.o: Jogo.cpp
	$(CC) $(CFLAGS) Jogo.cpp $(SFMLINCLUDES)

Menu.o: Menu.cpp
	$(CC) $(CFLAGS) Menu.cpp $(SFMLINCLUDES)

recordes.o: recordes.cpp
	$(CC) $(CFLAGS) recordes.cpp $(SFMLINCLUDES)

Pecas.o: Pecas.cpp
	$(CC) $(CFLAGS) Pecas.cpp $(SFMLINCLUDES)

Instrucoes.o: Instrucoes.cpp
	$(CC) $(CFLAGS) Instrucoes.cpp $(SFMLINCLUDES)

clean:
	rm -rf *o executavel


