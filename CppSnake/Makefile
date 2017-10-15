COMPILER=g++
CARGS=-std=c++14
RELEASE_PREFIX=Release/
EXE=Release/snake.exe
MAIN=CppSnake.cpp
CONSOLE=Console/Console.cpp Console/Win32Console.cpp
GAME=Game/SnakeGame.cpp Game/SnakeEngine.cpp
MENU=UI/Menu.cpp UI/MenuButton.cpp UI/MenuSpinner.cpp UI/MultiItemMenuSpinner.cpp

batch-compile = $(foreach src_file, $(1), $(COMPILER) $(CARGS) -c $(src_file) -o Release/$(src_file:.cpp=.o); ) 	

link:
	$(COMPILER) $(CARGS:.cpp=.o) $(MAIN:%.cpp=Release/%.o) $(CONSOLE:%.cpp=Release/%.o) $(GAME:%.cpp=Release/%.o) $(MENU:%.cpp=Release/%.o) -o $(EXE)

build-all: build-main build-console build-game build-menu link

main:
	$(call batch-compile, $(MAIN))

console:
	$(call batch-compile, $(CONSOLE))

game:
	$(call batch-compile, $(GAME))

menu:
	$(call batch-compile, $(MENU))

run:
	./$(EXE)

build-all-run: build-all run

all: build-all

clean:
	@echo -n "Deleting executable..."
	@rm -f $(EXE)
	@echo "done"
