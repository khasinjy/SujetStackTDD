EXEC=MyStackTest.out

all: clean compile test

compile: MyStack.o MyStackTest.o 
	g++ -o $(EXEC) build/*.o -lgtest -lpthread

MyStackTest.o: MyStackTest.cpp
	g++ -o build/MyStackTest.o -c MyStackTest.cpp

MyStack.o: MyStack.cpp
	g++ -o build/MyStack.o -c MyStack.cpp

test:
	./$(EXEC)

clean:
	rm -rf build/*
	rm -rf tests/*
	rm ./$(EXEC)