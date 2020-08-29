CC=g++ # compilador, troque para gcc se preferir utilizar C
CFLAGS=-Wall -g #-Wextra # compiler flags, troque o que quiser, exceto bibliotecas externas
EXEC=./tp1.exe # nome do executavel que sera gerado, nao troque
TMPOUT=tp1.testresult
BUILD=./build/
SRC=./src/
INCLUDE=./include/
JOGO=Jogo/

$(EXEC):	$(BUILD)main.o $(BUILD)$(JOGO)Jogo.o 
	$(CC) $(CFLAGS) -o $(EXEC) $(BUILD)main.o $(BUILD)$(JOGO)*.o 

$(BUILD)main.o:	$(SRC)main.cpp $(INCLUDE)$(JOGO)Jogo.hpp  
	$(CC) $(CFLAGS) -I $(INCLUDE)$(JOGO) -c $(SRC)main.cpp -o $(BUILD)main.o

$(BUILD)$(JOGO)Jogo.o: $(SRC)$(JOGO)Jogo.cpp $(INCLUDE)$(JOGO)Jogo.hpp 
	$(CC) $(CFLAGS) -I $(INCLUDE)$(JOGO) -c $(SRC)$(JOGO)Jogo.cpp -o $(BUILD)$(JOGO)Jogo.o


test:	$(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)