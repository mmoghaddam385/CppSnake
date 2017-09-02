COMPILER=g++
CARGS=-std=c++11
EXE=Release/snake.exe
MAIN=CppSnake.cpp
CONSOLE=Console/Console.cpp Console/Win32Console.cpp
GAME=Game/SnakeGame.cpp

build:
	$(COMPILER) $(CARGS) $(MAIN) $(CONSOLE) $(GAME) -o $(EXE)
	
run:
	./$(EXE)

build-run: build run

all: build

clean:
	@echo -n "Deleting executable..."
	@rm -f $(EXE)
	@echo "done"