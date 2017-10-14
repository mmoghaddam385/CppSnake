COMPILER=g++
CARGS=-std=c++14
EXE=Release/snake.exe
MAIN=CppSnake.cpp
CONSOLE=Console/Console.cpp Console/Win32Console.cpp
GAME=Game/SnakeGame.cpp Game/SnakeEngine.cpp
MENU=UI/Menu.cpp UI/MenuButton.cpp UI/MenuSpinner.cpp UI/MultiItemMenuSpinner.cpp

build:
	@mkdir -p ./Release/
	$(COMPILER) $(CARGS) $(MAIN) $(CONSOLE) $(GAME) $(MENU) -o $(EXE)
	
run:
	./$(EXE)

build-run: build run

all: build

clean:
	@echo -n "Deleting executable..."
	@rm -f $(EXE)
	@echo "done"
