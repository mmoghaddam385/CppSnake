COMPILER=g++
CARGS=-std=c++14
RELEASE_PREFIX=Release/
EXE=Release/snake.exe
MAIN=CppSnake.cpp
CONSOLE=Console/Console.cpp Console/Win32Console.cpp
GAME=Game/SnakeGame.cpp Game/SnakeEngine.cpp Game/Snake.cpp
MENU=UI/Menu.cpp UI/MenuButton.cpp UI/MenuSpinner.cpp UI/MultiItemMenuSpinner.cpp
UTIL=Util/Vec.cpp

batch-compile = $(foreach src_file, $(1), $(COMPILER) $(CARGS) -c $(src_file) -o Release/$(src_file:.cpp=.o); ) 	

link:
	$(COMPILER) $(CARGS:.cpp=.o) $(MAIN:%.cpp=Release/%.o) $(CONSOLE:%.cpp=Release/%.o) $(GAME:%.cpp=Release/%.o) $(MENU:%.cpp=Release/%.o) $(UTIL:%.cpp=Release/%.o) -o $(EXE)

build-all: main console game menu util link

main:
	$(call batch-compile, $(MAIN))

console:
	@mkdir -p Release/Console
	$(call batch-compile, $(CONSOLE))

game:
	@mkdir -p Release/Game
	$(call batch-compile, $(GAME))

menu:
	@mkdir -p Release/UI
	$(call batch-compile, $(MENU))

util:
	@mkdir -p Release/Util
	$(call batch-compile, $(UTIL))

run:
	./$(EXE)

build-all-run: build-all run

all: build-all

clean:
	@echo -n "Deleting executable..."
	@rm -f $(EXE)
	@echo "done"
