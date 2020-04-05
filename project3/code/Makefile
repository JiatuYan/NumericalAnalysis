SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))

Plot1 : Plot1.o function1.o NewtonFormula.o
	g++ -o $@ $^

Plot2 : Plot2.o function2.o NewtonFormula.o
	g++ -o $@ $^

%.o : %.cpp
	g++ -c $< 

clean :
	rm *.o *.exe *.txt html latex -fr Plot1 Plot1
