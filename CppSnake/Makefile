COMPILER=g++
CARGS=-std=c++11
EXE=Release/snake.exe
MAIN=CppSnake.cpp
CONSOLE=Console/console.cpp Console/win32-console.cpp

all:
	$(COMPILER) $(CARGS) $(MAIN) $(CONSOLE) -o $(EXE)
	
run: all
	./$(EXE)

clean:
	@echo -n "Deleting executable..."
	@rm -f $(EXE)
	@echo "done"