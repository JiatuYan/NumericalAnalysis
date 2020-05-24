SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))

Plot : Plot.cpp
	g++ -o $@ $^

clean :
	rm *.txt Plot
