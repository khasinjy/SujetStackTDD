EXEC=MyStackTest.out
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

all: clean compile test

compile: $(OBJ)
	g++ -o $(EXEC) build/*.o -lgtest -lpthread

%.o : %.cpp
	g++ -o build/$@ -c $<

test:
	./$(EXEC)

clean:
	rm -rf build/*
	@if [  -f "./$(EXEC)" ]; then rm ./$(EXEC); fi;