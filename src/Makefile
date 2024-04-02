EXE := exec/
CD := mkdir -p

CC := g++
CCOMPILE := -o
THREAD := -pthread
STDIO := -std=c++11
FILE := SSOOIIGLE
EXTENSION := .cpp
LK := ln
DL := rm
all: dir file

file:
	$(CC) $(FILE)$(EXTENSION) $(CCOMPILE) $(FILE) Busqueda$(EXTENSION) Manejador$(EXTENSION) $(THREAD) $(STDIO)
dir:
	$(CD) $(DIR) $(EXE)

open:
	nano $(FILE)$(EXTENSION)

solution1:
	./$(EXE)$(FILE) La-última-sirena.txt castillo 3

solution2:
	./$(EXE)$(FILE) ACTITUD-DE-VENDEDOR.txt actitud 13

solution3:
	./$(EXE)$(FILE) 21-LEYES-DEL-LIDERAZGO.txt liderazgo 50

clean:
	$(DL) $(EXE)$(FILE)
	$(DL)dir $(EXE)
